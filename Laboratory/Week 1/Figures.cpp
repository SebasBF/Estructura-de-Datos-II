#include <iostream>
using namespace std;

void rightTriangle(int n, int spaces){
    if(spaces == 0){ return; }

    for(int i = 0; i < spaces; i++){ 
        cout << " "; 
    }

    for(int i = 0; i <= (n - spaces) ; i++){
        cout << "*";
    }
    
    cout << endl;

    return rightTriangle(n, spaces - 1);
}

void equilateralTriangle(int n, int spaces){
    if(spaces == 0){ return; }

    for(int i = 0; i < spaces; i++){ 
        cout << " "; 
    }

    for(int i = 0; i <= 2*(n - spaces) ; i++){
        cout << "*";
    }
 
    cout << endl;

    return equilateralTriangle(n, spaces - 1);
}

void invertedTriangle(int n, int spaces = 1){
    
    if(spaces > n){ return; }

    for(int i = 0; i < spaces; i++){ 
        cout << " "; 
    }

    for(int i = 0; i <=  2*(n - spaces) ; i++){
        cout << "*";
    }
 
    cout << endl;

    return invertedTriangle(n, spaces + 1);
}


int main(){
    int levels;

    cout << "Indicate how many levels the figures will have: ";
    cin >> levels;
    cout << endl;

    rightTriangle(levels, levels);
    cout << endl;
    equilateralTriangle(levels,levels);
    cout << endl;
    invertedTriangle(levels);
    
}