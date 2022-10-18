/**
 *	author: Lang Dat
 *	create: 18-10-2022 55:23:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./XAUCHUAN.INP", "r", stdin);
    freopen("./XAUCHUAN.OUT", "w", stdout);

    string tmp;
    std::vector<string> str;
    while (std::cin >> tmp)
        str.push_back(tmp);
    
    for (int i = 0; i < str.size() - 1; i++)
        std::cout << str[i] << " ";
    std::cout << str.back();

    return 0;
}