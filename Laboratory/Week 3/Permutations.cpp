#include <iostream>
#include <set>
using namespace std;

bool thereAreRepetitions(set<char> set, string prompt){
    for(int i = 0; i < prompt.length(); i++){
        set.insert(prompt[i]);
    }
    if(set.size() != prompt.length()){
        cout << "Hay caracteres repetidos. Intenta de nuevo." << endl;
        return true;
    }
    return false;
}

void permutations(string& prompt, int left, int right){
    if(left == right){
        cout << prompt << endl;
    }

    for(int i = left; i <= right ; i++){
        swap(prompt[left],prompt[i]);
        permutations(prompt, left + 1, right);
        swap(prompt[left],prompt[i]);
    }
}

int main(){
    set<char> set{};
    string prompt;
    do{
        cout << "Ingrese una cadena: ";
        getline(cin,prompt);

    }while(thereAreRepetitions(set, prompt));
   
    permutations(prompt, 0, prompt.length() - 1);
}