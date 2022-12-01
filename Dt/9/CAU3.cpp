/**
 *	author: Lăng Trọng Đạt
 *	create: 01-12-2022 27:34:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int freq[10];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CAU3.INP", "r", stdin);
    freopen("./CAU3.OUT", "w", stdout);
    #endif

    string num;
    int tong = 0;
    std::cin >> num;
    for (char c : num) {
        tong += c - '0';
        freq[c - '0']++;
    }
    
    return 0;
}