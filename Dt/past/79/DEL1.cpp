/**
 *	author: Lang Dat
 *	create: 26-10-2022 06:08:16
**/
#include <iostream>
#include <vector>
using namespace std;

#define ull long long
const int MOD = 1e9 + 7;
ull pro = 1;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEL1.INP", "r", stdin);
    freopen("./DEL1.OUT", "w", stdout);

    ull n, tmp, max_neg = INT64_MIN, neg_count = 0;
    int zeros = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        if (tmp < 0) {
            max_neg = max(tmp, max_neg);
            neg_count++;
        }
        zeros += tmp == 0;
        if (tmp != 0)
            pro = (pro * std::abs(tmp));
        // if (pro > 0)
        //     pro %= MOD;
    }
    if (zeros > 1 || (zeros == 1 && neg_count % 2 == 1)) {
        pro = 0;
    } else if (neg_count % 2 == 1 && zeros == 0) {
        pro /= std::abs(max_neg);       
    } else if (neg_count % 2 == 1) {
        pro = 0;
    }
    std::cout << pro << "";
    return 0;
}