/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 23:49:20
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
    freopen("./string.INP", "r", stdin);
    freopen("./string.OUT", "w", stdout);
    #endif

    string s1, s2;

    while (std::cin >> s1 >> s2) {
        if (s1 == "END" && s2 == "END") break;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        std::cout << ((s1 == s2) ? "same" : "different") << "\n";
    }   

    return 0;
}