#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

string units[] = { "un ", "uno ", "dos ", "tres ", "cuatro ", "cinco ", "seis ", "siete ", "ocho ", "nueve ", "diez ", "once ", "doce ", "trece ", "catorce ", "quince ", "dieciseis ", "diecisiete ", "dieciocho ", "diecinueve " };
string tens[] = { "", "", "veinte ", "treinta ", "cuarenta ", "cincuenta ", "sesenta ", "setenta ", "ochenta ", "noventa " };
string twenties[] = { "veintiuno ", "veintiun ", "veintidos ", "veintitres ", "veinticuatro ", "veinticinco ", "veintiseis ", "veintisiete ", "veintiocho ", "veintinueve " };
string hundreds[] = { "", "ciento ", "doscientos ", "trescientos ", "cuatrocientos ", "quinientos ", "seiscientos ", "setecientos ", "ochocientos ", "novecientos " };

string showCents(int number){
    if(number == 0) return "";
    return "con " + to_string(number) + (number == 1 ? " centavo." : " centavos.");
}

string convertHundreds(int number, bool isThousandOrMillion){ 
    if(number == 0) return "";
    if(number == 100) return "cien ";

    string words = "";  
    words += hundreds[number/100]; 
    number %= 100; 

    if(number > 0){
        if(number < 20){
            words += units[number];
            return words;
        } 
        else if(number > 20 && number < 30){
            if(number == 21){
                words += (isThousandOrMillion) ? twenties[1] : twenties[0];
                return words;
            }
            words += twenties[number%10];
            return words;

        }
        
        words += tens[number/10];
        if(number % 10 != 0){
            if(isThousandOrMillion && number % 10 == 1){
                words += "y " + units[0];
                return words;
            }
            words += "y " + units[number%10];
        }
    
    }

    return words;
}

string convertThousands(int& number){
    if(number == 0) return "";
    
    string words = "";
    if(number >= 1000){
        int thousands = number / 1000;

        if(thousands == 1){
            words += "mil ";
        } 
        else{
            words += convertHundreds(thousands, true) + "mil ";
        }
        number %= 1000;
    }

    return words;
}

string convertMillions(int& number){
    if(number == 0) return "";
    
    string words = "";
    if(number >= 1000000){
        int millions = number / 1000000;

        if(millions == 1){
            words += "un millon ";
        }
        else{
            words += convertHundreds(millions, true) + "millones ";
        }
        number %= 1000000;
    }

    return words;
}

string convertToWords(int number, int cents){
    if(number == 0) return "cero";

    string words = "";
    words += convertMillions(number);
    words += convertThousands(number);
    words += convertHundreds(number, false);
    words += showCents(cents);

    return words;
}

double getValidNumber() {
    double number;
    bool validEntry;

    do{
        validEntry = true;
        cout << "Formato de ejemplo: 125784295.25" << endl;
        cout << "Indique el monto a convertir en palabras (limite 999,999,999.99): ";

        cin >> number;

        if(cin.fail() || cin.peek() != '\n'){
            cout << "Entrada invalida. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";

            cin.clear();
            cin.ignore(256, '\n');
            validEntry = false;
        }
        if(number < 0 || number > 999999999.99) {
            cout << "Numero fuera de rango. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";

            validEntry = false;
        }

    }while(!validEntry);

    return number;
}

int main(){
    double number = getValidNumber();
    int cents, intPart = number;
    
    cents = round((number - intPart) * 100);

    cout << endl;
    cout << convertToWords(intPart, cents) << endl;

    return 0;
}
