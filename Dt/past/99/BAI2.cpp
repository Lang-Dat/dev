/**
 *	author: Lang Dat
 *	create: 20-11-2022 29:10:11
**/
#include <iostream>
#include <cstring>
using namespace std;

int freq[129];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    int count = 0;
    string str;
    getline(cin, str);
    for (char c : str) {
        if ((c >= 'a' && c <= 'z'))
            c = std::toupper(c);
        if (freq[c] == 0) {
            count++;
        }
        freq[c]++;
    }
    std::cout << count << "\n";
    for (int c = 0; c <= 128; c++) {
        if (freq[c] > 0) {
            std::cout << (char)c << " " << freq[c] << "\n";
        }
    }
    return 0;
}