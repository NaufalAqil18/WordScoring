#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    // function 1
    ifstream file("example.txt");
    string text;
    stringstream buffer;

    if(file.is_open()) {
        buffer << file.rdbuf();
        text = buffer.str();
        // cout << text;

        file.close();
    } else {
        cout << "Gagal membuka file" << endl;
    }

    // function 2
    string preproces = "";
    bool lastSpace = false;
    for (char c : text) {
        if(ispunct(c) || c == '\n') {
            if (c == '\n' || c == '-') {
                c = ' ';
            } else {
                continue;
            }
        }
        c = tolower(c);

        // mengecek apakah char sebelumnya adalah ' '
        if (c == ' ') {
            if(lastSpace) {
                continue;
            }
            lastSpace = true;
        }
        else {
            lastSpace = false;
        }

        preproces += c;
    }
    cout << preproces;

    return 0;
}