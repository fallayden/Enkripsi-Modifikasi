#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Fungsi enkripsi permutasi blok 4 karakter (urutan 1234 → 4321)
string permuteEncrypt(const string& plaintext, const vector<int>& permutation) {
    string cleanedText = "";
    for (char c : plaintext) {
        cleanedText += (c == ' ') ? '_' : c; // ganti spasi dengan underscore
    }

    // Tambahkan padding '_' jika panjang tidak kelipatan 4
    while (cleanedText.length() % 4 != 0) {
        cleanedText += '_';
    }

    string ciphertext = "";
    for (size_t i = 0; i < cleanedText.length(); i += 4) {
        string block = cleanedText.substr(i, 4);
        for (int pos : permutation) {
            ciphertext += block[pos - 1]; // posisi 1-based
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    vector<int> permutation = {4, 3, 2, 1}; // FIX: permutasi 4321

    cout << "Masukkan plaintext: ";
    getline(cin, plaintext);

    string encrypted = permuteEncrypt(plaintext, permutation);

    cout << "\nPlaintext  : " << plaintext << endl;
    cout << "Encrypted (Permutasi 4321): " << encrypted << endl;

    return 0;
}
