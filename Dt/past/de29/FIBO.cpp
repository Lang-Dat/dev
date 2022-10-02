#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./FIBO.INP", "r", stdin);
    freopen("./FIBO.OUT", "w", stdout);

    std::vector<ull> fiboNum; // 1  1  2  3  5  8  13 21 34 55
    std::vector<ull> ans;

    ull a = 0, b = 1;
    while (b <= 2 * (ull)1e9) {
        fiboNum.push_back(b);
        int tmp = b;
        b += a;
        a = tmp;
    }
    int n;
    std::cin >> n;
    for (int i = fiboNum.size() - 1; i >= 0; i--)
        while (n >= fiboNum[i]) {
            n -= fiboNum[i];
            ans.push_back(fiboNum[i]);
        }
    for (int i = 0; i < ans.size() - 1; i++)
        std::cout << ans[i] << "+";
    std::cout << ans.back();
    return 0;
}