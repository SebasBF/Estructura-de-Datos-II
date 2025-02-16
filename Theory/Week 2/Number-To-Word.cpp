#include <iostream>
using namespace std;

string units[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve" };
string tens[] = { "", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string hundreds[] = { "", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

int checkPersistency(int number){
    int persistency = 0;

    do{
        number/= 1000;
        persistency++;
    }while(number > 999);

    return persistency;
}

int getFirstDigits( int number, int persistency){
    int firstDigits;

    for(int i = 0; i < checkPersistency(number); i++){
        firstDigits = number/1000;
    }
    return firstDigits;
}

void convertToWords(int number, int persistency){
    if(persistency == 2){
        
    }

}

int main(){
    int number;
    cout << "Indique el numero a convertir en palabras(limite 999,999,999.99): ";
    cin >> number;

    if(number == 0){
        cout << "\ncero";
    }

    int persistency = checkPersistency(number);
    int firstDigits = getFirstDigits(number, persistency);
    


}