/**
 *	author : Lăng Trọng Đạt
 *	creater: 25-01-2023 15:52:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

int64_t tong_uoc(int64_t n) {
    int64_t sum = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n)
                sum += n / i;
        }
    }

    return sum;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./ANHEM.INP", "r", stdin);
    freopen("./ANHEM.OUT", "w", stdout);
    #endif

    int64_t a, b;
    std::cin >> a >> b;

    cout << (tong_uoc(a) == tong_uoc(b) ? "YES" : "NO");

    return 0;
}