#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

bool isHaveNum(std::string str) {
    for (char c : str)
        if ((int)(c - '0') >= 0 && (int)(c - '0') <= 9)
            return true;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMTU.INP", "r", stdin);
    freopen("./DEMTU.OUT", "w", stdout);

    std::string str;
    int count = 0;
    while(std::cin >> str)
        count += (int)isHaveNum(str);

    std::cout << count;
    return 0;
}