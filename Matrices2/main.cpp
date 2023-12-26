#include <iostream>
#include <string>
#include "matrices.hpp"
using namespace std;

int main() {
	float matriz[MAX_FILAS][MAX_COLUMNAS];
	int cantFilas;
	int cantColumnas;
	float maxMedicion;
	float minMedicion;
	int posFilMax;
	int posColMax;
	int posFilMin;
	int posColMin;
	
	cout << "Ingrese la cantidad de filas" << endl;
	cin >> cantFilas;
	
	while(cantFilas != 3) {
		cout << "Ingrese la cantidad de filas" << endl;
		cin >> cantFilas;
	}
	
	cout << "Ingrese la cantidad de Columnas" << endl;
	cin >> cantColumnas;
	
	while(cantColumnas != 7){
			cout << "Ingrese la cantidad de Columnas" << endl;
			cin >> cantColumnas;
	}
	
	inicializar(matriz,cantFilas,cantColumnas);
	cargar(matriz,cantFilas,cantColumnas);
	//mostrar(matriz,cantFilas,cantColumnas);
	
	minMedicion = buscarMinimaMedicion(matriz, cantFilas, cantColumnas, posFilMin, posColMin);
	mostrarResultado("La minima medicion fue ", minMedicion, posFilMin, posColMin);
	
	cout << endl;
	
	maxMedicion = buscarMaximaMedicion(matriz, cantFilas, cantColumnas, posFilMax, posColMax);
	mostrarResultado("La maxima medicion fue ", maxMedicion, posFilMax, posColMax);
	
	return 0;
}











