/**
 *	author: Lang Dat
 *	create: 07-11-2022 15:19:16
**/
#include <iostream>
#include <cstring>
using namespace std;

string str, p = "";
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TruyenT.INP", "r", stdin);
    freopen("./TruyenT.OUT", "w", stdout);
    #endif

    std::cin >> n >> str;
    for (int i = 0; i < n; i++) {
        p += str[i];
        string tmp;
        for (int i = 0; i < n / p.size() + 1; i++) {
            tmp += p;
        }
        for (int i = 0; i < n; i++) {
            if (str[i] != tmp[i])
                goto cnt;
        }
        std::cout << i + 1 << "";
        break;
        cnt:;
    }
    return 0;
}