#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>

const int LIM = 1e4 + 5;
int count = 0;
std::vector<int> preAns(LIM, -1);

void phanTich(int n) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
    }
    if (n > 1) count++;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./THUASO.INP", "r", stdin);
    freopen("./THUASO.OUT", "w", stdout);

    int n;
    std::cin >> n;

    for (int i = 2; i <= n; i++)
        phanTich(i);

    std::cout << count;
    return 0;
}