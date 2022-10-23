/**
 *	author: Lang Dat
 *	create: 23-10-2022 19:18:07
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PREFIXES.INP", "r", stdin);
    freopen("./PREFIXES.OUT", "w", stdout);

    int n, count = 0;
    string str;
    std::cin >> n >> str;

    for (int i = 0; i <= str.size() / 2; i += 2) {
        if (str[i] == str[i+1]) {
            count++;
            str[i] = (str[i] == 'a') ? 'b' : 'a';
        }
    }
    std::cout << count << "\n" << str;
    return 0;
}