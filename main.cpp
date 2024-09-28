/*
    Longest Common Substring Algorithm.
    Author: Owen Walstrom
    Date: 9/28/2024
    
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonSubstring(string str1,string str2) {
    int string1Length = str1.length();
    int string2Length = str2.length();

    vector<vector<int>> table(string1Length + 1, vector<int>(string2Length + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= string1Length; i++) {
        for (int j = 1; j <= string2Length; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i;
                }
            }
             cout << table[i][j] << ", ";
        }
        cout << "\n";
    }

    return str1.substr(endIndex - maxLength, maxLength);
}

int main() {
    string str1 = "afholycowasfhafah";
    string str2 = "rholycow123456789";

    string output = longestCommonSubstring(str1, str2);

    cout << "Longest Common Substring: " << output << endl;

    return 0;
}


/*
attempt 2

#include <iostream>
#include <string>

using namespace std;

void longestCommonSubstring(string string1, string string2){
    int string1Length = string1.length();
    int string2Length = string2.length();
    
    //cout << string1Length << " : " << string2Length;
    //Create a 2D table to store the lengths of common substrings.
    int table[string1Length + 1][string2Length + 1];
    int maxLength = 0; //To keep track of the length of the longest common substring
    int endIndex = 0; //To keep track of the ending index of the longest common substring

    //Fill in the table using dynamic programming.
    for(int i = 1; i < string1Length; i++){
        for(int j = 1; j < string2Length; j++){
            if(string1[i-1] == string2[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
                if(table[i][j] > maxLength){
                    maxLength = table[i][j];
                    endIndex = i; // Update the ending index of the longest common substring
                }
            }else{
                table[i][j] = 0; // Reset the length to 0 for non-matching characters
            }
            cout << table[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "End Index: " << endIndex << " maxLength: " << maxLength << "\n";
    for(int i = (endIndex - maxLength); i <= endIndex; i++){
        cout << string1[i];
    }

}


int main() {
    longestCommonSubstring("abcs", "abdc");
    return 0;
}



/*
void printTable(int tableRows[]){
    string row;
    for(int i = 0; 1 < sizeof(tableRows); i++){
        row = " ";
        for(int j = 0; j < sizeof(tableRows[i]); j++){
            
            row += tableRows[i][j] + ", ";
        }
        row += "\n";
        cout << row
    
    }
}






ANotes

function longestCommonSubstring(string1, string2):
    m = length(string1)
    n = length(string2)
    # Create a 2D table to store the lengths of common substrings.
    # Initialize all values to 0.
    table = 2D array of size (m+1) x (n+1)
    maxLength = 0 # To keep track of the length of the longest common substring
    endIndex = 0 # To keep track of the ending index of the longest common substring
    # Fill in the table using dynamic programming.
    for i from 1 to m:
        for j from 1 to n:
            if string1[i-1] == string2[j-1]:
                table[i][j] = table[i-1][j-1] + 1
                if table[i][j] > maxLength:
                    maxLength = table[i][j]
                    endIndex = i # Update the ending index of the longest common substring
            else:
                table[i][j] = 0 # Reset the length to 0 for non-matching characters
    # Extract the longest common substring from the table.
    longestCommonSubstr = substring of string1 from (endIndex - maxLength) to endIndex

    return longestCommonSubstr





*/

