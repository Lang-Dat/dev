#pragma GCC optimize("O2")
#include <iostream>

int P, Q, K, count = 0;
// Bruce force
int tongChuSo(int n, int sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return (sum % K == 0) ? 1 : 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    
    std::cin >> P >> Q >> K;

    for (int i = P; i <= Q; count += tongChuSo(i), i++) {}
    std::cout << count;
    return 0;
}