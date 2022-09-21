#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

bool isPermutation(std::string tmp) {
    std::sort(tmp.begin(), tmp.end());
    for (int t = 0; t < tmp.size() - 1; t++) {
        if ((int)tmp[t] != (int)tmp[t+1] - 1)
            return false;
    }
    return true;
}

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
        std::unordered_set<char> s;
        for (int j = i; j < str.size(); j++) {
            if (s.count(str[j])) break;
            s.insert(str[j]);
            substr += str[j];
            if (substr.size() > max.size() && isPermutation(substr)) 
                max = substr;
        }
    }
    std::cout << max;
    return 0;
}