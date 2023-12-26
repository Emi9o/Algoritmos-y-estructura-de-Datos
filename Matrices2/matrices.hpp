#include <string>
#define MAX_FILAS 20
#define MAX_COLUMNAS 20
using namespace std;

#ifndef matrices
#define matrices

void inicializar (float mat[][MAX_COLUMNAS], int f, int c);
void cargar(float mat[][MAX_COLUMNAS], int f, int c);
void mostrar(float mat[][MAX_COLUMNAS], int f, int c);
float buscarMaximaMedicion(float mat[][MAX_COLUMNAS], int f, int c, int &posF, int &posC);
float buscarMinimaMedicion(float mat[][MAX_COLUMNAS], int f, int c, int &posF, int &posC);
void mostrarResultado(string texto, float valor, int posF, int posC); 
#endif
