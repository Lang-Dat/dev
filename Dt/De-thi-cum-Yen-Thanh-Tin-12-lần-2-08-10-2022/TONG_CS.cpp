#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

const int LIM = 9*9+5;
int pre_make[LIM];

ull tongChuSo(int n, int sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TONG_CS.INP", "r", stdin);
    freopen("./TONG_CS.OUT", "w", stdout);

    ull a, b, sum = 0;
    std::cin >> a >> b;

    for (int i = 0; i <= 9 * 9; i++) {
        int n = i;
        while(n >= 9) {
            n = tongChuSo(n);         
        }
        pre_make[i] = n;
    }
    for (int i = a; i <= b; i++) {
        sum += pre_make[tongChuSo(i)];
    }
    std::cout << sum;
    return 0;
}