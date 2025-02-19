#include <iostream>
using namespace std;
/*
bool checkLetter(string prompt, char letter){
    for(int i = 0; i < prompt.length(); i++){
        if(prompt[i] == )

    }

}
*/
bool isVowel(char letter, char vowels[]){
    for(int i = 0; i < 5; i++){
        if(letter == vowels[i] ){
            return true;
        }
    }
    return false;
}
bool checkConsonant(char letter, char consonants[]){
    for(int i = 0; i < 21; i++){
        if(letter == consonants[i] ){
            return true;
        }
    }
    return false;
}

int main(){
    string prompt, sum;
    char blankSpace = ' ';
    char vowels[] = {'a', 'e', 'i','o','u'};
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n',
                         'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

    cout << "Ingrese la frase a separar en silabas: ";
    //getline(cin, prompt);

    for (int i = 0; i < prompt.length(); i++)
    {
        cout << prompt[i] << " : " << prompt[i + 1] << endl;

        if (checkConsonant(prompt[i], consonants) && prompt[i + 1] == blankSpace)
        {
            sum += prompt[i];
        }
        else if (isVowel(prompt[i],vowels))
        {
            sum += prompt[i];
            sum += "-";
        }
        else
        {
            sum += prompt[i];
        }
    }
    cout << sum << endl;
}