#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

const int LIM = 11;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./THONGKE.INP", "r", stdin);
    freopen("./THONGKE.OUT", "w", stdout);

    ull n, tmp;
    std::cin >> n;
    while(std::cin >> tmp)    
        freq[tmp]++;
    for (int i = 1; i < LIM; i++)
        if (freq[i] > 0)
            std::cout << i << " " << freq[i] << "\n";

    return 0;
}