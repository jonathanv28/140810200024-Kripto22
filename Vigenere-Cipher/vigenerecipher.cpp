#include <iostream>
#include<windows.h>
using namespace std;

string encrypt(string text, string key) {
    string encrypted;

    for(int i=0; i< text.length(); i++) {
        int indexEncrypted;
        int j = i%key.length();

        if((int)text[i] == 32) {
            indexEncrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  // untuk jika alfabet kecil
            if((int)key[j] >= 97 && (int)key[j] <= 122){
                indexEncrypted = (int)text[i] + (int)key[j] - 97;
            }else if((int)key[j] >= 65 && (int)key[j] <= 90){
                indexEncrypted = (int)text[i] + (int)key[j] - 65;
            }
            if(indexEncrypted > 122) {
                indexEncrypted -= 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  // untuk jika alfabet kapital
            if((int)key[j] >= 97 && (int)key[j] <= 122){
                indexEncrypted = (int)text[i] + (int)key[j] - 97;
            }else if((int)key[j] >= 65 && (int)key[j] <= 90){
                indexEncrypted = (int)text[i] + (int)key[j] - 65;
            }
            if(indexEncrypted > 90) {
                indexEncrypted -= 26;
            }
        }
        encrypted += (char)indexEncrypted;
    }

    return encrypted;
}

string decrypt(string text, string key) {
    string decrypted;

    for(int i=0; i< text.length(); i++) {
        int indexDecrypted;
        int j = i%key.length();

        if((int)text[i] == 32) {
            indexDecrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  // untuk jika alfabet kecil
            if((int)key[j] >= 97 && (int)key[j] <= 122){
                indexDecrypted = (int)text[i] - (int)key[j] + 97;
            }else if((int)key[j] >= 65 && (int)key[j] <= 90){
                indexDecrypted = (int)text[i] - (int)key[j] + 65;
            }
            if(indexDecrypted < 97) {
                indexDecrypted += 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  // untuk jika alfabet kapital
            if((int)key[j] >= 97 && (int)key[j] <= 122){
                indexDecrypted = (int)text[i] - (int)key[j] + 97;
            }else if((int)key[j] >= 65 && (int)key[j] <= 90){
                indexDecrypted = (int)text[i] - (int)key[j] + 65;
            }
            if(indexDecrypted < 65) {
                indexDecrypted += 26;
            }
        }
        decrypted += (char)indexDecrypted;
    }

    return decrypted;
}

int main() {
    string text, key;

    cout << "====PROGRAM VIGENERE CIPHER====";
    cout << "\nMasukkan text : ";
    getline(cin, text);

    cout << "Masukkan kunci : ";
    getline(cin, key);

    cout << "\nEncrypted Text : ";
    cout << encrypt(text, key) << endl;

    cout << "Decrypted Text : ";

    cout << decrypt(encrypt(text, key), key) << endl;

}