#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e5 + 5;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    // freopen("./Botest/bai2/Test4/BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    int n, best, best_freq = 0, tmp;
    std::cin >> n;
    while(std::cin >> tmp) {
        freq[tmp]++;
    }
    for (int i = 0; i < LIM; i++)
        if (freq[i] > best_freq) {
            best_freq = freq[i];
            best = i;
        }

    std::cout << best << " " << best_freq;

    return 0;
}