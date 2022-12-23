/**
 *	author: Lang Dat
 *	create: 16-10-2022 38:04:21
**/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./EVENSUM.INP", "r", stdin);
    // freopen("./EVENSUM.OUT", "w", stdout);

    int n, q;
    std::cin >> n >> q;
    int lim = sqrt(LIM);
    std::vector<int> chia_can(lim, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        if (nums[i] % 2 == 0) {
            chia_can[i/lim]++;
        }
    }
    for (int i : chia_can)
        std::cout << i << " ";
    int loai, l, r;
    while (std::cin >> loai >> l >> r) {
        if (loai == 1) {
            if (nums[l] % 2 == 0 && r % 2 != 0) {
                chia_can[l / lim]--;
            } else if (nums[l] % 2 != 0 && r % 2 == 0) {
                chia_can[l / lim]++;
            }
            nums[l] = r;
        } else if (loai == 2) {
            int count = 0;
            for (int i = (l % lim == 0) ? l / lim : l / lim + 1; i <= r / lim; i++) {
                db(chia_can[i], i)
                count += chia_can[i];
            }
            for (int i = l; i < l / lim * lim + lim; i++) {
                if (nums[i] % 2 == 0) count++;
            }
            for (int i = r / lim * lim; i < r; i++) {
                if (nums[i] % 2 == 0) count++;
            }
            std::cout << count << "\n";
        }
    }
    return 0;
}