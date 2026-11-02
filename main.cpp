#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
struct structKata {
    double skor;
    // int jumlahKata;
    int panjangKata;
    string kata;
};

double ScribbleSkor(char huruf) {
    switch (huruf)
    {
    case 'a':
        return 1.0;
    case 'b':
        return 3.0;
    case 'c':
        return 3.0;
    case 'd':
        return 2.0;
    case 'e':
        return 1.0;
    case 'f':
        return 4.0;
    case 'g':
        return 2.0;
    case 'h':
        return 4.0;
    case 'i':
        return 1.0;
    case 'j':
        return 8.0;
    case 'k':
        return 5.0;
    case 'l':
        return 1.0;
    case 'm':
        return 3.0;
    case 'n':
        return 1.0;
    case 'o':
        return 1.0;
    case 'p':
        return 3.0;
    case 'q':
        return 10.0;
    case 'r':
        return 1.0;
    case 's':
        return 1.0;
    case 't':
        return 1.0;
    case 'u':
        return 1.0;
    case 'v':
        return 4.0;
    case 'w':
        return 4.0;
    case 'x':
        return 8.0;
    case 'y':
        return 4.0;
    case 'z':
        return 10.0;
    default:
        break;
    }
};

structKata struckMaker(string kata) {
    structKata kataDalamStruct;
    kataDalamStruct.skor = 0.0;
    for(char c : kata) {
        kataDalamStruct.skor += ScribbleSkor(c);
    }
    kataDalamStruct.panjangKata = kata.length();
    kataDalamStruct.kata = kata;
    return kataDalamStruct;
}

string readFile(string fileTxt) {
    // function 1 membaca file
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
    return text;
}

string preprocesText(string textAfterReadFile) {
    string preproces = "";
    bool lastSpace = false;
    for (char c : textAfterReadFile) {
        if(ispunct(c) || c == '\n' || isdigit(c)) {
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
    // cout << preproces;
    return preproces;
}

int main() {
    // function 1 membaca file
    string text = readFile("example.txt");

    // function 2 preprocess kata
    string preproces = preprocesText(text);

    // function 3 membuat struct dari setiap kata untuk menyimpan kata, panjangKata dan skor lalu memasukkan ke dalam array
    string word;
    vector<structKata> arr;

    stringstream ss(preproces);

    while(ss >> word){
        arr.push_back(struckMaker(word));
    }

    for (structKata kata : arr) {
        cout << kata.kata << " " << kata.panjangKata << " " << kata.skor << endl;
    }

    // function 4 menghimpun kata-kata dengan skor yang sama urut berdasarkan abjad

    // function 5 mengurutkan skor kata dari yang paling besar ke yang paling kecil (descending order)

    return 0;
}