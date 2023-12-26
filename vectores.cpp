#include <iostream>
#include <string.h>
#include <ctime>
#include "vectores.hpp"
using namespace std;

//n -> cantidad maxima de elementos que tiene el vector
//len -> cantidad REAL de elementos que tiene el vector

void agregar(int arr[], int n, int &len, int v){
	 
	if(len == n){
		cout << "el vector esta lleno" << endl;
	} else {
		arr[len] =  v;
		len++;	
	}
	
	return;
}

void mostrar(int arr[], int len){
	
	for(int i=0; i < len; i++){
		cout << arr[i] << endl;
	}
	
	return;
}

int buscar(int arr[], int len, int v){
	int i = 0;
	int pos;
	
	while(i < len && arr[i] != v){
		i++;
	}
	
	if(i == len){
		pos = -1;
	} else {
		pos = i;
	}
	
	return pos;
}

void eliminar(int arr[], int &len, int pos){
	
	for(int i = pos; i < len - 1; i++){
		arr[i] = arr[i+1];
	}
	
	len--;
	return;
}

void insertar(int arr[], int &len, int v, int pos){
	
	for(int i = len -1; i >= pos; i--){
		arr[i+1] = arr[i];
	}

	arr[pos] = v;
	len++;
	return;
}

int insertarOrdenado(int arr[], int& len, int v){
	int i = 0;
	
	while(i < len && arr[i] <= v){
		i++;
	}	
	
	insertar(arr,len,v,i);
	
	return i;
}

//si v está en el arr, devuelve la pos en la que está y enc en "true"
//si v no está en el arr, lo inserta y devuelve la pos en la que lo insertó y enc en "false"

int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){ // v no está en el arr
		enc = false;
		pos = insertarOrdenado(arr,len,v); 
	} else {
		enc = true;	
	}
	
	return pos;
}

//Búsqueda Binaria
int busquedaBinaria(int vec[],int len,int v){
	int primero = 0;
	int ultimo = len-1;
	int pos;
	
	int medio = (primero+ultimo) / 2;
	
	while(primero<=ultimo){

		if(vec[medio] > v){
			ultimo = medio -1;
		} else if(vec[medio] == v){
			break;
		} else {  //menor a v
			primero = medio +1;
		}
		
		medio = (primero+ultimo) / 2;
	}
	
	if(primero > ultimo){
		pos = -1;	
	} else {
		pos = medio;
	}
	
	return pos;
	
}

void burbujaAsc(int vec[], int len){
	int temp;
	bool huboIntercambio = true;
	
	for(int i = 0; i < len - 1 && huboIntercambio ; i++){
		huboIntercambio = false;
		for(int j = 0; j < len-i-1; j++){
			if(vec[j] > vec[j+1]) {
				huboIntercambio = true;
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}	
		}
	}
}


void agregarNodo(Nodo*& lista, int x){

    Nodo* nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
	
	if(lista == NULL){
       lista = nuevo;
	} else {
	   Nodo* aux = lista;
	   while(aux->sig != NULL){
	   	  aux = aux->sig;
	   }
	   aux->sig = nuevo;
	}
	
}

void mostrar(Nodo* lista){
	Nodo * aux = lista;
	while(aux != NULL){
	   cout << aux->info << endl;	
	   aux = aux->sig;
	}
}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sig;
		delete aux;
	}
}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	while(aux != NULL && aux->info != v){
		aux = aux->sig;
	}
		
	return aux;
}

void eliminar(Nodo*& lista, int v){
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux!= NULL && aux->info != v){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant != NULL){
		ant->sig = aux->sig;
	} else {
		lista = aux->sig;
	}
	
	delete aux;	
}


int eliminarPrimerNodo(Nodo*& lista){
	int retorno = lista->info;
	Nodo * aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info<= v){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL){
		lista = nuevo;
	} else{
		ant->sig = nuevo;
	}	
	nuevo->sig = aux;
	
	return nuevo;
}

void ordenar(Nodo*& lista){
	int valor;
	Nodo* listaAux = NULL;
	while(lista != NULL){
		valor = eliminarPrimerNodo(lista);
		insertarOrdenado(listaAux,valor);
	}
	lista = listaAux;
}

Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc){
	Nodo* nodoBuscado = buscar(lista,v);
	
	if(nodoBuscado == NULL){
		nodoBuscado = insertarOrdenado(lista,v);
		enc = false;
	} else {
		enc = true;
	}
	
	return nodoBuscado;
}

void push(Nodo*& pila, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(Nodo*& pila){
	int retorno = pila->info;
	Nodo* aux = pila;
	pila = aux->sig;
	delete aux;
	return retorno;
}

void encolar(Nodo*& colafte,Nodo*& colafin, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL){
		colafte = nuevo;
	} else {
		colafin->sig = nuevo;
	}
	colafin = nuevo;
}

int desencolar(Nodo*& colafte,Nodo*& colafin){
	int retorno = colafte->info;
	Nodo* aux = colafte;
	colafte = colafte->sig;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return retorno;
}

//colas ej 1
void agregarNodo(NodoProceso*& lista, infoProceso x){
    NodoProceso* nuevo = new NodoProceso();
    nuevo->info = x;
    nuevo->sig = NULL;
	
	if(lista == NULL){
       lista = nuevo;
	} else {
	   NodoProceso* aux = lista;
	   while(aux->sig != NULL){
	   	  aux = aux->sig;
	   }
	   aux->sig = nuevo;
	}
}

infoProceso eliminarPrimerNodo(NodoProceso*& lista){
	infoProceso retorno = lista->info;
	NodoProceso * aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
}

void encolar(NodoProceso*& colafte,NodoProceso*& colafin, infoProceso v){
	NodoProceso* nuevo = new NodoProceso();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL){
		colafte = nuevo;
	} else {
		colafin->sig = nuevo;
	}
	colafin = nuevo;
}

void burbujaAsc(servidor vec[], int len){
	servidor temp;
	bool huboIntercambio = true;
	
	for(int i = 0; i < len - 1 && huboIntercambio ; i++){
		huboIntercambio = false;
		for(int j = 0; j < len-i-1; j++){
			if(vec[j].sumaConsumoCPU > vec[j+1].sumaConsumoCPU) {
				huboIntercambio = true;
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}	
		}
	}
}

infoProceso desencolar(NodoProceso*& colafte,NodoProceso*& colafin){
	infoProceso retorno = colafte->info;
	NodoProceso* aux = colafte;
	colafte = colafte->sig;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return retorno;
}

//colas ej 2
void encolar(NodoFamilia*& colafte,NodoFamilia*& colafin, infoFamilia v){
	NodoFamilia* nuevo = new NodoFamilia();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL){
		colafte = nuevo;
	} else {
		colafin->sig = nuevo;
	}
	colafin = nuevo;
}

infoFamilia desencolar(NodoFamilia*& colafte,NodoFamilia*& colafin){
	infoFamilia retorno = colafte->info;
	NodoFamilia* aux = colafte;
	colafte = colafte->sig;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return retorno;
}


//pila ej 1
void push(NodoProducto*& pila, infoProducto v){
	NodoProducto* nuevo = new NodoProducto();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
};

infoProducto pop(NodoProducto*& pila){
	infoProducto retorno = pila->info;
	NodoProducto* aux = pila;
	pila = aux->sig;
	delete aux;
	return retorno;
}

NodoProducto* insertarOrdenado(NodoProducto*& lista, infoProducto v){
	NodoProducto* nuevo = new NodoProducto();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoProducto* aux = lista;
	NodoProducto* ant = NULL;
	
	while(aux != NULL && aux->info.fecha<= v.fecha){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL){
		lista = nuevo;
	} else{
		ant->sig = nuevo;
	}	
	nuevo->sig = aux;
	
	return nuevo;
}

infoProducto eliminarPrimerNodo(NodoProducto*& lista){
	infoProducto retorno = lista->info;
	NodoProducto * aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
}

//pila ej 2
void push(NodoArticulo*& pila, infoArticulo v){
	NodoArticulo* nuevo = new NodoArticulo();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
};

infoArticulo pop(NodoArticulo*& pila){
	infoArticulo retorno = pila->info;
	NodoArticulo* aux = pila;
	pila = aux->sig;
	delete aux;
	return retorno;
}

void agregarNodo(NodoArticulo*& lista, infoArticulo x){
    NodoArticulo* nuevo = new NodoArticulo();
    nuevo->info = x;
    nuevo->sig = NULL;
	
	if(lista == NULL){
       lista = nuevo;
	} else {
	   NodoArticulo* aux = lista;
	   while(aux->sig != NULL){
	   	  aux = aux->sig;
	   }
	   aux->sig = nuevo;
	}
}

NodoArticulo* buscar(NodoArticulo* lista, int v){
	NodoArticulo* aux = lista;
	while(aux != NULL && aux->info.id != v){
		aux = aux->sig;
	}
		
	return aux;
}

//jugadores
int edadDelCandidato(int fechaDeNacimiento){
	time_t t = time(0);  
 	tm* now = localtime(&t); 
	 
	int anioActual = now->tm_year + 1900;
 	int mesActual = now->tm_mon +1;
 	int diaActual = now->tm_mday;
 	
 	int fechaActual = anioActual*10000 + mesActual*100 + diaActual;
 	int edad = (fechaActual - fechaDeNacimiento)/10000;
 	
 	return edad;
}

NodoListaJugoEn* buscar(NodoListaJugoEn* listaSelecciones, int id_jugador){
	NodoListaJugoEn* aux = listaSelecciones;
	while(aux != NULL && aux->info.id_jugador != id_jugador){
		aux = aux->sig;
	}
		
	return aux;
}
NodoListaJugadores* buscar(NodoListaJugadores* listaJugadores, int id_jugador){
	NodoListaJugadores* aux = listaJugadores;
	while(aux != NULL && aux->info.id_jugador != id_jugador){
		aux = aux->sig;
	}
		
	return aux;
}

bool jugoEnOtraSeleccion(NodoListaJugoEn* listaSelecciones, int id_jugador, char pais[50 + 1]){
	NodoListaJugoEn* jugadorBuscado = buscar(listaSelecciones, id_jugador);
	bool jugoEnOtra = true;
	
	if(strcmp(jugadorBuscado->info.pais,pais) == 0 || jugadorBuscado == NULL){
		jugoEnOtra = false;
	}
	
	return jugoEnOtra;
} 

NodoListaJugadores* insertarOrdenado(NodoListaJugadores*& lista, jugador v){
	NodoListaJugadores* nuevo = new NodoListaJugadores();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoListaJugadores* aux = lista;
	NodoListaJugadores* ant = NULL;
	
	while(aux != NULL && aux->info.id_jugador<= v.id_jugador){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL){
		lista = nuevo;
	} else{
		ant->sig = nuevo;
	}	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoListaJugoEn* insertarOrdenado(NodoListaJugoEn*& lista, jugo_en v){
	NodoListaJugoEn* nuevo = new NodoListaJugoEn();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoListaJugoEn* aux = lista;
	NodoListaJugoEn* ant = NULL;
	
	while(aux != NULL && aux->info.id_jugador <= v.id_jugador){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL){
		lista = nuevo;
	} else{
		ant->sig = nuevo;
	}	
	nuevo->sig = aux;
	
	return nuevo;
}

void cargarDatosEnMemoria(FILE* archJugadores, FILE* archSelecciones,NodoListaJugadores*& listaJugadores,NodoListaJugoEn*& listaSelecciones){
	jugador regJ;
	jugo_en regJE;

	fread(&regJ,sizeof(jugador),1,archJugadores);
	
	while(!feof(archJugadores)){
		insertarOrdenado(listaJugadores,regJ);
		fread(&regJ,sizeof(jugador),1,archJugadores);	
	}
	
	fclose(archJugadores);
		
	fread(&regJE,sizeof(jugo_en),1,archSelecciones);
	
	while(!feof(archSelecciones)){
		insertarOrdenado(listaSelecciones,regJE);
		fread(&regJE,sizeof(jugo_en),1,archSelecciones);	
	}
	
	fclose(archSelecciones);
}

bool puedeSerCitado(int id_jugador,char pais[50 + 1], NodoListaJugadores* listaJugadores,NodoListaJugoEn* listaSelecciones){
	//ciudadano nativo del país convocante
	//menor de 30 
   //no haber participado en el pasado en la selección de ningún país distinto al que lo convoca.
   NodoListaJugadores* jugadorBuscado = buscar(listaJugadores,id_jugador);
   bool puede = true;
   int edad;
   bool jugoEnOtra;
   
   if(jugadorBuscado == NULL){
   	  puede = false;
   } else {
   		edad = edadDelCandidato(jugadorBuscado->info.fecha_nacimiento);
   		if(edad >= 30){
   			puede = false;
		} else {
			jugoEnOtra = jugoEnOtraSeleccion(listaSelecciones,id_jugador,pais);
			if(jugoEnOtra){
				puede = false;
			} else {
				if(strcmp(jugadorBuscado->info.pais,pais) != 0){
					puede = false;
				}
			}
		}
   }
   
   return puede;
}