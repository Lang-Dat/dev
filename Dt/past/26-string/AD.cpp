/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 22:31:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

int freq[129];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./AD.INP", "r", stdin);
    freopen("./AD.OUT", "w", stdout);
    #endif

    string s1, s2;
    int count = 0;
    std::cin >> s1 >> s2;

    for (char c : s1)
        freq[c]++;
    for (char c : s2)
        freq[c]--;
    for (int i : freq)
        count += std::abs(i);
    std::cout << count << "";
    return 0;
}