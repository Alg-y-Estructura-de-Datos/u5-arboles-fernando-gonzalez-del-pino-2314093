#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

/*Problema: Trabajas en una empresa de logística y debes gestionar los paquetes que llegan
y se entregan a través de un sistema. Cada paquete tiene un número de seguimiento único.
Tu sistema debe permitir la entrada de nuevos paquetes, la entrega (eliminación) de
paquetes, y la verificación de los que siguen en tránsito.
● Tarea: Inserta los paquetes con los números de seguimiento: 1001, 5002, 3003,
2004, 4500, 7005, 8006.
● Desafío: Los paquetes con los números de seguimiento 2004 y 4500 fueron
entregados, así que elimínalos. Luego, un nuevo paquete con el número 3500 llega
al sistema. Verifica si el paquete con el número 1001 sigue en tránsito e imprime la
lista de paquetes restantes*/

int main() {
    ArbolBinario<int> arbol;
    int n, t;

    cout << "\nIngrese los numeros de seguimiento de los paquetes al arbol (termina con 0): " << endl;
    while (cin >> n && n != 0) {
        arbol.put(n);
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese la cantidad de paquetes entregados: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Ingrese el numero de paquete a entregar: " << endl;
        cin >> n;
        arbol.remove(n);
        cout << "El paquete " << n << " ha sido entregado" << endl;
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese la cantidad de paquetes a registrar: " << endl;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Ingrese el numero de paquete: " << endl;
        cin >> n;
        arbol.put(n);
        cout << "El paquete " << n << " ha sido registrado" << endl;
    }

    cout << "\nIngrese al cantidad de paquetes que desea verificar: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "\nIngrese el numero de paquete a verificar: " << endl;
        cin >> n;
        try {
            int a = arbol.search(n);
            cout << "El paquete " << n << " esta registrado" << endl;
        } catch (int e) {
            cerr << "El paquete no se encuentra registrado" << endl;
        }
    }

    cout << "Arbol: " << endl;
    arbol.print();

    return 0;
}
