#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e6 + 1;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMHANG.INP", "r", stdin);
    freopen("./DEMHANG.OUT", "w", stdout);

    int n, tmp, loaiHang, count = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        freq[tmp]++;

    for (int i = 0; i < LIM; i++)
        if (freq[i] > count) {
            count = freq[i];
            loaiHang = i;
        }
    std::cout << loaiHang << " " << count;

    return 0;
}