#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double loanValue, TNA;
    int years;

    cout << "Ingrese el valor del Prestamo: ";
    cin >> loanValue;

    cout << "Ingrese el valor del TNA (en %): ";
    cin >> TNA;

    cout << "Ingrese el numero de años: ";
    cin >> years;
    cout << "\n";

    double equalInterest = (TNA / 100) / 12;
    int totalFee = years * 12;
    double fixedFee = (loanValue * equalInterest) / (1 - pow(1 + equalInterest, -totalFee));

    double livingCapital = loanValue;

    cout << fixed << setprecision(2);

    cout << "Capital Vivo: " << livingCapital << endl;


    cout << "Numero de Cuota   Cuota a pagar   Interes   Capital Amortizado   Capital vivo" << endl;
    
    for (int i = 0; i <= totalFee; i++)
    {
        cout << "---------------------------------------------------------------" << endl;

        if (i == 0)
        {
            cout << i << "                -              -                -              " << livingCapital << endl;
        }
        else
        {
            double interes = livingCapital * equalInterest;
            double capitalAmortizado = fixedFee - interes;
            livingCapital -= capitalAmortizado;

            if (i == totalFee) livingCapital = 0;

            cout << i;
            cout << "            " << fixedFee;
            cout << "            " << interes;
            cout << "            " << capitalAmortizado;
            cout << "            " << livingCapital;
            cout << endl;
        }

        cout << "---------------------------------------------------------------" << endl;
    }

    return 0;
}
