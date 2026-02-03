#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function for Naive String Matching
void search(string pattern, string text) {
    int m = pattern.length();
    int n = text.length();

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    bool found = false;
    // Iterate through the text
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Check for pattern match at current index i
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If pattern matches successfully
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Pattern not found in text." << endl;
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    
    search(pattern, text);
    
    return 0;
}
