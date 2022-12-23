/**
 *	author: Lang Dat
 *	create: 08-11-2022 09:09:15
**/
#include <iostream>
#include <cstring>
using namespace std;

string str, p = "";

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./xauhn.INP", "r", stdin);
    freopen("./xauhn.OUT", "w", stdout);
    #endif

    std::cin >> str;
    int n = str.size();
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
        std::cout << p << "";
        break;
        cnt:;
    }

    return 0;
}