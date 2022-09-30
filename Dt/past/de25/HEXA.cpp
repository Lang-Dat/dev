#pragma GCC optimize("O2")
#include <iostream>
#include <sstream>
#include <cstring>
#include <bitset>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./HEXA.INP", "r", stdin);
    // freopen("./Test/hexa/test1/HEXA.INP", "r", stdin);
    freopen("./HEXA.OUT", "w", stdout);

    std::string str;
    while (std::cin >> str) {
        std::ostringstream ss;
        ss << std::hex << std::stoull(str, NULL, 2);
        std::string result = ss.str();
        for (int i = 0; i < result.size(); i++)
            result[i] = std::toupper(result[i]);
        std::cout << result << "\n";
    }

    return 0;
}