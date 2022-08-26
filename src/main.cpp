#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector> 
#include <cstring> 
#include <stdlib.h>
#include <windows.h>
#include "../lib/funciones.h"

using namespace std;

int main(){
	Salvapantalla();
	do{	
		loadInfo();
		system("cls");
		switch(getOp()){
				case retirar	: retDinero(retirar);	saveInfo();
								  break;
				case depositar	: depDinero(depositar);	saveInfo();
								  break;
				case transferir	: transfDinero(transferir);	saveInfo();
								  break;
				case saldo		: conDinero(saldo);		saveInfo();
								  break;
				case salir 		: Mensaje(salir);	 EXIT_SUCCESS; return 0;

				default:  		  cout<<endl<< "Opcion no valida..!"<<endl;		break;
			}
	}while(true);
	
	return 0;
	getch();
}