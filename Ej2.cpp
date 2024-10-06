#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

/*Problema: En una tienda de electrónica, cada producto tiene un código único y quieres
gestionar el inventario. A medida que entran y salen productos, es necesario mantener el
sistema actualizado.
● Tarea: Inserta los productos con los siguientes códigos: 4001, 2002, 6003, 1500,
3500, 5000, 7000.
● Desafío: Un cliente compró los productos con códigos 2002 y 6003, así que
elimínalos del sistema. Luego, un nuevo producto con el código 2500 llega al
inventario. Imprime el inventario actualizado y verifica si el código 4001 todavía está
en el sistema.*/

int main() {
    ArbolBinario<int> arbol;
    int n, t;

    cout << "\nIngrese los codigos de los productos al arbol (termina con 0): " << endl;
    while (cin >> n && n != 0) {
        arbol.put(n);
    }

    cout << "Arbol: " << endl;
    arbol.print();


    cout << "\nIngrese la cantidad de productos que fueron comprados: " << endl;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "\nIngrese el codigo del producto comprado: " << endl;
        cin >> n;

        try {
            if (arbol.search(n)) {
                arbol.remove(n);
                cout << "El producto " << n << " ha sido eliminado del arbol" << endl;
            }
        } catch (int e) {
            cerr << "El producto no existe en el arbol" << endl;
        }
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese el codigo del nuevo producto a agregar: " << endl;
    cin >> n;
    arbol.put(n);
    cout << "El producto " << n << " ha sido agregado al arbol" << endl;
    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese el codigo del producto a verificar: " << endl;
    cin >> n;

    try {
        int a = arbol.search(n);
        cout << "El producto " << n << " se encuentra en el arbol" << endl;

    } catch (int e) {
        cerr << "El producto " << n << " no se encuentra en el arbol" << endl;
    }



    return 0;
}
