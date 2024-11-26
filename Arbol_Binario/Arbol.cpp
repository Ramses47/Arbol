#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;
};


void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
Nodo *arbol = NULL;
void mostrarArbol(Nodo*, int);


int main() {
	menu();
	
	return 0;
}
//Menu
void menu() {
	int dato, opcion, contador=0;
	do {
		std::cout << "MENU" << std::endl;
		std::cout << "1. Insertar nuevo nodo" << std::endl;
		std::cout << "2. Mostar Arbol" << std::endl;
		std::cout << "3. Salir" << std::endl;
		std::cin >> opcion;

		switch (opcion)
		{
		case 1: std::cout << "Dame un numero:" << std :: endl;
			std::cin >> dato;
			insertarNodo(arbol, dato);
			std::cout << "" << std::endl;
			break;

		case 2:
			std::cout << "Mostrar arbol" << std::endl;
			mostrarArbol(arbol, contador);
			std::cout << "" << std::endl;
			break;
		case 3:
			std::cout << "Saliendo" << std::endl;
			break;
		default:
			std::cout << "opcion no valida" << std::endl;
			break;
		}
	} while (opcion != 3);
}

//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n) {
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

//Funcion para incertar elemetos en el arbol
void insertarNodo(Nodo*& arbol, int n) {
	if (arbol == NULL) {//Si el arbol esta vacio
		Nodo* nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else {//Si el arbol tiene un nodo o mas
		int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
		if (n < valorRaiz) {//Si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq, n);
		}
		else {// Si el elemento es mayor a la raiz, insertamos en der
			insertarNodo(arbol->der, n);
		}
	}
}

void mostrarArbol(Nodo* arbol, int cont) {
	if (arbol == NULL) {
		
		return;
	}
	else {
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			std::cout << "  ";
		}
		std::cout << arbol->dato << std::endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}