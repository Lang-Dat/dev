#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

int type(std::string num) {
    int s = num.size();
    if (s >= 7 &&
        num[0] == num[s-3] && num[1] == num[s-2] && num[2] == num[s-1])
        return 3;
    else if (s >= 5 &&
        num[0] == num[s-2] && num[1] == num[s-1])
        return 2;
    else if (s >= 3 &&
        num[0] == num[s-1])
        return 1;
    else return 0;
    return 0;    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOGANH.INP", "r", stdin);
    freopen("./SOGANH.OUT", "w", stdout);

    std::string num;
    while (std::cin >> num)
        std::cout << type(num) << "\n";

    return 0;
}