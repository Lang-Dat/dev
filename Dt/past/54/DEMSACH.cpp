/**
 *	author: Lang Dat
 *	create: 12.10.2022 48.17.19
 *	[13.10.2022 22.06.21] Bug 1: Phải duyệt qua freq sau khi input hết mới lấy đc id nhỏ nhất
**/
#include <iostream>
using namespace std;

const int LIM = 1e4;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMSACH.INP", "r", stdin);
    freopen("./DEMSACH.OUT", "w", stdout);

    int n, tmp, best = 0, id = 0;
    std::cin >> n;
    while(std::cin >> tmp) {
        freq[tmp]++;
    }
    for (int i = 0; i < LIM; i++) {
        if (freq[i] > best) {
            id = i;
            best = freq[i];
        }
    }
    std::cout << id << " " << best;
    return 0;
}