#include <iostream>
#include <math.h>
using namespace std;

int main(){
string binary;
int decimal = 0, counter = 0;
cout << "Indique el número binario que quiere convertir a decimal: ";
cin >> binary;

int length = binary.length();
do{
    decimal += (binary[(length-counter) - 1] - '0')*pow(2,counter);
    counter++;

}while(counter < length);

cout << "\nEl valor decimal es: " << decimal;
}
