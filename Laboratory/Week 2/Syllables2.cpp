#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

char toLowerChar(char c) {
    return static_cast<char>(tolower(c));
}

bool isVowel(char c) {
    c = toLowerChar(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'á' || c == 'é' || c == 'í' || c == 'ó' || c == 'ú' || c == 'ü');
}

bool isAccented(char c) {
    c = toLowerChar(c);
    return (c == 'á' || c == 'é' || c == 'í' || c == 'ó' || c == 'ú');
}

bool formsDiphthong(char v1, char v2) {
    v1 = toLowerChar(v1);
    v2 = toLowerChar(v2);
    bool v1Weak = (v1 == 'i' || v1 == 'u') && !isAccented(v1);
    bool v2Weak = (v2 == 'i' || v2 == 'u') && !isAccented(v2);
    if (v1Weak && v2Weak) return true;
    if ((v1Weak && !isAccented(v1)) && !v2Weak) return true;
    if ((v2Weak && !isAccented(v2)) && !v1Weak) return true;
    return false;
}


bool isPermissibleOnset(const string& cluster) {
    const vector<string> onsets = { "bl", "br", "cl", "cr", "dr", "fl", "fr",
                                   "gl", "gr", "pl", "pr", "tr" };
    for (const auto& onset : onsets) {
        if (cluster == onset)
            return true;
    }
    return false;
}

string syllabifyWord(const string& word, char separator = '-') {
    string lower;
    for (char c : word)
        lower.push_back(toLowerChar(c));

    vector<string> syllables;
    int i = 0;
    while (i < lower.size()) {
        string syllable = "";
        while (i < lower.size() && !isVowel(lower[i])) {
            syllable.push_back(lower[i]);
            i++;
        }
        if (i < lower.size() && isVowel(lower[i])) {
            syllable.push_back(lower[i]);
            i++;
            while (i < lower.size() && isVowel(lower[i])) {

                if (!syllable.empty() && formsDiphthong(syllable.back(), lower[i])) {
                    syllable.push_back(lower[i]);
                    i++;
                }
                else {
                    break;
                }
            }
        }

        string followingCons = "";
        int j = i;
        while (j < lower.size() && !isVowel(lower[j])) 
        {
            followingCons.push_back(lower[j]);
            j++;
        }
        if (j == lower.size()) {
            syllable += followingCons;
            i = j;
        }
        else {
            if (followingCons.size() == 0) {

            }
            else if (followingCons.size() == 1) {

            }
            else {
                string two = followingCons.substr(0, 2);
                if (!isPermissibleOnset(two)) 
                {
                    syllable.push_back(followingCons[0]);
                    i++; 
                }
            }
        }

        syllables.push_back(syllable);
    }

    string result;
    for (size_t k = 0; k < syllables.size(); k++) {
        if (k > 0)
            result.push_back(separator);
        result += syllables[k];
    }
    return result;
}

string syllabifySentence(const string& sentence, char separator = '-') {
    istringstream iss(sentence);
    string word, output;
    bool first = true;
    while (iss >> word) {
        if (!first)
            output += " ";
        output += syllabifyWord(word, separator);
        first = false;
    }
    return output;
}

int main() {
    string input;
    getline(cin, input);
    
    cout << syllabifySentence(input) << endl;
}