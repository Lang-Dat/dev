/**
 *	author : Lăng Trọng Đạt
 *	creater: 28-01-2023 07:59:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

string str;

bool is_palindrome(int &start, int end) {
    for (int i = start, j = end; i <= j; i++, j--)
        if (str[i] != str[j])    
            return false;

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./XOAKT.INP", "r", stdin);
    freopen("./XOAKT.OUT", "w", stdout);
    #endif

    int n, k;
    std::cin >> n >> k >> str;    

    for (int i = 0; i + k < n; i++) {
        if (is_palindrome(i, i + k)) {
            std::cout << str.substr(i, k) << "";
            return 0;
        }
    }

    std::cout << "NO";  

    return 0;
}