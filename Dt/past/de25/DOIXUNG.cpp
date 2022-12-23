#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_set>
#include <cstring>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOIXUNG.INP", "r", stdin);
    // freopen("./test/doixung/test12/DOIXUNG.INP", "r", stdin);
    freopen("./DOIXUNG.OUT", "w", stdout);

    std::string str, tmp;
    std::unordered_set<std::string> s;
    int count = 0;
    while(std::cin >> str) {
        tmp = str;
        std::reverse(str.begin(), str.end());
        if (tmp == str || s.count(tmp)) continue;
        if (s.count(str))
            count++;
        s.insert(tmp);
    }
    std::cout << count;


    return 0;
}