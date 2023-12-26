#include <iostream>
#include "matrices.hpp"
using namespace std;

void inicializar (float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			m[i][j] = 0;
		}
	}
	return;
}

void cargar (float m[][MAX_COLUMNAS], int f, int c){
	float medicion;
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << "Ingresar Medicion" << endl;
			cin >> medicion;
			m[i][j] = medicion;
		}
	}
	return;
}

void mostrar(float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

float buscarMaximaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){
	float maximo = -100;  
	for(int i = 0; i < f; i++){
	    for (int j=0; j < c; j++){
	        if(m[i][j] > maximo){
	            maximo = m[i][j];
	            posF = i;
	            posC = j;
	        }
	        
	    }
	}
	  
	return maximo;
}
	

float buscarMinimaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){
	float minimo = 200;  
	for(int i = 0; i < f; i++){
	    for (int j=0; j < c; j++){
	        if(m[i][j] < minimo){
	            minimo = m[i][j];
	            posF = i;
	            posC = j;
	        }
	        
	    }
	}
	  
	return minimo;
}

void mostrarResultado(string texto, float valor, int posF, int posC){
    cout << texto << valor;
    
    cout << " el ";
    switch(posC){
        case 0:
            cout << "Domingo";
            break;
        case 1:
            cout << "Lunes";
            break;
        case 2:
            cout << "Martes";
            break;
        case 3:
            cout << "Miercoles";
            break;
        case 4:
            cout << "Jueves";
            break;
         case 5:
            cout << "Viernes";
            break;
        case 6:
            cout << "Sabado";
            break;
        default:
            break;
    }
    
    cout << " a la ";
    
    switch(posF){
        case 0:
            cout << "Mañana";
            break;
        case 1:
            cout << "Tarde";
            break;
        case 2:
            cout << "Noche";
            break;
        default:
            break;
    }
    
    
	return;
}