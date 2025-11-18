#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengenkripsi teks menggunakan Caesar Cipher
string caesarEncrypt(const string& text, int shift) {
    string result = "";

    for (char c : text) {
        if (isupper(c)) {
            result += char((c - 'A' + shift) % 26 + 'A');
        } else if (islower(c)) {
            result += char((c - 'a' + shift) % 26 + 'a');
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    string plaintext;
    int shift = 3;

    cout << "Masukkan plaintext: ";
    getline(cin, plaintext);

    string encrypted = caesarEncrypt(plaintext, shift);

    cout << "\nPlaintext  : " << plaintext << endl;
    cout << "Ciphertext : " << encrypted << endl;

    return 0;
}
