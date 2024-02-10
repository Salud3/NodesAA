#include "Node.h"
#include <iostream>

using namespace std;

void conectarVertices(Node* n1, Node* n2) {

    bool n2EstaEnLista = false;

    Node* actual = n1 -> siguiente; 

    while (actual != nullptr) {
        
        if (actual->id == n2->id) {
            
            n2EstaEnLista = true;

            break;
        }
        
        actual = actual -> siguiente;
    } 

    if (!n2EstaEnLista) {

        Node* nuevoNodo = new Node;
        
        nuevoNodo->id = n2->id;
        
        nuevoNodo->siguiente = n1->siguiente;
        
        n1->siguiente = nuevoNodo;
    }

    bool n1EstaEnLista = false;
    actual = n2->siguiente;
    while (actual != nullptr) {
        if (actual->id == n1->id) {
            n1EstaEnLista = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!n1EstaEnLista) {
        Node* nuevoNodo2 = new Node;
        nuevoNodo2->id = n1->id;
        nuevoNodo2->siguiente = n2->siguiente;
        n2->siguiente = nuevoNodo2;
    }
}


void imprimirAdyacentes(Node* v) {
    cout << "Vertice " << v->id << " esta conectado con: ";
    Node* actual = v->siguiente;
    while (actual != nullptr) {
        cout << actual->id << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {

    Node* v1 = new Node{ 1, nullptr };
    Node* v2 = new Node{ 2, nullptr };
    Node* v3 = new Node{ 3, nullptr };
    Node* v4 = new Node{ 4, nullptr };
    Node* v5 = new Node{ 5, nullptr };

    conectarVertices(v1, v2);
    conectarVertices(v2, v3);
    conectarVertices(v2, v4);
    conectarVertices(v2, v5);
    conectarVertices(v3, v2);
    conectarVertices(v3, v5);
    conectarVertices(v4, v2);
    conectarVertices(v4, v5);
    conectarVertices(v5, v2);
    conectarVertices(v5, v3);
    conectarVertices(v5, v4);


    imprimirAdyacentes(v1);
    imprimirAdyacentes(v2);
    imprimirAdyacentes(v3);
    imprimirAdyacentes(v4);
    imprimirAdyacentes(v5);


    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;

    return 0;
}

