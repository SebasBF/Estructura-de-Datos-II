#include <iostream>
using namespace std;

int weights[5] = {10, 20, 30, 40, 50};
int benefit[5] = {20, 30, 65, 40, 60};

bool isFull(int currentWeight, int newWeight) {
    return (currentWeight + newWeight > 100);
}

int checkBestOption() {
    int bestOption = -1;
    double maxRatio = -1.0;

    for (int i = 0; i < 5; i++) {
        if (weights[i] > 0) {  // Solo considerar elementos disponibles
            double avg = (double)benefit[i] / weights[i];
            if (avg > maxRatio) {
                bestOption = i;
                maxRatio = avg;
            }
        }
    }

    return bestOption;
}

void showBackpack(int backpack[], double amounts[], int size) {
    cout << "Objetos seleccionados: \n" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Índice: " << backpack[i] << ", Peso: " << amounts[i] << "kg" << endl;
    }
   
}

int main() {
    int backpack[4], currentWeight = 0, i = 0;
    double amounts[4];  
    int totalBenefit = 0;

    while (i < 5) {
        int best = checkBestOption();
        if (best == -1) break;  

        int newWeight = weights[best];

        if (!isFull(currentWeight, newWeight)) {  
            backpack[i] = best;
            amounts[i] = newWeight;
            
            currentWeight += newWeight;
            totalBenefit += benefit[best];

            weights[best] = 0; 
            i++;
            
        } 
        else {  
            int remainingSpace = 100 - currentWeight;
            backpack[i] = best;
            amounts[i] = remainingSpace;
            
            totalBenefit += (((double)benefit[best] / weights[best]) * remainingSpace);

            currentWeight = 100; 
            break;
        }
    }

    showBackpack(backpack, amounts, i + 1);
    cout << "\nBeneficio total obtenido: " << totalBenefit << endl;

    return 0;
}
