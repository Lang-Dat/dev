#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using std::string;

const string NAME = "DOANCON";
std::string original, tmp, inPathStr, outPathStr, output;
std::ifstream inFile, inPath, outPath;

int main() {
    system("chcp 65001");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOANCON.OUT", "w", stdout);
    Timer time;
    inFile.open("./DOANCON.INP");
    std::getline(inFile, original, '\0');
    inFile.close();

    // system("where /r e:\\ DOANCON.INP > inpath.txt");
    // system("where /r d:\\ DOANCON.INP > inpath.txt");
    system("dir /AD /B /S e:\\ DOANCON | findstr \"DOANCON\" > inpath.txt");
    // inFile.open("inpath.txt");

    // while (getline(inFile, inPathStr)) {
    //     inPath.open(inPathStr);
    //     if (!inPath.is_open()) continue;
    //     std::getline(inPath, tmp, '\0');
    //     inPath.close();
    //     if (tmp == original) {
    //         outPathStr = inPathStr.substr(0, inPathStr.size() - 4) + ".OUT";
    //         outPath.open(outPathStr);
    //         if (!outPath.is_open()) continue;
    //         std::getline(outPath, output, '\0');
    //         outPath.close();
    //         std::cout << output;
    //         return 0;
    //     }
    // }   

}
