#include <iostream>
#include <vector>
using namespace std;

void longestSequence(int length1, int length2, string chain1, string chain2, vector<vector<int>> &dp){

    for (int i = 1; i <= length1; i++){

        for (int j = 1; j <= length2; j++){
            
            if (chain1[i - 1] == chain2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

string showSubsequence(string &chain1, string &chain2, vector<vector<int>> dp)
{
    int i = chain1.length(), j = chain2.length();
    string chain = "";

    do
    {
        if (chain1[i - 1] == chain2[j - 1])
        {
            chain = chain1[i - 1] + chain;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }while(i > 0 && j > 0);

    return chain;
}

int main(){
    
    string chain1, chain2, subsequence;
    int length1, length2;

    cout << "Inserte la cadena 1: ";
    cin >> chain1;
    length1 = chain1.length();

    cout << "Inserte la cadena 2: ";
    cin >> chain2;
    length2 = chain2.length();

    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

    longestSequence(length1, length2, chain1, chain2, dp);
   
    subsequence = showSubsequence(chain1, chain2, dp);
    cout << "\nLa subsecuencia mas larga es: " << subsequence << ", el número más alto de coincidencias es: " << dp[length1][length2];
}