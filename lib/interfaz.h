#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/global.h"
using namespace std;
const int LargoBarra = 30;

void SetColor(int Background, int Text);   
void Encabezado();
void LoadingDeposito();
void LoadingTransf();
void LoadingRetiro();
void Salvapantalla();
bool EsNumero(string linea);
void Mensaje(int num);
void updateBar(int n, int x);

void updateBar(int n, int x){
    int num_char = (n * LargoBarra)/100;
    cout<<"\r[";
    
    for(int i=0; i<= LargoBarra; i++)
        printf((i<=num_char)?"#":" ");
    
    cout<<"]"<<"  "<<n<<"% Contando dinero" ; 
}

void LoadingSaldo(){
    int t=1;
    for(int i=0; i<= 100; i++){
        SetColor(BLACK,GREEN);
        updateBar(i,t);
        usleep(20000);
    }
}

void LoadingTransf(){
    int t=1;
    for(int i=0; i<= 100; i++){
        SetColor(BLACK,GREEN);
        updateBar(i,t);
        usleep(20000);
    }
}

void LoadingDeposito(){
    int t=2;
    for(int i=0; i<= 100; i++){
        SetColor(BLACK,GREEN);
        updateBar(i,t);
        usleep(20000);
    }
}

void LoadingRetiro(){
    int t=3;
    for(int i=0; i<= 100; i++){
        SetColor(BLACK,GREEN);
        updateBar(i,t);
        usleep(20000);
    }
}

void Encabezado(){
    system("cls");
    SetColor(BLACK,CYAN);
    cout<<"O-----------------------------------------------------O"<<endl;
    cout<<"O                                                     O"<<endl;
    cout<<"O                      POLICAJERO                     O"<<endl;
    cout<<"O                                                     O"<<endl;
    cout<<"O-----------------------------------------------------O"<<endl;
}

bool EsNumero(string linea)
{
    bool b=true;
    int longitud = linea.size();
    if (longitud==0)
        b=false;
    else if((longitud==1)&&(!isdigit(linea[0])))
        b=false;
    else
    {
        int i;
        if (linea[0]=='+'||linea[0]=='-')
            i=1;
        else
            i=0;

        while (i<longitud)
        {
            if (!isdigit(linea[i]))
            {
                b=false;
                break;
            }
            i++;
        }
    }
    return b;
}

void Mensaje(int num){
    switch (num){
        case 0: Encabezado();
            cout<<"O                        SALIENDO                     O"<<endl;
            cout<<"O-----------------------------------------------------O"<<endl;getch();break;
        case 1: Encabezado();
            cout<<"O                    RETIRAR DINERO                   O"<<endl;
            cout<<"O-----------------------------------------------------O"<<endl;break;
        case 2: Encabezado();
            cout<<"O                   DEPOSITAR DINERO                  O"<<endl;
            cout<<"O-----------------------------------------------------O"<<endl;break;
        case 3: Encabezado();
            cout<<"O                   TRANFERIR DINERO                  O"<<endl;
            cout<<"O-----------------------------------------------------O"<<endl;break;
        case 4: Encabezado();
            cout<<"O                    CONSULTAR SALDO                  O"<<endl;
            cout<<"O-----------------------------------------------------O"<<endl;break;
       
        default: break;
    }
}

void Salvapantalla(){
    int a;
    bool tecla=true;
    while (tecla){
        system("cls");
        SetColor(BLACK,BLUE);
        cout<<"O-----------------------------------------------------O"<<endl;//usleep(90000);
        cout<<"O                                                     O"<<endl;//usleep(90000);
        cout<<"O               BIENVENIDO A POLICAJERO               O"<<endl;//usleep(90000);
        cout<<"O                                                     O"<<endl;//usleep(90000);
        cout<<"O-----------------------------------------------------O"<<endl;/*usleep(90000);*/SetColor(BLACK,CYAN);
        cout<<"O-----------------------------------------------------O"<<endl;//usleep(90000);
        cout<<"O                TU CAJERO MAS SEGURO                 O"<<endl;//usleep(90000);
        cout<<"O-----------------------------------------------------O"<<endl;/*usleep(90000);*/SetColor(BLACK,WHITE);
        cout<<"O-----------------------------------------------------O"<<endl;//usleep(90000);
        cout<<"O                                                     O"<<endl;//usleep(90000);
        cout<<"O        PRESIONA CUALQUIER TECLA PARA CONTINUAR      O"<<endl;//usleep(90000);
        cout<<"O                                                     O"<<endl;//usleep(90000);
        cout<<"O-----------------------------------------------------O"<<endl;//usleep(90000);
        if (_kbhit()){
            a=getch();
            tecla=false;
        }
    }
    cin.clear();
    fflush(stdin);
}