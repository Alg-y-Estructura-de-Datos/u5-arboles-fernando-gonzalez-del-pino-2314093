#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

/*Problema: Estás organizando una biblioteca familiar. Cada libro tiene un número único de
identificación (ID) y quieres organizar los libros en un sistema que te permita agregarlos,
eliminarlos y buscarlos fácilmente.
● Tarea: Inserta los libros con los siguientes IDs en el sistema de gestión (árbol): 101,
52, 198, 36, 75, 150, 200.
● Desafío: Busca el libro con el ID 75 y verifica si está en la biblioteca. Luego elimina
el libro con el ID 52 porque fue prestado. Imprime la estructura del sistema después
de la eliminación.
*/

int main() {
    ArbolBinario<int> arbol;
    int n;

    cout << "\nIngrese los nodos del arbol: " << endl;

    while (cin >> n && n != 0) {
        arbol.put(n);
    }

    cout << "Arbol: " << endl;
    arbol.print();

    cout << "\nIngrese el numero a buscar en el arbol: " << endl;
    cin >> n;

    try {
        int a = arbol.search(n);
        cout << "El numero " << n << " se encuentra en el arbol" << endl;

    } catch (int e) {
        cerr << "Error al buscar el numero " << n << endl;
    }

    cout << "\nIngrese el numero a eliminar del arbol: " << endl;
    cin >> n;

    arbol.remove(n);
    cout << "El numero " << n << " ha sido eliminado del arbol" << endl;

    cout << "Arbol: " << endl;
    arbol.print();

    return 0;
}
