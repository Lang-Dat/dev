/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 21:18:20
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
    freopen("./matma.INP", "r", stdin);
    freopen("./matma.OUT", "w", stdout);
    #endif

    int tong = 0;
    string str;
    getline(cin, str);

    for (char c : str)  
        tong += c - '0';

    sort(str.begin(), str.end(), greater<int>());
    if (tong % 3 == 0 and str.back() == '0') {
            std::cout << str << "";
    } else
    std::cout << -1 << "";
    return 0;
}