#include <iostream>
using namespace std;

double weights[5] = {10, 20, 30, 40, 50};
double benefit[5] = {20, 30, 65, 40, 60};

bool isFull(int currentWeight, int newWeight) {
    return (currentWeight + newWeight > 100);
}
int checkBestOption() {
    int bestOption = -1;
    double maxRatio = -1.0;

    for (int i = 0; i < 5; i++) {
        if (weights[i] > 0) { // Solo considerar elementos disponibles
            double avg = benefit[i] / weights[i];
            if (avg > maxRatio) {
                bestOption = i;
                maxRatio = avg;
            }
        }
    }
    return bestOption;
}
int main() {

    int currentWeight = 0, i = 0;
   
    double totalBenefit = 0;

    while (i < 5) {
        int best = checkBestOption();
        if (best == -1) break;  

       if (!isFull(currentWeight, weights[best])) {
             currentWeight +=  weights[best];
            totalBenefit += benefit[best];
             i++;
            cout << "Índice: " << best << ", Peso: " <<weights[best]  << "kg" << endl;
        } else {
            int remainingSpace = 100 - currentWeight;
             totalBenefit += ((benefit[best] / weights[best]) * remainingSpace);
             cout << "Índice: " << best << ", Peso fraccionado: " << remainingSpace << "kg" << endl;
            break;
        }
        weights[best] = 0;
    }
    cout << "\nBeneficio total obtenido: " << totalBenefit << endl;

    return 0;
}
