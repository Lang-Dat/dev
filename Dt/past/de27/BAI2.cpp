#pragma GCC optimize("O2")
#include <iostream>
#include <map>

std::map<int, int> freq;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    int n, tmp, max = -1, i;
    std::cin >> n;
    while(std::cin >> tmp)
        freq[tmp]++;
    for (auto &p : freq) {
        if (p.second > max) {
            max = p.second;
            i = p.first;
        }
    }

    std::cout << i << " " << max;
    return 0;
}