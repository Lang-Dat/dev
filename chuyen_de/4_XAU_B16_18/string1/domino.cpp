/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 37:01:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./domino.INP", "r", stdin);
    freopen("./domino.OUT", "w", stdout);
    #endif

    int t, n;
    string str;
    std::cin >> t;
    while (std::cin >> n >> str) {
        for (char c : str) {
            if (c == 'U') cout << 'D';
            else if (c == 'D') cout << 'U';
            else if (c == 'L') cout << 'L';
            else if (c == 'R') cout << 'R';
        }
        std::cout << "\n";
    }

    return 0;
}