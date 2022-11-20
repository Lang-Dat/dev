/**
 *	author: Lang Dat
 *	create: 20-11-2022 38:15:13
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    int ans = 0;
    string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i, chu_cai = 0; j < str.size(); j++) {
            if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) 
                chu_cai++;
            ans += chu_cai > (j - i + 1 - chu_cai);
            // db(ans, i, j, chu_cai)
        }
    }
    std::cout << ans << "";
    return 0;
}