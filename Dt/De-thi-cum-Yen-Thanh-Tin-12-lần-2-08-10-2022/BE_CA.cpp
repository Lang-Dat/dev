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
    freopen("./BE_CA.OUT", "w", stdout);

    ull n, sum = 0;
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        std::cin >> heigh[i];
    }
    for (int i = 0; i <= n; i++) {
        std::cout << heigh[i] << " ";
    }

    for (int i = 0; i < n;) {
        int next;
        for (next = i + 1; heigh[next] < heigh[i] && next <= n; next++) {}
        if (heigh[next] < heigh[i]) {
            sum += heigh[i+1];
            i++;
        } else {
            sum += (next - i) * heigh[i];
            i = next;
        }
    }
    std::cout << sum;
    return 0;
}