/**
 *	author : Lăng Trọng Đạt
 *	creater: 05-02-2023 07:13:01
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./XAUCHAN.INP", "r", stdin);
    freopen("./XAUCHAN.OUT", "w", stdout);

    std::unordered_map<char, int> freq;
    char c;
    while (std::cin >> c)
        freq[c]++;

    for (auto& p : freq)
        if (p.second & 1) {
            std::cout << "NO";
            return 0;
        }

    std::cout << "YES";
}