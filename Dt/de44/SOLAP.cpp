#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e6;
bool freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOLAP.INP", "r", stdin);
    freopen("./SOLAP.OUT", "w", stdout);

    int n, count = 0, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (freq[tmp] == false) {
            freq[tmp] = true;
            count++;
        }
    }
    std::cout << count;
    return 0;
}