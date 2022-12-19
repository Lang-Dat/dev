/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 55:08:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(string &num) {
    for (int l = 0, r = num.size() - 1; l <= r; l++, r--)
        if (num[l] != num[r])
            return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PASSW.INP", "r", stdin);
    freopen("./PASSW.OUT", "w", stdout);
    #endif

    string num = "", best = "";
    int k;
    std::cin >> k;

    char tmp;
    while (std::cin >> tmp)
        if ('0' <= tmp and tmp <= '9')
            num += tmp;

    int ind = -1;
    while (k > 0) {
        ind = max_element(num.begin() + ind + 1, num.end() - k + 1) - num.begin();
        best += num[ind];
        k--;
    }

    std::cout << best << "\n";
    std::cout << (is_palindrome(best) ? "YES" : "NO") << "";
    return 0;
}