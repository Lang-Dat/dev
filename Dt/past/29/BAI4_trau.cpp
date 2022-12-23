/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 57:31:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4_trau.OUT", "w", stdout);
    #endif

    int n;
    int count = 0;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            for (int z = j + 1; z <= n; z++)
                if (i + j + z == n) count++;
                else if (i + j + z == n)
                    break;
    }

    std::cout << count << "";
    return 0;
}