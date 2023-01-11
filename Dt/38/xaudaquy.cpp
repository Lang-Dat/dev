/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 26:16:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

string str, org;

bool isPalindrome(int start, int end) {
    for (int l = start, r = end - 1; l < r; l++, r--)
        if (str[l] != str[r]) {
            return false;
        }

    return true;
}  

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./xaudaquy.INP", "r", stdin);
    freopen("./xaudaquy.OUT", "w", stdout);
    #endif

    std::cin >> org;
    int count = 0;

    str = org + org;
    for (int i = 0; i < org.size(); i++)    
        count += isPalindrome(i, i + org.size());


    std::cout << count << "";

    return 0;
}