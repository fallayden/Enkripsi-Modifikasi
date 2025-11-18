#include <iostream>
#include <string>
using namespace std;

// Fungsi enkripsi pemampatan
string compressEncrypt(const string& plaintext) {
    string mainText = "";
    string removedChars = "";

    for (size_t i = 0; i < plaintext.length(); ++i) {
        if ((i + 1) % 6 == 0) {
            removedChars += plaintext[i]; // karakter ke-6, ke-12, dst.
        } else {
            mainText += plaintext[i];
        }
    }

    return mainText + "_" + removedChars;
}

int main() {
    string plaintext;

    cout << "Masukkan plaintext: ";
    getline(cin, plaintext);

    string encrypted = compressEncrypt(plaintext);

    cout << "\nPlaintext  : " << plaintext << endl;
    cout << "Encrypted (Pemampatan): " << encrypted << endl;

    return 0;
}
