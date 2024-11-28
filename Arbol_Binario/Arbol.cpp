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
void preorden(Nodo*);
void inorden(Nodo*);
void postorden(Nodo*);


int main() {
	menu();
	
	return 0;
}
//Menu
void menu() {
    int dato, opcion, contador = 0;
    do {
        std::cout << "MENU" << std::endl;
        std::cout << "1. Insertar nuevo nodo" << std::endl;
        std::cout << "2. Mostrar Arbol (derecha a izquierda)" << std::endl;
        std::cout << "3. Recorrido en Preorden" << std::endl;
        std::cout << "4. Recorrido en Inorden" << std::endl;
        std::cout << "5. Recorrido en Postorden" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Dame un numero:" << std::endl;
            std::cin >> dato;
            insertarNodo(arbol, dato);
            std::cout << "" << std::endl;
            break;
        case 2:
            std::cout << "Mostrar arbol:" << std::endl;
            mostrarArbol(arbol, contador);
            std::cout << "" << std::endl;
            break;
        case 3:
            std::cout << "Recorrido en Preorden:" << std::endl;
            preorden(arbol);
            std::cout << "" << std::endl;
            break;
        case 4:
            std::cout << "Recorrido en Inorden:" << std::endl;
            inorden(arbol);
            std::cout << "" << std::endl;
            break;
        case 5:
            std::cout << "Recorrido en Postorden:" << std::endl;
            postorden(arbol);
            std::cout << "" << std::endl;
            break;
        case 6:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
        }
    } while (opcion != 6);
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
// Recorrido en Preorden
void preorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    std::cout << arbol->dato << " ";
    preorden(arbol->izq);
    preorden(arbol->der);
}

// Recorrido en Inorden
void inorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    inorden(arbol->izq);
    std::cout << arbol->dato << " ";
    inorden(arbol->der);
}

// Recorrido en Postorden
void postorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    postorden(arbol->izq);
    postorden(arbol->der);
    std::cout << arbol->dato << " ";
}