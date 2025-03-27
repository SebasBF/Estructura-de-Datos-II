#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

string nombre[30] = {
    "Juan", "María", "Carlos", "Ana", "Pedro", "Laura", "José", "Marta", "Luis", "Sofía",
    "Andrés", "Valeria", "Diego", "Elena", "Fernando", "Camila", "Roberto", "Paula", "Javier", "Lucía",
    "Ricardo", "Gabriela", "Héctor", "Patricia", "Emilio", "Carolina", "Manuel", "Isabel", "Raúl", "Natalia"
};

double salarioMensual[30] = {
    35500, 33200, 3800, 44100, 2800, 3300, 3700, 2900, 
    4200, 95100, 250000, 79000, 5800, 5300, 55700, 6300,
    48000, 87200, 89500, 8000, 7700, 77800, 8700, 47000,
    9500, 10000, 10500, 11000, 11500, 12000 
};

int mesesCesantia[30] = {
    2, 5, 8, 1, 4, 7, 3, 6, 9, 12,
    15, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 1, 2, 62, 4, 5, 6, 24, 18
};

void calcularEstadisticas(const vector<int>& grupo, double salarioMensual[]) {
    int indiceMax = grupo[0];
    int indiceMin = grupo[0];
    double suma = 0;

    for (int i : grupo) {
        suma += salarioMensual[i];

        if (salarioMensual[i] > salarioMensual[indiceMax]) {
            indiceMax = i;
        }
        if (salarioMensual[i] < salarioMensual[indiceMin]) {
            indiceMin = i;
        }
    }

    double promedio = suma / grupo.size();

    cout << "\nPersona con el salario máximo: " << nombre[indiceMax] << " ($" << salarioMensual[indiceMax] << ")";
    cout << "\nPersona con el salario mínimo: " << nombre[indiceMin] << " ($" << salarioMensual[indiceMin] << ")";
    cout << "\nSalario Promedio del grupo: $" << fixed << setprecision(2) << promedio << "\n";
}

void imprimirGrupo(const vector<int>& grupo, const string& titulo, double impuestoAnual[], double salarioNeto[], double salarioMensual[]) {
    if (grupo.empty()) return;

    cout << "\n====================================\n";
    cout << " " << titulo << "\n";
    cout << "====================================\n";
    cout << "| Nombre       | Salario Anual | Salario Mensual | Impuesto Anual | Impuesto Mensual | Salario Neto  |\n";
    cout << "-----------------------------------------------------------------------------------------------------\n";

    for (int i : grupo) {
        cout << "| " << setw(11) << left << nombre[i] << " | $"
             << setw(12) << right << fixed << setprecision(2) << salarioMensual[i] * 12 << " | $"
             << setw(14) << salarioMensual[i] << " | $"
             << setw(13) << impuestoAnual[i] << " | $"
             << setw(15) << impuestoAnual[i] / 12 << " | $"
             << setw(12) << salarioNeto[i] << " |\n";
    }
    cout << "-----------------------------------------------------------------------------------------------------\n";
    calcularEstadisticas(grupo, salarioMensual);
}

int main() {
    double impuestoAnual[30], salarioNeto[30];
    vector<int> grupo1, grupo2, grupo3, grupo4;

    for (int i = 0; i < 30; i++) {
        double salarioAnual = salarioMensual[i] * 12;

        if (salarioAnual <= 499999) {
            impuestoAnual[i] = 0;
            grupo1.push_back(i);
        } else if (salarioAnual <= 749999) {
            impuestoAnual[i] = (salarioAnual - 500000) * 0.15;
            grupo2.push_back(i);
        } else if (salarioAnual <= 999999) {
            impuestoAnual[i] = ((salarioAnual - 750000) * 0.20) + 37500;
            grupo3.push_back(i);
        } else {
            impuestoAnual[i] = ((salarioAnual - 1000000) * 0.25) + 87500;
            grupo4.push_back(i);
        }

        salarioNeto[i] = salarioMensual[i] - (impuestoAnual[i] / 12);
    }

    imprimirGrupo(grupo1, "Grupo 1: Salario Anual ≤ 499,999", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupo2, "Grupo 2: Salario Anual entre 500,000 y 749,999", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupo3, "Grupo 3: Salario Anual entre 750,000 y 999,999", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupo4, "Grupo 4: Salario Anual ≥ 1,000,000", impuestoAnual, salarioNeto, salarioMensual);

    vector<int> grupoC1, grupoC2, grupoC3, grupoC4;
    for (int i = 0; i < 30; i++) {
        int meses = mesesCesantia[i];
        if (meses >= 3 && meses <= 6) {
            grupoC1.push_back(i);
        } else if (meses > 6 && meses <= 12) {
            grupoC2.push_back(i);
        } else if (meses > 12 && meses <= 60) {
            grupoC3.push_back(i);
        } else if( meses > 60){
            grupoC4.push_back(i);
        }
    }

    imprimirGrupo(grupoC1, "Grupo Cesantía 1: 3-6 meses", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupoC2, "Grupo Cesantía 2: 7-12 meses", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupoC3, "Grupo Cesantía 3: 1 - 5 años", impuestoAnual, salarioNeto, salarioMensual);
    imprimirGrupo(grupoC4, "Grupo Cesantía 4: más de 5 años", impuestoAnual, salarioNeto, salarioMensual);

    return 0;
}