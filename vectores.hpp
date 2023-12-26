#include <string>
using namespace std;

struct Nodo {
	int info;
	Nodo* sig;
};

//colas ej 1

struct infoProceso {
	int id;
	int consumoCPU;
};

struct NodoProceso {
	infoProceso info;
	NodoProceso* sig;
};

struct servidor {
	int id;
	int sumaConsumoCPU;
	NodoProceso* colafte;
	NodoProceso* colafin;
};

//cola ej 2

struct infoFamilia {
	int id;
	int integrantes;
};

struct NodoFamilia{
	infoFamilia info;
	NodoFamilia* sig;
};

//pila ej 1

struct infoProducto {
	int id;
	int fecha;
};

struct NodoProducto {
	infoProducto info;
	NodoProducto* sig;
};

//pila ej 2
struct infoArticulo{
	int id;
	string nombre;
}; 

struct NodoArticulo {
	infoArticulo info;
	NodoArticulo* sig;
};

//jugadores
struct jugador{
	 unsigned id_jugador;
	 char nombres[50 + 1];
	 unsigned fecha_nacimiento;
	 char pais[50 + 1];
	 unsigned cantidad_goles;
};

struct jugo_en {
	unsigned id_jugador;
	char pais[50 + 1];
};

struct NodoListaJugadores {
	jugador info;
    NodoListaJugadores *sig;
};
struct NodoListaJugoEn {
    jugo_en info;
    NodoListaJugoEn *sig;
};

#ifndef vectores
#define vectores

void agregar(int arr[], int n, int &len, int v);
void mostrar(int arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int &len, int pos);
void insertar(int arr[], int &len, int v, int pos);
int insertarOrdenado(int arr[], int& len, int v); 
int buscaEInserta(int arr[], int& len, int v, bool& enc); 
void burbujaAsc(int vec[], int len);
int busquedaBinaria(int arr[],int len,int v);

//listas
void agregarNodo(Nodo*& lista, int x);
void mostrar(Nodo* lista);
void liberar(Nodo*& lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int v);
int eliminarPrimerNodo(Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void ordenar(Nodo*& lista);
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc);

//pilas
void push(Nodo*& pila, int v);
int pop(Nodo*& pila);

//colas
void encolar(Nodo*& colafte,Nodo*& colafin, int v);
int desencolar(Nodo*& colafte,Nodo*& colafin);

//colas ej 1
void agregarNodo(NodoProceso*& lista, infoProceso x);
infoProceso eliminarPrimerNodo(NodoProceso*& lista);
void encolar(NodoProceso*& colafte,NodoProceso*& colafin, infoProceso v);
void burbujaAsc(servidor vec[], int len);
infoProceso desencolar(NodoProceso*& colafte,NodoProceso*& colafin);

//colas ej 2
void encolar(NodoFamilia*& colafte,NodoFamilia*& colafin, infoFamilia v);
infoFamilia desencolar(NodoFamilia*& colafte,NodoFamilia*& colafin);

//pila ej 1
void push(NodoProducto*& pila, infoProducto v);
infoProducto pop(NodoProducto*& pila);
NodoProducto* insertarOrdenado(NodoProducto*& lista, infoProducto v);
infoProducto eliminarPrimerNodo(NodoProducto*& lista);

//pila ej 2
void agregarNodo(NodoArticulo*& lista, infoArticulo x);
void push(NodoArticulo*& pila, infoArticulo v);
infoArticulo pop(NodoArticulo*& pila);
NodoArticulo* buscar(NodoArticulo* lista, int v);

//jugadores
int edadDelCandidato(int fechaDeNacimiento);
NodoListaJugoEn* buscar(NodoListaJugoEn* listaSelecciones, int id_jugador);
NodoListaJugadores* buscar(NodoListaJugadores* listaJugadores, int id_jugador);
NodoListaJugadores* insertarOrdenado(NodoListaJugadores*& lista, jugador v);
NodoListaJugoEn* insertarOrdenado(NodoListaJugoEn*& lista, jugo_en v);
bool jugoEnOtraSeleccion(NodoListaJugoEn* listaSelecciones, int id_jugador, char pais[50 + 1]); //seleccion que lo quiere citar
void cargarDatosEnMemoria(FILE* archJugadores, FILE* archSelecciones,NodoListaJugadores*& listaJugadores,NodoListaJugoEn*& listaSelecciones);
bool puedeSerCitado(int id_jugador,char pais[50 + 1], NodoListaJugadores* listaJugadores,NodoListaJugoEn* listaSelecciones);
#endif