#pragma GCC optimize("O2")
#include <iostream>

bool isPerfect(int n, int sum = 1) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0 && i * i != n) sum += i + n / i;
        else if (n % i == 0 && i * i == n) sum += i;
    return sum == n;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n, tmp, count = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        count += isPerfect(tmp);
    std::cout << count;

    return 0;
}