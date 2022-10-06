#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    std::string str;
    while(std::cin >> str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] >= '0' && str[i] <= '9') {
                std::cout << str[i];
                if (i < str.size() - 1 && (str[i+1] < '0' || str[i+1] > '9'))
                    std::cout << " ";
            }
        std::cout << "\n";
    }
    return 0;
}