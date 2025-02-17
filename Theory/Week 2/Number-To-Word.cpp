#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

string units[] = { "", "uno ", "dos ", "tres ", "cuatro ", "cinco ", "seis ", "siete ", "ocho ", "nueve ", "diez ", "once ", "doce ", "trece ", "catorce ", "quince ", "dieciséis ", "diecisiete ", "dieciocho ", "diecinueve " };
string tens[] = { "", "", "veinte ", "treinta ", "cuarenta ", "cincuenta ", "sesenta ", "setenta ", "ochenta ", "noventa " };
string hundreds[] = { "", "ciento ", "doscientos ", "trescientos ", "cuatrocientos ", "quinientos ", "seiscientos ", "setecientos ", "ochocientos ", "novecientos " };

string showCents(int number){
    string words = "";

    if(number == 0){
        return words;
    }
    words += "con " + to_string(number) + " centavos";
    return words;
}

string convertHundreds(int number){
    if(number == 0){ return ""; }
    if(number == 100){ return "cien ";};

    string words = " ";
    words += hundreds[number/100];
    number %= 100;

    if(number > 0){
        if(number < 20){
            words += units[number];
            return words;
        }
        words += tens[number/10];
        if(number%10 != 0){
            words += " y " + units[number%10];
            return words;
        }
    }
}

string convertThousands(int& number){
    if(number == 0){ return ""; }

    string words = " ";
    if(number >= 1000){
        int thousands = number/1000;
        if(thousands == 1){
            words += "mil ";
            return words;
        }
        words += convertHundreds(thousands) + "mil";
        number %= 1000;
    }

    return words;

}

string convertMillions(int& number){
    string words = " ";
    if(number >= 1000000){
        int millions = number/1000000;
        if(millions == 1){
            words += "un millon ";
            return words;
        }
        words += convertHundreds(millions) + "millones ";
        number %= 1000000;
    }

    return words;
}


string convertToWords(int number, int cents){
    if(number == 0){ return "\ncero"; }

    string words = "";

    words += convertMillions(number);
    words += convertThousands(number);
    words += convertHundreds(number);
    words += showCents(cents);

    return words;
}


int main(){
    double number;
    int cents, intPart;
    bool validEntry = false;
    do{

    cout << "Formato de ejemplo: 784000000.78 " << endl;
    cout << "Indique el monto a convertir en palabras(limite 999,999,999.99): ";
    cin >> number;
    
    if(cin.fail()){
        cout << "Entrada inválida. Favor intentar de nuevo.\n";   
        cout << "------------------------------------------------\n\n";   

        cin.clear();
        cin.ignore(256,'\n');
        continue;
    }
    
    if (number < 0 || number > 999999999) {
        cout << "Número fuera de rango. Favor intentar de nuevo.\n";
        cout << "------------------------------------------------\n\n";   
        continue;
    }
        validEntry = true;

    }while(!validEntry);

    intPart = number;
    cents = (number-intPart)*100;
    
    cout << convertToWords(number,cents) << endl;

    return 0;
}