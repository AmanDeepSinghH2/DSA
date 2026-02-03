#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    int l = 0;
    int h = str.length() - 1;
    while (h > l) {
        if (str[l++] != str[h--]) {
            return false;
        }
    }
    return true;
}

void countVowelsConsonants(string str) {
    int vowels = 0, consonants = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

int main() {
    string str = "Hello World";
    cout << "String: " << str << endl;
    
    countVowelsConsonants(str);

    string str2 = str;
    reverse(str2.begin(), str2.end());
    cout << "Reversed: " << str2 << endl;

    string pal = "madam";
    if(isPalindrome(pal)) cout << pal << " is a palindrome." << endl;
    else cout << pal << " is NOT a palindrome." << endl;

    return 0;
}
