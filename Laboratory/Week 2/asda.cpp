#include <iostream>
#include <string>
using namespace std;


void initializeLettersArray(string prompt, char letters[]){
    for(int i = 0; i < prompt.length() ; i++ ){
        letters[i] = prompt[i];
    }

}

bool checkLetters(char letters[], string prompt){
    bool exists = false;
    for(int i = 0; i < prompt.length() ; i++ ){
        if(letters[i] == prompt[i]){
            exists = true;
            return;
        }    
        letters[i+1];
    }
    return exists;
}



int countChar(string prompt, string letters[]){
    int length = prompt.length();
    for(int i = 0; i < length ; i++ ){
        cout << prompt[i]<< "\n";
        if(checkLetters){

        }
        
    }
    return 0;

}

int main(){
string prompt;
char letters[];

    cout << "Please indicate the prompt to count the letters: ";
    getline(cin,prompt);

    initializeLettersArray(prompt, letters);
    countChar(prompt);
   

}