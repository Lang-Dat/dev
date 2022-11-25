/**
 *	author: Lang Dat
 *	create: 18-11-2022 08:06:19
**/
#include <iostream>
using namespace std;

int freq[128 + 5];

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
    std::cin >> str;
    for (char c : str) {
        if (freq[c] == 0) count++;
        freq[c]++;
    }
    std::cout << count<< "\n";
    for (int i = 'A'; i <= 'Z'; i++) {
        if (freq[i] != 0) {
            std::cout << (char)i << " " << freq[i] << "\n";
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (freq[i] != 0) {
            std::cout << (char)i << " " << freq[i] << "\n";
        }
    }
    for (int i = '0'; i <= '9'; i++) {
        if (freq[i] != 0) {
            std::cout << (char)i << " " << freq[i] << "\n";
        }
    }
    return 0;
}