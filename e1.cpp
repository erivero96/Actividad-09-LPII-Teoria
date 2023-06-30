#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

//out_of_range es una subclase de excepction
template <typename T>
vector<T> arreglo(int indice) {
    vector<T> arreglo;
    try {
        cout << "Ingrese valores para las posiciones del arreglo: " << endl;
        for (int i = 0; i < indice; i++) {
            cout << "Posicion " << i << ": ";
            T value;
            cin >> value;

            arreglo.push_back(value);
        }
    } catch (const out_of_range& e) {
        cout << "Se ha producido una excepcion: " << e.what() << endl;
    }
    return arreglo;
}

template <typename T>
void mostrarVector(const vector<T>& x) {
    int indice;
    cout << "Ingrese el tamaño del vector: ";
    cin >> indice;
    try {
        if (indice < 0 or indice > x.size()) {
            throw out_of_range("El indice se encuentra fuera de rango");
        }
        for (int i = 0; i < indice; i++) {
            cout << "Posicion " << i << ": ";
            if (i >= x.size()) {
                throw out_of_range("El indice se encuentra fuera de rango");
            } else {
                cout << x[i] << endl;
            }
        }
    } catch (const out_of_range& e) {
        cout << "Se ha producido una excepcion: " << e.what() << endl;
    }
}

int main() {
    cout << "Ingrese el tamaño de los arreglos: ";
    int indice;
    cin >> indice;
    vector<int> arregloInt = arreglo<int>(indice);
    vector<string> arregloString = arreglo<string>(indice);
    mostrarVector<int>(arregloInt);
    mostrarVector<string>(arregloString);
    return 0;
}
