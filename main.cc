#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "grid.h"

using namespace std;

int main(int argc, char **argv){
    bool chk = false;
    if (argc == 1) { // ./monopoly
        cout << "Welcome to Watopoly!" << endl;
        Grid g;
        g.play();
    } else if (argc == 2) { // ./monopoly -testing
        istringstream ss{argv[1]};
        string s;
        ss >> s;
        if (s == "-testing") {
            chk = true;
            // Do whatever the testing flag means
            cout << "Welcome to Watopoly!" << endl;
            Grid g;
            g.play();
        }
    } else if (argc == 3) { // ./monopoly -load file
        istringstream ss{argv[1]};
        string s;
        ss >> s;
        if (s == "-load") {
            chk = true;
            istringstream ss1{argv[2]};
            string s1;
            ss1 >> s1;
            cout << "Welcome to Watopoly!" << endl;
            Grid g{ifstream{s1}};
            g.play();
        }
    } else if (argc == 4) { // ./monopoly -load file -testing
        istringstream ss{argv[1]};
        string s;
        ss >> s;
        istringstream ss1{argv[2]};
        string s1;
        ss1 >> s1;
        istringstream ss2{argv[3]};
        string s2;
        ss2 >> s2;
        if (s == "-load" && s2 == "-testing") {
            cout << "Welcome to Watopoly!" << endl;
            chk = true;
            Grid g{ifstream{s1}};
            g.play();
            // do whatever the -testing flag means
        } else if (s == "-testing" && s1 == "-load") {
            cout << "Welcome to Watopoly!" << endl;
            chk = true;
            Grid g{ifstream{s2}};
            g.play();
        }
    } 
    if (!chk) {
        cout << "Format: ./watopoly -load file -testing" << endl;
        cout << "You can omit either -load file and/or -testing" << endl;
        return 1;
    }
    return 0;
}
