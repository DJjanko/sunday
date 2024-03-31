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
    int* kmp_next = new int[vzorec.size()];
    cout << "size: " << vzorec.size() << endl;
    for(int i = 0; i< vzorec.size(); i++){
        kmp_next[i] = 0;
    }

    for(int i= 0; i < vzorec.size(); i++){
        if(i == 0) kmp_next[i] = -1;
        else if(i == 1) kmp_next[i] = 0;
        else if (i >= 2){
            int temp_size = i-1;
            for(int j = 0; j < i; j++){

                if(temp_size == 0){
                    kmp_next[i] = 0;

                    cout << "----------------" << endl;
                    cout << "index: "<< i << endl;
                    cout << "size: "<< temp_size << endl;
                    cout << "s1: " << endl;
                    cout << "s2: " << endl;
                    cout << "----------------" << endl;
                    
                    break;
                }
                string s1 = "";
                string s2 = "";
                for(int k = 0 ; k < temp_size; k++){
                    s1 = s1 + vzorec[k];
                }
                int counter = 0;
                for(int k = i-1; k > 0 && counter < temp_size;k--){
                    s2 =vzorec[k] + s2 ;
                    counter ++;
                }

                if(s1 == s2){
                    kmp_next[i] = s1.size();

                    cout << "----------------" << endl;
                    cout << "index: "<< i << endl;
                    cout << "size: "<< temp_size << endl;
                    cout << "s1: " << s1 << endl;
                    cout << "s2: " << s2 << endl;
                    cout << "----------------" << endl;
                    
                    break;
                }
                temp_size--;
            }
        }
    }
    cout << "----------------" << endl;
    for(int i= 0; i < vzorec.size(); i++){
        cout << kmp_next[i] << " " ;
    }
    cout <<endl << "----------------" << endl;
    

    for(int i = 0; i< text.size() - vzorec.size();){
        for(int j = 0; j < vzorec.size();j++){

            if(text[i+j] != vzorec[j]){
                i = i + (j - kmp_next[j]);
                break;
            }else{
                if(j == vzorec.size()-1){
                    out << i << ' ';
                    out.flush();
                    i += vzorec.size();
                    break;
                }
            }

        }
    }
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
