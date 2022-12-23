/**
 *	author: Lăng Trọng Đạt
 *	create: 06-12-2022 26:15:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int find_distist(string &str) {
    int freq[129];
    memset(freq, 0, sizeof(freq));
    for (char c : str) freq[c]++;
    for (int i = 0; i < str.size(); i++)
        if (freq[str[i]] == 1)
            return i + 1;
    return -1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    int T;
    string str;
    std::cin >> T;
    while (std::cin >> str) {
        std::cout << find_distist(str) << "\n";
    }

    return 0;
}