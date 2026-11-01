#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {

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

    return 0;
}