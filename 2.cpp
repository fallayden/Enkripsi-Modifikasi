#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Fungsi enkripsi dengan metode blocking vertikal → horizontal
string blockEncrypt(const string& plaintext, int blockSize) {
    // Ganti spasi dengan underscore sebelum diproses
    string cleanedText = "";
    for (char c : plaintext) {
        cleanedText += (c == ' ') ? '_' : c;
    }

    int length = cleanedText.length();
    int rows = (length + blockSize - 1) / blockSize; // pembulatan ke atas

    // Inisialisasi tabel blok
    vector<vector<char>> table(rows, vector<char>(blockSize, '_'));

    // Isi tabel secara vertikal per kolom
    int index = 0;
    for (int col = 0; col < blockSize; ++col) {
        for (int row = 0; row < rows; ++row) {
            if (index < length) {
                table[row][col] = cleanedText[index++];
            }
        }
    }

    // Baca tabel secara horizontal per baris
    string ciphertext = "";
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < blockSize; ++col) {
            ciphertext += table[row][col];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    int blockSize = 5; // FIX = 5

    cout << "Masukkan plaintext: ";
    getline(cin, plaintext);

    string encrypted = blockEncrypt(plaintext, blockSize);

    cout << "\nPlaintext  : " << plaintext << endl;
    cout << "Blocking (5): " << encrypted << endl;

    return 0;
}
