#include <iostream>
#include "sculptor.h"
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;
    if(nx<=0)
    {
        nx = 0;
    }
    if(ny<=0)
    {
        ny = 0;
    }
    if(nz<=0)
    {
        nz = 0;
    }

    //Alocação dinâmica da memória para a matriz 3D
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nz*ny*nx];

    for(int i=1;i<nx;i++)
    {
        v[i] = v[i-1]+ny;
    }

    for(int i=1; i<(nx*ny);i++)
    {
        v[0][i]=v[0][i-1]+nz;
    }

}

Sculptor::~Sculptor()
{
    // Liberação da memória alocada;
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;  
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha)
{
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++)
        {
            for(int j=y0;j<y1;j++)
            {
                for(int k=z0;k<z1;k++)
                {
                    putVoxel(i,j,k);
                }
            }
        }
}


void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++)
        {
            for(int j=y0;j<y1;j++)
            {
                for(int k=z0;k<z1;k++)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++)
        {
            for(int j = ycenter-radius; j<=ycenter+radius; j++)
            {
                for(int k = zcenter-radius; k<=zcenter+radius; k++)
                {
                    if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2))
                    {
                        putVoxel(i,j,k);
                    }
                }
            }
        }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++)
        {
            for(int j = ycenter-radius; j<=ycenter+radius; j++)
            {
                for(int k = zcenter-radius; k<=zcenter+radius; k++)
                {
                    if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2))
                    {
                        cutVoxel(i,j,k);
                    }
                }
            }
        }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
        {
            for(int j = ycenter-ry; j<=ycenter+ry; j++)
            {
                for(int k = zcenter-rz; k<=zcenter+rz; k++)
                {
                        if(((pow((i-xcenter),2)/pow(rx,2))+(pow((j-ycenter),2)/pow(ry,2))+(pow((k-zcenter),2)/pow(rz,2)))<=1.0)
                        {
                            putVoxel(i,j,k);
                        }
                }
            }
        }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
        {
            for(int j = ycenter-ry; j<=ycenter+ry; j++)
            {
                for(int k = zcenter-rz; k<=zcenter+rz; k++)
                {
                        if(((pow((i-xcenter),2)/pow(rx,2))+(pow((j-ycenter),2)/pow(ry,2))+(pow((k-zcenter),2)/pow(rz,2)))<=1.0)
                        {
                            cutVoxel(i,j,k);
                        }
                }
            }
        }
}

void Sculptor::writeOFF(char *filename)
{

    int aux = 0;
    int Nface = 0;
    int Nvert = 0;

    ofstream arq;
    arq.open(filename);


    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn)
                {
                    Nvert = Nvert+8;
                    Nface = Nface+6;

                }
            }
        }
    }


    arq << "OFF" << endl; //Primeira linha do arquivo (obrigatória)
    arq << Nvert << " " << Nface << " " << 0 << endl;

    // Laço para atribuir os devidos valores dos vértices de cada voxel no arquivo
    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn)
                {
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }

    // Laço para atribuir o devido ordenamento das faces de cada voxel no arquivo;
    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn)
                {
                   arq << 4 << " " << aux+0 << " " << aux+3 << " " << aux+2 << " " << aux+1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                   arq << 4 << " " << aux+4 << " " << aux+5 << " " << aux+6 << " " << aux+7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                   arq << 4 << " " << aux+0 << " " << aux+1 << " " << aux+5 << " " << aux+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                   arq << 4 << " " << aux+0 << " " << aux+4 << " " << aux+7 << " " << aux+3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                   arq << 4 << " " << aux+3 << " " << aux+7 << " " << aux+6 << " " << aux+2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                   arq << 4 << " " << aux+1 << " " << aux+2 << " " << aux+6 << " " << aux+5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

                   aux = aux + 8;
                }
            }
        }
    }

    // Verifica se o arquivo é gerado. Quando não aparece mensagem alguma, provavelmente houve alguma falha na alocação;
    if(arq.is_open())
        {
            cout << "arquivo OFF salvo com sucesso ! "<<endl;
        }
    else
    {
        cout << "Erro ao salvar o arquivo" << endl;
    }

}
