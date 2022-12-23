/**
 *	author: Lang Dat
 *	create: 23-10-2022 19:18:07
**/
#include <iostream>
using namespace std;

int n, ans = 0;
string str;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PREFIXES.INP", "r", stdin);
    // freopen("./test/PREFIXES/test01/PREFIXES.INP", "r", stdin);
    freopen("./PREFIXES.OUT", "w", stdout);

    std::cin >> n >> str;
    // db(str)
    for (int i = 0; i < str.size(); i += 2) {
        if (str[i] == str[i+1]) {
            ans++;
            str[i] = (str[i] == 'a') ? 'b' : 'a';
        }
    }
    std::cout << ans << "\n";
    cout << str;
    return 0;
}