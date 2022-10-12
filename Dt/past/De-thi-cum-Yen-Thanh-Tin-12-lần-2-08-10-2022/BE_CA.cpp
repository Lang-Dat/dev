#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

const int LIM = 1e5 + 5;
ull heigh[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BE_CA.INP", "r", stdin);
    // freopen("./Test_YTL2/BE_CA/test05/BE_CA.INP", "r", stdin);
    freopen("./BE_CA.OUT", "w", stdout);

    ull n, sum = 0;
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        std::cin >> heigh[i];
    }

    for (int i = 0; i < n;) {
        // int next = std::max_element(heigh + i + 1, heigh + n + 1) - heigh;
        int next = i + 1, best = heigh[i+1];
        for (int j = i + 1; j <= n + 1 && best < heigh[i]; j++) {
            if (heigh[j] >= best) {
                best = heigh[j];
                next = j;
            }
        }
        // log(next, i, sum, heigh[i])
        sum += (next - i) * std::min(heigh[i], heigh[next]);
        i = next;
    }
    std::cout << sum;
    return 0;
}