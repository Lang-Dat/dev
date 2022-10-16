/**
 *	author: Lang Dat
 *	create: 13.10.2022 21.51.19
**/
#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long
#define ll long long
int freq[10];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUM.INP", "r", stdin);
    freopen("./SUM.OUT", "w", stdout);

    ll m, n;
    ull x;
    std::cin >> m >> n;
    if ((m >= 0 && n <= 0) || (m <= 0 && n >= 0)) {
        x = m + n;
    } else {
        x = (ull)std::abs(m) + (ull)std::abs(n);
    }
    if (x == 0) {
        std::cout << 0 << " " << 1;
        return 0;
    }
    while (x > 0) {
        freq[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] != 0) {
            std::cout << i << " " << freq[i] << "\n";
        }
    }
    return 0;
}