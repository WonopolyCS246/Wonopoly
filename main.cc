#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "grid.h"

using namespace std;

int main(int argc, char **argv){
    if (argc == 1) { //./monopoly
        Grid g;
        g.play();
    } else if (argc == 2) { // ./monopoly -testing
        istringstream ss{argv[1]};
        string s;
        ss >> s;
        if (s == "-testing") {
            // Do whatever the testing flag means
            //Grid g;
            //g.play();
            cout << " testing " << endl;
        } else {
            cout << "Format: ./monopoly -load file -testing" << endl;
            cout << "You can omit either -load file and/or -testing" << endl;
            return 1;
        }
    } else if (argc == 3) { // ./monopoly -load file
        istringstream ss{argv[1]};
        string s;
        ss >> s;
        if (s == "-load") {
            istringstream ss1{argv[2]};
            string s1;
            ss1 >> s1;
            cout << " ./monopoly -load file "<< argv[2] << endl;
            //Grid g{ifstream{s1}};
            //g.play();
        }  else {
            cout << "Format: ./monopoly -load file -testing" << endl;
            cout << "You can omit either -load file and/or -testing" << endl;
            return 1;
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
            //Grid g{ifstream{s1}};
            //g.play();
            cout << "-loading and -testing" << endl;
            // do whatever the -testing flag means
        } else {
            cout << "Format: ./monopoly -load file -testing" << endl;
            cout << "You can omit either -load file and/or -testing" << endl;
            return 1;
        }
    } else {
        cout << "Format: ./monopoly -load file -testing" << endl;
        cout << "You can omit either -load file and/or -testing" << endl;
        return 1;
    }
    return 0;
}
