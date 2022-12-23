#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e6 + 1;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TIEUCHUAN.INP", "r", stdin);
    freopen("./TIEUCHUAN.OUT", "w", stdout);

    int n, tmp, best = 0, greater = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        freq[tmp]++;
    for (int i = LIM - 1; i > best; i--) {
        greater += freq[i];
        if (greater >= i && freq[i] != 0) 
            best = i;
    }
    std::cout << best;

    return 0;
}