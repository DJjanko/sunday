#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "vector"
using namespace std;

ofstream out;

string inputText(const string &pot) {
    ifstream input(pot);
    stringstream sstream;

    if (!input.is_open()) {
        return string();
    }

    sstream << input.rdbuf();
    return sstream.str();
}

void izpis_KMPnext(const int* polje, int len) {
    for (int i = 0; i < len; ++i) {
        out << polje[i] << ' ';
    }
    out << endl;
}

void KMP(const string& text, const string& vzorec) {
    /*
     * implementacija algoritma KMP
     * za izpis polja KMPnext lahko uporabite funkcijo izpis_KMPnext
     * Za izpis navidezne spremenljivke index uporabite: out << index << ' ';
     */
}

void Sunday(const string& text, const string& vzorec){

}

int main(int argc, const char *const argv[]) {
    if (argc != 4) {
        return -1;
    }

    string text = inputText(argv[3]);
    string vzorec = argv[2];
    out.open("out.txt");

    if (!out) {
        return -2;
    }

    if (argv[1][0] == '0') {
        KMP(text, vzorec);
    }
    else {
        Sunday(text,vzorec);
    }


    return 0;
}
