/**
 *	author: Lang Dat
 *	create: 02.11.2022 32.15.08
**/
#include <testlib/testlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
const std::string NAME = "UOC";
const int MAX_COL = 5;
int T = 10, range = 500;

void generator(int range) {
    ofstream file;
    file.open(NAME + ".INP");
    int n = rnd.next(range);
    file << n << "\n";
    for (int i = 0; i < n; i++)
        file << rnd.next(1, 1000) << " ";
    file << "\n";
    file.close();
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    system("chcp 65001"); // to accecpt unicode
    system("clear");
    // int T = atoi(argv[1]);
    // int range = atoi(argv[2]);
    for (int i = 1; i <= T; i++) {
        generator(range);
        
        system(string(NAME + ".exe").c_str());
        system(string(NAME + "_trau.exe").c_str());
        if (system(string("diff " + NAME + ".OUT " + NAME + "_trau.OUT").c_str()) == 1)
            quitf(_wa, "\nThe sum is wrong");
        std::cout << "\033[32mTest " << setw(2) <<  i << ": ✅\t";
    
        if (i % MAX_COL == 0)
            std::cout << "\n";
    }

    std::cout << "\n\t\t\033[93mThe test passed";
}