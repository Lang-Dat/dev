/**
 *	author: Lang Dat
 *	create: 20-11-2022 54:39:12
**/
#include <iostream>
using namespace std;

int tongUoc(int n, int sum = 0) {
    // bruce force
    for (int i = 1; i * i<= n; i++)
        // if (n % i == 0 && i * i != n) sum += i + n / i;
        // else if (n % i == 0 && i * i == n) sum += i;
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;
        }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    int ans[] = {0, 6, 28, 496, 8128};
    int n, sum = 0;
    std::cin >> n;
    for (int i : ans)
        if (i <= n)
            sum += i;
    std::cout << sum << "";
    return 0;
}