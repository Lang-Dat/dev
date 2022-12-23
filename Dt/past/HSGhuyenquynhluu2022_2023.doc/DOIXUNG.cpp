/**
 *	author: Lang Dat
 *	create: 26-10-2022 50:20:09
**/
#include <iostream>
using namespace std;

bool isPalindrome(string &str) {
    for (int i = 0, j = str.size() - 1; i < j; i++, j--)
        if (str[i] != str[j]) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOIXUNG.INP", "r", stdin);
    freopen("./DOIXUNG.OUT", "w", stdout);

    string str;
    std::cin >> str;
    (isPalindrome(str)) ? std::cout << "YES" : cout << "NO";
    return 0;
}