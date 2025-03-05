#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    
    string prompt;
    char character;
    int count = 0;
    getline(cin,prompt);
    cin >> character;

    map<char,int> frequency;

    for(char c : prompt){
        if(c == character){
            count++;
        }
        c = tolower(c);
        frequency[c]++; 
    }

    for(auto pair : frequency){
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\n\nEl caracter se repite " << count << " veces";
}