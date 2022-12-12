/**
 *	author: Lăng Trọng Đạt
 *	create: 04-12-2022 19:55:09
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    string str;
    getline(cin, str);

    for (int i = 1, count = 1; i < str.size(); i++, count++) {
        if (str[i] != str[i-1] || i == str.size() - 1) {
            if (count != 1) std::cout << count;
            std::cout << str[i-1];
            count = 0;
        }
    }
    cout << str.back();
    return 0;
}