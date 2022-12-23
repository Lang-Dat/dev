#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEM.INP", "r", stdin);
    freopen("./DEM.OUT", "w", stdout);

    std::string str;
    std::getline(std::cin, str);
    int chu = 0, so = 0;
    for (char c : str)
        if (c >= '0' && c <= '9') so++;
        else if ((c >= 'a' && c <= 'z') ||
                 (c >= 'A' && c <= 'Z')) chu++;
    std::cout << chu << "\n" << so;

    return 0;
}