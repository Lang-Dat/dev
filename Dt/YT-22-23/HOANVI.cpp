#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./HOANVI.INP", "r", stdin);
    freopen("./HOANVI.OUT", "w", stdout);

    std::string str, substr, tmp, max = "";
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        substr = "";
        for (int j = i; j < str.size(); j++) {
            substr += str[j];
            tmp = substr;
            std::sort(tmp.begin(), tmp.end());
            for (int t = 0; t < tmp.size() - 1; t++) {
                if ((int)tmp[t] != (int)tmp[t+1] - 1)
                    goto cnt;
            }
            if (substr.size() > max.size())
                max = substr;
            cnt:;
        }
    }
    std::cout << max;
    return 0;
}