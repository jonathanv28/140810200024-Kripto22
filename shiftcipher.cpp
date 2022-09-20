#include <iostream>
#include<windows.h>
using namespace std;


string encrypt(string text, int key) {
    string encrypted;

    for(int i=0; i< text.length(); i++) {
        int indexEncrypted;

        if((int)text[i] == 32) {
            indexEncrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  // Untuk alfabet non-kapital
            indexEncrypted = (int)text[i] + key;
            if(indexEncrypted > 122) {
                indexEncrypted -= 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  // Untuk alfabet kapital
            indexEncrypted = (int)text[i] + key;
            if(indexEncrypted > 90) {
                indexEncrypted -= 26;
            }
        }
        encrypted += (char)indexEncrypted;
    }
    return encrypted;
}


void decrypt(string text, int key) {
    string decrypted;

    for(int i=0; i< text.length(); i++) {
        int indexDecrypted;

        if((int)text[i] == 32) {
            indexDecrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  // Untuk alfabet non-kapital
            indexDecrypted = (int)text[i] - key;
            if(indexDecrypted > 122) {
                indexDecrypted += 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  // Untuk alfabet kapital
            indexDecrypted = (int)text[i] - key;
            if(indexDecrypted > 90) {
                indexDecrypted += 26;
            }
        }
        decrypted += (char)indexDecrypted;
    }
    cout << decrypted << endl;
}

int main() {
    string text;
    int key;

    cout << "====PROGRAM SHIFT CIPHER====";
    cout << "\nMasukkan text : ";
    getline(cin, text);

    cout << "Masukkan kunci : ";
    cin >> key;

    cout << "\nEncrypted Text : ";
    cout << encrypt(text, key) << endl;

    cout << "Decryption : ";
    decrypt(encrypt(text, key),key);
}