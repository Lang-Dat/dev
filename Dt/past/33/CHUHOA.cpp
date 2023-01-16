/**
 *	author: Lăng Trọng Đạt
 *	create: 22-12-2022 08:19:07
**/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CHUHOA.INP", "r", stdin);
    freopen("./CHUHOA.OUT", "w", stdout);
    #endif

    string str;
    getline(cin, str);

    for (char &c : str)
        c = toupper(c);

    std::cout << str << "";
    return 0;
}