/**
 *	author: Lang Dat
 *	create: 18-11-2022 12:14:20
**/
#include <iostream>
using namespace std;

int flip(char n) {
    if (n == '1') return '3';
    else if (n == '3') return '1';
    else return '2';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NUMBER.INP", "r", stdin);
    freopen("./NUMBER_trau.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    string str = "123";
    while (str.size() <= n) {
        for (char c : str) {
            str += flip(c);
        }
    }
    std::cout << str[n-1] << "";

    return 0;
}