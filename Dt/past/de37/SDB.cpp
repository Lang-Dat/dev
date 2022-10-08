#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SDB.INP", "r", stdin);
    freopen("./SDB.OUT", "w", stdout);

    std::string num;
    std::cin >> num;
    while (num.size() > 1) {
        int sum = 0;
        while (num.size() > 0) {
            sum += num.back() - '0';
            num.pop_back();
        }
        num.clear();
        while (sum > 0) {
            num.push_back((sum % 10) + '0');
            sum /= 10;
        }
        std::reverse(num.begin(), num.end());
    }
    std::cout << num;
    return 0;
}