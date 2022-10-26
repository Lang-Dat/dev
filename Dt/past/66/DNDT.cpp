/**
 *	author: Lang Dat
 *	create: 21-10-2022 09:07:20
**/
#include <iostream>
#include <unordered_map>
using namespace std;

int firstDististOccu(string str) {
    std::unordered_map<char, int> freq;
    for (int i = 0; i < str.size(); i++) {
        freq[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++) {
        if (freq[str[i]] == 1) {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DNDT.INP", "r", stdin);
    freopen("./DNDT.OUT", "w", stdout);

    int n;
    string str;
    std::cin >> n;
    while (std::cin >> str) {
        std::cout << firstDististOccu(str) << "\n";
    }

    return 0;
}