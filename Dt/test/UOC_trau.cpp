/**
 *	author: Lang Dat
 *	create: 02-11-2022 59:48:06
**/
#include <iostream>
using namespace std;

int tongUoc(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;
        }
    }
    return sum;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOC.INP", "r", stdin);
    freopen("./UOC_trau.OUT", "w", stdout);

    int n, tmp, sum  = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        // db(tongUoc(tmp), tmp);
        sum += tongUoc(tmp);
    }
    std::cout << sum << "";
    return 0;
}