#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ASIANCUP.INP", "r", stdin);
    freopen("./ASIANCUP.OUT", "w", stdout);

    std::vector<std::string> x, y, z; // X: HV; y: TV; Z: TD
    std::string str, thuMon;
    for (int i = 0; i < 11; i++) {
        std::getline(std::cin, str);
        if (str.substr(str.size() - 2) == "HV") 
            x.push_back(str.substr(0, str.size() - 2));
        else if (str.substr(str.size() - 2) == "TV") 
            y.push_back(str.substr(0, str.size() - 2));
        else if (str.substr(str.size() - 2) == "TD") 
            z.push_back(str.substr(0, str.size() - 2));
        else thuMon = str.substr(0, str.size() - 2);
    }
    std::cout << x.size() << " " << y.size() << " " << z.size() << "\n";
    for (auto s : z)
        std::cout << s << " ";
    std::cout << "\n";
    for (auto s : y)
        std::cout << s << " ";
    std::cout << "\n";
    for (auto s : x)
        std::cout << s << " ";
    std::cout << "\n";
    std::cout << thuMon;
    return 0;
}