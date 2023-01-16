/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 02:42:19
**/
#include <testlib/testlib.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;

const std::string NAME  = "SO";
const std::string FILE_IN  = NAME + ".INP";
const std::string WHITE = "\033[37m", 
                  GREEN = "\033[32m",
                  RED   = "\033[31m";

static const int MAX_COL = 3;
int T = 10, range = 5;

void generator(int range) {
    ofstream file;
    file.open(FILE_IN);
    file << rnd.next(1, range);
    file.close();
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    system("clear");
    
    int T = atoi(argv[1]);
    int range = atoi(argv[2]);

    for (int i = 1; i <= T; i++) {
        generator(range);

        system(string(NAME + "_trau.exe").c_str());

        auto start = high_resolution_clock::now();
        system(string(NAME + ".exe").c_str());
        auto end = high_resolution_clock::now();
        duration<double, std::milli> elapsed = end - start;
        double time = elapsed.count() / 1000;

        if (system(string("cmp " + NAME + ".OUT " + NAME + "_trau.OUT").c_str()) == 1) {
            cout << "Input:\n";
            system(string("cat " + FILE_IN).c_str());
            quitf(_wa, "Answer is diffrencent");
        }
        
        cout << WHITE << "Test case " << setw(2) << i << ": "; 
        if (time >= 1.) {
            string command("cp " + FILE_IN + " TLE/" + to_string(i) + "-[" + to_string(time) + "]" + FILE_IN);
            system(command.c_str());
            cout << RED << "TLE";
        } else {
            cout << GREEN << "AC";
        }
        cout << WHITE << " [" << time << "s]" << "\t";
        if (i % MAX_COL == 0) cout << "\n";
    }

    cout << "\n\t\t\t\t\t\033[93mThe test passed";
}