// Log10(a.b) = Log10(a) + Log10(b)
/**
 *	author: Lang Dat
 *	create: 20-11-2022 03:21:19
**/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n, i;
    double count = 0;
    std::cin >> n;
    for (i = 1; count < n - 1; i++) {
        count += log10(i);
    }
    if ((int)count == n - 1)
        cout << i - 1;
    else 
        cout << -1;
    return 0;
}