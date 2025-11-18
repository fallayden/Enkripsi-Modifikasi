#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Fungsi untuk mengecek apakah huruf vokal
bool isVowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';
}

// Fungsi enkripsi ekspansi per kata
string expandEncrypt(const string& plaintext) {
    stringstream ss(plaintext);
    string word;
    string result = "";

    while (ss >> word) {
        if (word.length() == 0) continue;

        char first = word[0];
        string rest = word.substr(1);

        if (isVowel(first)) {
            result += rest + first + "Y ";
        } else {
            result += rest + first + "X ";
        }
    }

    // Hapus spasi terakhir
    if (!result.empty()) result.pop_back();
    return result;
}

int main() {
    string plaintext;

    cout << "Masukkan plaintext: ";
    getline(cin, plaintext);

    string encrypted = expandEncrypt(plaintext);

    cout << "\nPlaintext  : " << plaintext << endl;
    cout << "Encrypted (Ekspansi): " << encrypted << endl;

    return 0;
}
