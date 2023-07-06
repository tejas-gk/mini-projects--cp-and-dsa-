#include <iostream>
#include <string>

using namespace std;

string encryptCaesar(string message, int key) {
    string encryptedMessage;
    for (char c : message) {
        if (isalpha(c)) {
            char base = (islower(c)) ? 'a' : 'A';
            char encryptedChar = (c - base + key) % 26 + base;
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

string decryptCaesar(const string& encryptedMessage, int key) {
    return encryptCaesar(encryptedMessage, 26 - key);
}

int main() {
    string message;
    cout<<"Enter a message ";
    cin>>message;
    int key;
    cout<<"Enter shifts ";
    cin>>key;

    string encrypted = encryptCaesar(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    string decrypted = decryptCaesar(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
