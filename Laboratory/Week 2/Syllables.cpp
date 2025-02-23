#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string abiertas = "aeo";
string cerradas = "iu";

bool validate(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool esVocal(char c)
{
    c = tolower(c);
    return (abiertas.find(c) != string::npos || cerradas.find(c) != string::npos);
}

vector<string> split(const string& s)
{
    vector<string> res;
    string temp;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            if (!temp.empty())
                res.push_back(temp);
            temp = "";
        }
        else if (validate(ch))
        {
            temp += ch;
        }
    }
    if (!temp.empty())
        res.push_back(temp);
    return res;
}

int seekNextVowel(const string& s, int i)
{
    for (i += 1; i < s.size(); i++)
    {
        if (esVocal(s[i]))
            return i;
    }
    return -1;
}

vector<string> divide(const string& s)
{
    vector<string> res;
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        temp += s[i];
        bool abierta = (abiertas.find(tolower(s[i])) != string::npos);
        bool cerrada = (cerradas.find(tolower(s[i])) != string::npos);
        if (abierta || cerrada)
        {
            // Si es la última letra, se agrega lo acumulado y se termina.
            if (i == s.size() - 1)
            {
                res.push_back(temp);
                return res;
            }
            if (abierta && (abiertas.find(tolower(s[i + 1])) != string::npos))
            {
                res.push_back(temp);
                temp = "";
            }
            else if (cerrada && (cerradas.find(tolower(s[i + 1])) != string::npos))
            {
                if (tolower(s[i]) == tolower(s[i + 1]))
                {
                    res.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += s[++i];
                    res.push_back(temp);
                    temp = "";
                }
            }
            else
            {
                int j = seekNextVowel(s, i);
                if (j == -1) {
                    // No hay más vocales en el resto de la palabra.
                    res.push_back(temp + s.substr(i + 1));
                    return res;
                }
                int gap = j - i - 1;
                switch (gap)
                {
                case 1:
                    res.push_back(temp);
                    temp = "";
                    if (i + 1 < s.size())
                        temp += s[++i];
                    break;
                case 2:
                    if (i + 2 < s.size() && (s[i + 2] == 'l' || s[i + 2] == 'r' || (s[i + 1] == 'c' && s[i + 2] == 'h')))
                    {
                        res.push_back(temp);
                        temp = "";
                        if (i + 1 < s.size())
                            temp += s[++i];
                        if (i + 1 < s.size())
                            temp += s[++i];
                    }
                    else
                    {
                        if (i + 1 < s.size())
                            temp += s[++i];
                        res.push_back(temp);
                        temp = "";
                        if (i + 1 < s.size())
                            temp += s[++i];
                    }
                    break;
                case 3:
                    if (i + 3 < s.size() && (s[i + 3] == 'l' || s[i + 3] == 'r'))
                    {
                        if (i + 1 < s.size()) temp += s[++i];
                        res.push_back(temp);
                        temp = "";
                        if (i + 1 < s.size()) temp += s[++i];
                        if (i + 1 < s.size()) temp += s[++i];
                    }
                    else
                    {
                        if (i + 1 < s.size()) temp += s[++i];
                        if (i + 1 < s.size()) temp += s[++i];
                        res.push_back(temp);
                        temp = "";
                        if (i + 1 < s.size()) temp += s[++i];
                    }
                    break;
                case 4:
                    if (i + 1 < s.size()) temp += s[++i];
                    if (i + 1 < s.size()) temp += s[++i];
                    res.push_back(temp);
                    temp = "";
                    if (i + 1 < s.size()) temp += s[++i];
                    if (i + 1 < s.size()) temp += s[++i];
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (!temp.empty())
        res.push_back(temp);
    return res;
}

void printVector(const vector<string>& v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << '-';
    }
    cout << v.back() << endl;
}

int main() {
    string s;
    cout << "Introduzca una frase: ";
    getline(cin, s);
    auto frase = split(s);

    for (auto& word : frase)
    {
        printVector(divide(word));
    }
    return 0;
}