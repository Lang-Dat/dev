/**
 *	author: Lang Dat
 *	create: 15.10.2022 59.22.15
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MATKHAU.INP", "r", stdin);
    freopen("./MATKHAU.OUT", "w", stdout);

    string num;
    std::cin >> num;
    std::cout << *max_element(num.begin(), num.end()) << *min_element(num.begin(), num.end());

    return 0;
}