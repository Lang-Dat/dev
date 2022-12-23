/**
 *	author: Lang Dat
 *	create: 21-10-2022 08:21:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e5 + 10;
int nam[LIM];
int nu[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./FLOWER.INP", "r", stdin);
    freopen("./FLOWER.OUT", "w", stdout);

    int n, m, count = 0;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> nam[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> nu[i];
    }
        
    sort(nam, nam + n);

    for (int i = 0; i < m; i++) {
        cout << n - (lower_bound(nam, nam + n, nu[i]) - nam) << " ";
    }
    return 0;
}