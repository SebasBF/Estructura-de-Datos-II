#include <iostream>
using namespace std;

void findQR(int a, int b, int& q, int& r){
    q = 0, r = a;

    if(r < 0){   //Si a es negativo.
        do{
            r += b; 
            q--;
        }while(r < 0);

        return;
    }
    else if (a < b) {  //Si a es menor que b
        return;
    } 

    do{   //Caso base
        r -= b; 
        q++;
    }while(r > b);
 
}

int main(){
    int a,b,q,r;
    
    cout << "Introduzca a: ";
    cin >> a;

    cout << "Introduzca b: ";
    cin >> b;

    cout << endl;

    findQR(a,b,q,r);
    cout << a << " = " << q << "(" << b << ")" << " + " << r << endl;
    cout << a << " = " << q*b + r;

    return 0;
}