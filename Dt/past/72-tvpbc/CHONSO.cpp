/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 19:28:58
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int freq[LIM];
int n, tmp, best1 = 0, best2 = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHONSO.INP", "r", stdin);
    freopen("./CHONSO.OUT", "w", stdout);

    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        if (freq[tmp] > best2) {
            if (freq[tmp] > best1) {
                best2 = best1;
                best1 = freq[tmp];
            } else {
                best2 = freq[tmp];
            }
        }
    }

    std::cout << best1 + best2 << "";
    return 0;
}