#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

/*Problema: Un restaurante tiene un sistema de reservas donde cada mesa tiene un número
específico. A medida que los clientes reservan o cancelan mesas, el sistema debe
mantenerse actualizado.
● Tarea: Agrega las reservas de las siguientes mesas: 15, 10, 20, 5, 12, 18, 25.
● Desafío: Dos clientes cancelaron sus reservas en las mesas 10 y 20, así que
elimínalas del sistema. Luego, un nuevo cliente reserva la mesa 13. Verifica si la
mesa 12 aún está reservada e imprime la lista actualizada de mesas reservadas*/

int main() {
    ArbolBinario<int> arbol;
    int n, t;

    cout << "\nIngrese los numeros de las mesas reservadas al arbol (termina con 0): " << endl;
    while (cin >> n && n != 0) {
        arbol.put(n);
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese la cantidad de mesas que fueron canceladas: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Ingrese el numero de mesa cancelada: " << endl;
        cin >> n;
        arbol.remove(n);
        cout << "La mesa " << n << " ha sido cancelada" << endl;
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese la cantidad de mesas a reservar: " << endl;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Ingrese el numero de mesa a reservar: " << endl;
        cin >> n;
        arbol.put(n);
        cout << "La mesa " << n << " ha sido reservada" << endl;
    }

    cout << "\nIngrese al cantidad de mesas que desea verificar: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "\nIngrese el numero de mesa a verificar: " << endl;
        cin >> n;
        try {
            int a = arbol.search(n);
            cout << "La mesa " << n << " se encuentra reservada" << endl;
        } catch (int e) {
            cerr << "La mesa no esta reservada" << endl;
        }
    }

    cout << "Arbol: " << endl;
    arbol.print();

    return 0;
}