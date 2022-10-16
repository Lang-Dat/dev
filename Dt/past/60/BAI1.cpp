/**
 *	author: Lang Dat
 *	create: 16.10.2022 41.35.10
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n, s, str_sum;
    std::cin >> n >> s;
    string str(n, '9');
    str_sum = 9 * n;
    if (str_sum < s) {
        std::cout << "-1";
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (str_sum - 9 > s) {
            str[i] = '0';
            str_sum -= 9;
        } else {
            str[i] = 9 - (str_sum - s) + '0';
            std::cout << str;
            return 0;
        }
    }
    return 0;
}