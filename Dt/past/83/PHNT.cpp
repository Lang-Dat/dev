/**
 *	author: Lang Dat
 *	create: 31-10-2022 31:58:07
**/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PHNT.INP", "r", stdin);
    freopen("./PHNT.OUT", "w", stdout);

    string str, tmp = "";
    int n;
    std::cin >> n >> str;

    for (int i = 1; i <= n; i++) {
        tmp = str.substr(0, i);
        for (int j = 0; j < n - i; j++) {
            if (search(str.begin() + j + 1, str.end(), str.begin() + j, str.begin() + j + i) != str.end()) {
                goto cnt;
            }
        }
        std::cout << i << "";
        return 0;
        cnt:;
    }
    std::cout << n << "";
    return 0;
}
