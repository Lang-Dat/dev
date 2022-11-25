/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 48:08:08
**/
#include <testlib/testlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
const std::string NAME = "BAI4";
const int MAX_COL = 5;
int T = 10, range = 5;

void generator(int range) {
    ofstream file;
    file.open(NAME + ".INP");
    int n = rnd.next(1, range);
    file << n << "\n";
    for (int i = 0; i < n; i++)
        file << rnd.next(-50, 50) << " ";
    file << "\n";
    file.close();
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    system("chcp 65001"); // to accecpt unicode
    system("clear");
    int T = atoi(argv[1]);
    int range = atoi(argv[2]);
    for (int i = 1; i <= T; i++) {
        generator(range);

        system(string(NAME + ".exe").c_str());
        system(string(NAME + "_trau.exe").c_str());
        if (system(string("diff " + NAME + ".OUT " + NAME + "_trau.OUT").c_str()) == 1)
            quitf(_wa, "");
        std::cout << "\033[32mTest " << setw(2) <<  i << ":✅\t";
    
        if (i % MAX_COL == 0)
            std::cout << "\n";
    }

    std::cout << "\n\t\t\t\033[93mThe test passed";
}