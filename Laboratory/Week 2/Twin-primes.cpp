//decir cuales son los primos gemelos desde el 3 hasta el 10k
#include <iostream> 
#include <math.h>
using namespace std;

/*
ENUNCIADO: Hacer un programa que generé n numeros primos.

FECHA: 19/12/2024

AUTORES: Sebastián Batista (1122881)
*/

bool esPrimo(int n) {
    if (n < 2) return false; // Los números menores que 2 no son primos
    if (n == 2 || n == 3) return true; // 2 y 3 son primos
    if (n % 2 == 0) return false; // Los números pares mayores que 2 no son primos

    int limite = sqrt(n); // Calcula la raíz cuadrada una vez
    for (int i = 3; i <= limite; i += 2) { // Itera solo sobre impares
        if (n % i == 0) return false; // Si es divisible, no es primo
    }
    return true; // Si no encontró divisores, es primo
}

int main(){
    for(int i = 3; i < 10001; i+=2){
        
            if(esPrimo(i) && esPrimo(i+2)){
                cout << "(" << i << "," << i+2 << ")" << endl;
            }
        

    }
     
    return 0;
}
