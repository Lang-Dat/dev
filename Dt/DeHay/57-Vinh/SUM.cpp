/**
 *	author: Lang Dat
 *	create: 13.10.2022 21.51.19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
#define ll long long

struct Value {
    ll index, val;
};
Value freq[10];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUM.INP", "r", stdin);
    // freopen("./test_TT/SUM/Test11/SUM.INP", "r", stdin);
    freopen("./SUM.OUT", "w", stdout);

    ll m, n;
    std::cin >> m >> n;
    ll x = m + n;
    std::cout << x << "\n";
    if (x < 0) x = -x;
    // db(x, m, n)
    while (x > 0) {
        freq[x % 10].val++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        freq[i].index = i;
    }
    sort(freq, freq + 10, [](Value &a, Value &b) -> bool {
        return a.val > b.val;
    });
    for (int i = 0; i < 10; i++) {
        if (freq[i].val != 0)
            std::cout << freq[i].index << " " << freq[i].val << "\n";
    }
    return 0;
}