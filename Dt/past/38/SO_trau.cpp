/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 27:37:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SO.INP", "r", stdin);
    freopen("./SO_trau.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        prev = reverse(prev) + 2;
        
    }    

    std::cout << prev << "";
    return 0;
}