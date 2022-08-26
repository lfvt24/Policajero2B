#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector> 
#include <cstring> 
#include <stdlib.h>
#include <windows.h>
#include "../lib/estructuras.h"
#include "../lib/interfaz.h"

using namespace std;

int numeroDeTarjeta, numeroDeTarjeta2;

struct usuario verPersona;
struct usuario verPersona2;
vector<usuario> persona;
const string fileDir = "../datos/base.txt";

int getOp();
void loadInfo();
void saveInfo();
void showInfo();
bool existReg(int numero);
bool existReg2(int numero);
bool verificarPin(int pin);
void retDinero();
void depDinero();
void traDinero();
void conDinero();
void Out();
void del();
int getOp();
void ingresarDatos();

void loadInfo(){
	string nombre;
	fstream fBase(fileDir);
	
	cout<<endl<< "CARGANDO SISTEMA OK!"<<endl;
	if(!fBase)
		cout<< "Error al abrir el archivo" << fileDir << endl;
	
	while(fBase >> nombre){
		struct usuario usu;
		strcpy(usu.nombre, &nombre[0]);
		fBase>> usu.numTarjeta;
		fBase>> usu.pin;
		fBase>> usu.saldo;

		persona.push_back(usu);
	}
	fBase.close();
}

void saveInfo(){
    string usuarios;
    fstream fUsuarios;

	cout << "Salvando datos..."  << endl;
    fUsuarios.open(fileDir, ios_base::out);  // ios_base::in ios_base::app

    if ( !fUsuarios.is_open() )
    {
		cout << "Error al escribir el archivo: " << fileDir << endl;
        exit(EXIT_FAILURE);
    }

    for (auto &&usuarios : persona)
    {
        fUsuarios << usuarios.nombre << endl;
        fUsuarios << usuarios.numTarjeta << endl;     
        fUsuarios << usuarios.pin << endl;
        fUsuarios << usuarios.saldo<<endl;
    }
    
    fUsuarios.close();
}


int ingresarDatos(int num){
    int PIN, cont=1;
    cout<<"Ingrese su numero de tarjeta > ";	cin>> numeroDeTarjeta;
	if(existReg(numeroDeTarjeta)== true){
		cout<<endl<<"Ingrese su PIN > ";	cin>> PIN;
		while(verificarPin(PIN) == false && cont<3){
			system("cls");
            Mensaje(num);
			cout<<endl<<"Pin Incorrecto"<<endl;
			cout<<endl<<"Ingrese nuevamente su PIN > ";	cin>> PIN;
			cont++;
		}
		if(cont==3){
			system("cls");
			cout<<"Lo sentimos, has superado el limite de intentos"<<endl;
			cout<< "Gracias por utilizar el Policajero"<<endl;
			return 0;
            getch();
            
		}
    }else{
	    system("cls");
        Encabezado();
	    cout<<"Lo sentimos, no estas registrado para usar el Policajero"<<endl;
        return 0;
        getch();
    }
    return 1;
}

void showInfo(){
	cout<< "------"<<endl;
	for (auto &&usu :persona){
		cout<<"Nombre: "<< usu.nombre<< endl
			<<"Tarjeta: "<< usu.numTarjeta<<endl
			<<"Pin: "<< usu.pin<< endl
			<<"Saldo: $ "<< usu.saldo<< endl<< endl;
	}
	
}

void del(int a){
    int index=0;

    for (auto &&e : persona){
        if (e.numTarjeta==a){
            persona.erase(persona.begin()+index);
            break;
        }
        index++;
    }
}

void add2(){     
        persona.push_back(verPersona2);
}

void add(){     
        persona.push_back(verPersona);
}

bool existReg(int numero){
	
	bool ban=false;
	
	for (auto &&e : persona){
		if(e.numTarjeta == numero){
			strcpy(verPersona.nombre, &e.nombre[0]);
			verPersona.numTarjeta = e.numTarjeta;
			verPersona.pin = e.pin;
			verPersona.saldo = e.saldo;
			ban=true;
			continue;
		}
    }
	return ban;
}

bool existReg2(int numero){
	
	bool ban=false;
	
	for (auto &&e : persona)
		if(e.numTarjeta == numero){
			strcpy(verPersona2.nombre, &e.nombre[0]);
			verPersona2.numTarjeta = e.numTarjeta;
			verPersona2.pin = e.pin;
			verPersona2.saldo = e.saldo;
			ban=true;
			continue;
		}
	return ban;
}

bool verificarPin(int pin){
	bool ban=false;
	if(pin == verPersona.pin){
		ban=true;
	}
	return ban;
}

void retDinero(int num){ 
    int valor;
    Mensaje(num);
    if(ingresarDatos(num) != 0){
        del(numeroDeTarjeta);
        system("cls");  Mensaje(num);
        cout<<"Ingrese el valor a retirar > ";  cin>> valor;
        if(valor <= verPersona.saldo){
            system("cls");  Mensaje(num);
            LoadingRetiro();
            verPersona.saldo = verPersona.saldo - valor;
            cout<<endl<<"Retiro exitoso"<<endl;
        } else{
            system("cls");  Mensaje(num);
            SetColor(BLACK,RED);
            cout<<"Lo sentimos. Fondos insuficientes"<<endl;
        }
    }
    add();
	getch();
}

void depDinero(int num){ 
	int valor, numeroDeTarjeta;
    Mensaje(num);
    cout<<"Ingrese el numero de tarjeta a quien depositra > ";	cin>> numeroDeTarjeta;
	if(existReg(numeroDeTarjeta)== true){
        del(numeroDeTarjeta);
        cout<<"Ingrese el valor a depositar a "<< verPersona.nombre << " > "; cin>> valor;
        LoadingDeposito();
        verPersona.saldo = verPersona.saldo + valor;
        cout<<endl<<"Deposito exitoso"<<endl;
    }else{
        system("cls");  Mensaje(num);
        SetColor(BLACK,RED);
        cout<<"Lo sentimos. El usuario no está registrado"<<endl;
    }
    add();
	getch();
}

void transfDinero(int num){ 
    int valor;
    Mensaje(num);
	if(ingresarDatos(num) != 0){
        del(numeroDeTarjeta);
        system("cls");  Mensaje(num);
        cout<<"Ingrese el valor a transferir > ";  cin>> valor;
        if(valor <= verPersona.saldo){
            cout<<"Ingrese el numero de tarjeta a quien depositara > ";	cin>> numeroDeTarjeta2;
	        if(existReg2(numeroDeTarjeta2)== true){
                del(numeroDeTarjeta2);
                verPersona.saldo = verPersona.saldo - valor;
                verPersona2.saldo = verPersona2.saldo + valor;
                LoadingTransf();
                cout<<endl<<"Transferencia exitosa"<<endl; 
            }else{
                SetColor(BLACK,RED);
                cout<<"Lo sentimos. El usuario no está registrado"<<endl;
            }
        }else{
           system("cls");  Mensaje(num);
           SetColor(BLACK,RED);
           cout<<"Lo sentimos. Fondos insuficientes"<<endl;
       }
    }
    add();
    add2();
	getch();
}

void conDinero(int num){ 
	Mensaje(num);
    if(ingresarDatos(num) != 0){
        system("cls");  Mensaje(num);
        LoadingSaldo();
        cout<<endl<<"Saldo disponible > $ "<<verPersona.saldo;
    }
	getch();
}

int getOp(){
	int op;
	do{
        system("cls");
        SetColor(BLACK,CYAN);
        cout<<"O-----------------------------------------------------O"<<endl;
        cout<<"O                                                     O"<<endl;
        cout<<"O                      POLICAJERO                     O"<<endl;
        cout<<"O                                                     O"<<endl;
        cout<<"O-----------------------------------------------------O"<<endl;
		cout<<"O 1. Retirar                                          O"<<endl;
        cout<<"O 2. Depositar                                        O"<<endl;
        cout<<"O 3. Transferir                                       O"<<endl;
        cout<<"O 4. Consultar Saldo                                  O"<<endl;
        cout<<"O 0. Salir                                            O"<<endl;
        cout<<"O-----------------------------------------------------O"<<endl;	
            
		cout<<endl<<"Ingresa tu opcion > ";
		cin >> op;
	}while(op<0 || op>4);

	return op;
}