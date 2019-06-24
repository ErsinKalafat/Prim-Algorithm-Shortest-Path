#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define SATIR 20
#define SUTUN 20
#define SONSUZ 5000

class plab2proje1
{
    int komsulukMatrisi[SATIR][SUTUN],dugumAdet;
public:
    plab2proje1();
    void grafOlustur();
    void primAlgoritmasi();
};

plab2proje1 :: plab2proje1()
{
    for(int i=0; i<SATIR; i++)
        for(int j=0; j<SUTUN; j++)
            komsulukMatrisi[i][j]=0;
}

void plab2proje1 :: grafOlustur()
{
    int i,j,yol;
    cout<<"Toplam Dugum Adedi : ";
    cin>>dugumAdet;
    cout<<"\nKomsuluk Matrisi : \n";
    for(i=0; i<dugumAdet; i++)               // graf oluşturuluyor.
        for(j=0; j<dugumAdet; j++)
            cin>>komsulukMatrisi[i][j];

    cout<<"\n\n";

    cout<<"\n\n KOMSULUK MATRISI : \n\n";

    for(i=0; i<dugumAdet; i++)               // komşuluk matrisi ekrana yazılıyor.
    {
        for(j=0; j<dugumAdet; j++)
        {
            cout<<komsulukMatrisi[i][j];

            if (komsulukMatrisi[i][j]<10)
                cout<<"   ";
            else
                cout<<"  ";
        }
        cout<<"\n\n";
    }

    cout<<"\n\n GRAF : \n\n";
    for(i=0; i<dugumAdet; i++)               // graf yazdırılıyor.
    {
        for(j=0; j<dugumAdet; j++)
        {
            if (i==j)
                continue;
            for(yol=0; yol<komsulukMatrisi[i][j]; yol++)
                cout<<"_";
            cout<<"  Dugum"<<i+1<<" --> Dugum"<<j+1<<"\n\n";
        }
        cout<<"\n\n";
    }


    for(j=0; j<dugumAdet; j++)
    {
        if(komsulukMatrisi[i][j]==0)
            komsulukMatrisi[i][j]=SONSUZ;
    }
}

void plab2proje1 :: primAlgoritmasi()
{
    int secili[SATIR],i,j,kenarNo;
    int min,x,y,toplam=0,yol;

    for(i=0; i<dugumAdet; i++)
        secili[i]=false;

    secili[0]=true;
    kenarNo=0;

    cout<<"\n\n EN KISA YOL : \n\n";

    while(kenarNo < dugumAdet-1)
    {
        min=SONSUZ;
        for(i=0; i<dugumAdet; i++)
        {
            if(secili[i]==true)
            {
                for(j=0; j<dugumAdet; j++)
                {
                    if(secili[j]==false)
                    {
                        if(min > komsulukMatrisi[i][j])
                        {
                            min=komsulukMatrisi[i][j];

                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        secili[y]=true;

        for(yol=0; yol<=min; yol++)
            cout<<"_";
        cout<<"  Dugum"<<x+1<<" --> Dugum"<<y+1<<"\n\n";

        toplam+=komsulukMatrisi[x][y];
        kenarNo++;
    }
    cout<<"\n\n TOPLAM MALIYET : "<<toplam;

    cout<<"\n\n";
}

int main()
{
    /*System("cls");
    int sur = DETECT, gmode;
    initgraph(&sur,&gmode,"");
    line(12,12,298,198);
    circle(200,100,75);
    arc(200,100,90,180,50);
    rectangle(10,10,300,200);
    ellipse(320,240,0,180,50,70);
    getch();
    closegraph();*/

    plab2proje1 EnKisaYolAgaci;
    cout<<"Ersin Kalafat - 130202117 \n";
    cout<<"PRIM ALGORITMASIYLA EN KISA YOL AGACI \n";
    cout<<"_____________________________________ \n\n";
    EnKisaYolAgaci.grafOlustur();
    EnKisaYolAgaci.primAlgoritmasi();

    return 0;
}
