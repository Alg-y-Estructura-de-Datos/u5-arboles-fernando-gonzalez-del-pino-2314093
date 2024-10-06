#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

/*Problema: Estás diseñando un sistema de inscripción para un gimnasio, donde cada socio
tiene un número de socio único. El sistema debe permitir la inscripción de nuevos socios, la
eliminación de socios que se dan de baja, y la búsqueda de socios activos.
● Tarea: Inscribe a los socios con los siguientes números de socio: 500, 250, 750, 100,
300, 600, 800.
● Desafío: Un socio con el número 250 se da de baja, así que elimínalo. Luego,
verifica si los socios con los números 300 y 750 aún están activos. Imprime la lista
de socios actualizada.*/

int main() {
    ArbolBinario<int> arbol;
    int n, t;

    cout << "\nIngrese los socios al arbol (termina con 0): " << endl;
    while (cin >> n && n != 0) {
        arbol.put(n);
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese el numero de socio a dar de baja: " << endl;
    cin >> n;
    try {
        if (arbol.search(n)) {
            arbol.remove(n);
            cout << "El socio " << n << " ha sido dado de baja del arbol" << endl;
        }
    } catch (int e) {
        cerr << "El socio no existe en el arbol" << endl;
    }

    cout << "Arbol despues de dar de baja: " << endl;
    arbol.print();

    cout << "\nIngrese al cantidad de socios que desea verificar: " << endl;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "\nIngrese el numero de socio a verificar: " << endl;
        cin >> n;
    try {
        int a = arbol.search(n);
        cout << "El socio " << n << " se encuentra en el arbol" << endl;
    } catch (int e) {
        cerr << "El socio no existe en el arbol" << endl;
    }
    }


    return 0;
}
