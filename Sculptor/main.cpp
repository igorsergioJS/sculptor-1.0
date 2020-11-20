#include <iostream>
#include "sculptor.h"
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


int main(void)
{

    // Testa putVoxel e cutVoxel
    Sculptor cubo(10,10,10);
    cubo.setColor(0,0,0.1,1);
    cubo.putVoxel(0,0,0);
    cubo.setColor(1,1,1,1);
    cubo.putVoxel(1,0,0);
    cubo.setColor(0.86275,0.07843,0.23529,1);
    cubo.putVoxel(2,0,0);
    cubo.putVoxel(0,1,0);
    cubo.cutVoxel(0,1,0);
    cubo.writeOFF((char*)"cuboFinal.off");

    // Testa putBox e cutBox
    Sculptor trono(20,20,20);
    trono.setColor(0,1,0,1);
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF((char*)"tronoFinal.off");

    // Testa a transparência;
    Sculptor alpha(20,20,20);
    alpha.setColor(0,1,0,1);
    alpha.putBox(0,10,0,10,0,10);
    alpha.setColor(0,0,1,0.3);
    alpha.putBox(1,9,1,9,0,10);
    alpha.putBox(1,9,0,10,1,9);
    alpha.putBox(0,10,1,9,1,9);
    alpha.writeOFF((char*)"alphaBoxFinal.off");

    // Gera a espada de dimante do minecraft utilizando várias chamadas da putVoxel
    Sculptor sword(50,50,50);
    //Cabo
    sword.setColor(0.02353,0.16078,0.14510,1);
    sword.putVoxel(0,0,0);
    sword.putVoxel(1,0,0);
    sword.putVoxel(2,0,0);
    sword.putVoxel(0,1,0);
    sword.putVoxel(0,2,0);
    sword.putVoxel(1,2,0);
    sword.putVoxel(2,1,0);
    sword.setColor(0.12549,0.53725,0.47059,1);
    sword.putVoxel(1,1,0);
    sword.setColor(0.40784,0.30196,0.11765,1);
    sword.putVoxel(2,2,0);
    sword.putVoxel(4,4,0);
    sword.setColor(0.29020,0.20784,0.08627,1);
    sword.putVoxel(2,3,0);
    sword.putVoxel(3,4,0);
    sword.setColor(0.52941,0.40784,0.15294,1);
    sword.putVoxel(3,3,0);
    sword.setColor(0.14902,0.11373,0.04314,1);
    sword.putVoxel(3,2,0);
    sword.putVoxel(4,3,0);
    //Meio
    sword.setColor(0.12549,0.53725,0.47059,1);
    sword.putVoxel(5,5,0);
    sword.putVoxel(4,6,0);
    sword.putVoxel(4,7,0);
    sword.putVoxel(6,4,0);
    sword.putVoxel(7,4,0);
    sword.setColor(0.08235,0.38824,0.33333,1);
    sword.putVoxel(3,8,0);
    sword.putVoxel(8,3,0);
    sword.setColor(0.02745,0.14902,0.12549,1);
    sword.putVoxel(4,5,0);
    sword.putVoxel(5,4,0);
    sword.putVoxel(3,6,0);
    sword.putVoxel(6,3,0);
    sword.putVoxel(3,7,0);
    sword.putVoxel(7,3,0);
    sword.putVoxel(2,8,0);
    sword.putVoxel(2,9,0);
    sword.putVoxel(3,9,0);
    sword.putVoxel(8,2,0);
    sword.putVoxel(9,2,0);
    sword.putVoxel(9,3,0);
    sword.putVoxel(4,8,0);
    sword.putVoxel(5,7,0);
    sword.putVoxel(5,6,0);
    sword.putVoxel(8,4,0);
    sword.putVoxel(7,5,0);
    sword.putVoxel(6,5,0);
    //Lâmina
    sword.setColor(0.15686,0.78431,0.67843,1);
    sword.putVoxel(6,6,0);
    sword.putVoxel(7,7,0);
    sword.putVoxel(8,8,0);
    sword.putVoxel(9,9,0);
    sword.putVoxel(10,10,0);
    sword.putVoxel(11,11,0);
    sword.putVoxel(12,12,0);
    sword.putVoxel(13,13,0);
    sword.putVoxel(14,14,0);
    sword.setColor(0.20000,0.91765,0.79608,1);
    sword.putVoxel(6,7,0);
    sword.putVoxel(7,8,0);
    sword.putVoxel(8,9,0);
    sword.putVoxel(9,10,0);
    sword.putVoxel(10,11,0);
    sword.putVoxel(11,12,0);
    sword.putVoxel(12,13,0);
    sword.putVoxel(13,14,0);
    sword.putVoxel(7,6,0);
    sword.putVoxel(8,7,0);
    sword.putVoxel(9,8,0);
    sword.putVoxel(10,9,0);
    sword.putVoxel(11,10,0);
    sword.putVoxel(12,11,0);
    sword.putVoxel(13,12,0);
    sword.putVoxel(14,13,0);
    sword.setColor(0.05490,0.23922,0.20784,1);
    sword.putVoxel(6,8,0);
    sword.putVoxel(7,9,0);
    sword.putVoxel(8,10,0);
    sword.putVoxel(9,11,0);
    sword.putVoxel(10,12,0);
    sword.putVoxel(11,13,0);
    sword.putVoxel(12,14,0);
    sword.putVoxel(13,15,0);
    sword.putVoxel(8,6,0);
    sword.putVoxel(9,7,0);
    sword.putVoxel(10,8,0);
    sword.putVoxel(11,9,0);
    sword.putVoxel(12,10,0);
    sword.putVoxel(13,11,0);
    sword.putVoxel(14,12,0);
    sword.putVoxel(15,13,0);
    sword.putVoxel(15,14,0);
    sword.putVoxel(14,15,0);
    sword.putVoxel(15,15,0);
    sword.writeOFF((char*)"swordFinal.off");

    //Testa putSphere e cutBox
    Sculptor esfera(50,50,50);
    esfera.setColor(1,0,0,1);
    esfera.putSphere(8,8,8,8);
    esfera.cutBox(1,16,8,16,8,24); // Tira um quadrante da esfera(1,16)  um octante (1,8);
    esfera.writeOFF((char*)"esferaFinal.off");

    // Testa putSphere e cutSphere
    Sculptor cratera(100,100,100);
    cratera.setColor(0,1,1,1);
    cratera.putSphere(50,50,50,25);
    cratera.cutSphere(45,50,50,25);
    cratera.writeOFF((char*)"crateraFinal.off");


    // Testa putEllipsoid, cutEllipsoid e cutBox
    Sculptor elip(31,31,51);
    elip.setColor(0,1,0,1);
    elip.putEllipsoid(15,15,15,10,10,15);
    elip.setColor(1,0,0,1);
    elip.putEllipsoid(15,15,15,9,9,14);
    elip.cutEllipsoid(15,15,15,8,8,13);
    elip.cutBox(0,30,0,30,0,5);
    elip.writeOFF((char*)"elipFinal.off");


    // Gera uma pirâmide a partir de chamadas da função putBox(formando planos)
    Sculptor piramid(100,100,100);

    // 91 para G
    // 51 para M
    // 21 para P

    int j = 31;
    for(int i = 0; i < 31; i++)
    {
        if(i%2==0)
        {
          piramid.setColor(0.94118,0.90196,0.54902,1);
        }
        else
        {
          piramid.setColor(1,0.84314,0,1);
        }

        piramid.putBox(i,j,i,i+1,i,j);
        j--;
    }

    piramid.writeOFF((char*)"piramidFinal.off");


    // Gera uma melancia utilizando putEllipsoid e cutBox
    Sculptor melancia(61,61,81);
    //Casca
    melancia.setColor(0,1,0,1);
    melancia.putEllipsoid(30,30,30,20,20,30);
    //Interior
    melancia.setColor(1,0,0,1);
    melancia.putEllipsoid(30,30,30,19,19,29);
    melancia.cutBox(0,60,0,60,0,10);
    // Sementes
    melancia.setColor(0,0,0,1);

    double r1,r2;
    int a,b;
    a = 20;
    b = 40;
    for(int i = 0; i < 20; i++)
    {
       r1 = (double) rand()/RAND_MAX;
       r2 = (double) rand()/RAND_MAX;
       r1 = (int)(a + r1*(b - a));
       r2 = (int)(a + r2*(b - a));

       melancia.putVoxel(r1,r2,10);
    }

    melancia.writeOFF((char*)"melanciaFinal.off");


    //Gera uma maçã mordida utilizando putSphere, cutSphere e putVoxel
    Sculptor maca(100,100,100);
    maca.setColor(1,0,0,1);
    maca.putSphere(50,50,50,20);
    maca.setColor(0.83137,0.77647,0.66275,1);
    maca.putSphere(50,50,50,19);
    maca.cutEllipsoid(40,65,35,15,10,10);
    maca.setColor(0.20000,0.15294,0.14118,1);
    maca.putVoxel(50,70,50);
    maca.putVoxel(50,71,50);
    maca.putVoxel(50,72,50);
    maca.putVoxel(50,73,50);
    maca.putVoxel(50,74,50);
    maca.putVoxel(50,74,51);
    maca.putVoxel(50,74,52);
    maca.putVoxel(50,73,52);
    maca.putVoxel(50,72,53);

    maca.writeOFF((char*)"macaFinal.off");



}
