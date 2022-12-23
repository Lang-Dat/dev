/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 05:17:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MBRACKETS.INP", "r", stdin);
    freopen("./MBRACKETS.OUT", "w", stdout);
    #endif

    int n, t;
    string str;
    std::cin >> t;
    while (std::cin >> n >> str) {
        int open = 0, count = 0;
        for (char c : str) {
            if (c == '(') open++;
            else if (open == 0) count++;
            else open--;
        }

        std::cout << count << "\n";
    }

    return 0;
}