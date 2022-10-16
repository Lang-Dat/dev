/**
 *	author: Lang Dat
 *	create: 16.10.2022 02.55.07
**/
#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    string str = "", tmp;
    while (std::cin >> tmp)
        str += tmp;
    std::unordered_set<int> s;
    for (char c : str)
        s.insert(c);
    std::cout << s.size();

    return 0;
}