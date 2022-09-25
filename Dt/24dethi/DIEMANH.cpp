#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
const int LIM = 1e6 + 5;
int freq[LIM + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DIEMANH.INP", "r", stdin);
    freopen("./DIEMANH.OUT", "w", stdout);

    int n, tmp, max = 0, index = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        freq[tmp]++;
    std::cout << *std::max_element(freq, freq + LIM);
    return 0;
}