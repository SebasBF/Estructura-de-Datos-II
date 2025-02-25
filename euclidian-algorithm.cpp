#include <iostream>
using namespace std;

int mcd(int a, int b) {
    return (b == 0) ? a : mcd(b, a % b); // operador ternario para continuar dividiendo hasta que b sea 0
}

int main() {
    int a, b;
    cout << "Introduzca a: ";
    cin >> a; 
    cout << "Introduzca b: ";
    cin >> b;

    cout << "El MCD de " << a << " y " << b << " es: " << mcd(a, b) << endl;
    return 0;
}
