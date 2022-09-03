#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool isPalindrome(std::string str) {
    int n = str.size();
    for (int i = 0; i <= n / 2 - 1; i++)
        if (str[i] != str[n - 1 - i])
        {
            return false;
        }

    return true;
}

std::string solve(std::string str, int n) {
    for (int i = 1; i <= n; i++) {
        std::string tmp = str.substr(0, i);
        if (isPalindrome(tmp) && isPalindrome(str.substr(i, n - i)))
            return tmp;
    }
    return str;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T, n;
    std::string str;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++)
    {
        std::cin >> n;
        std::cin >> str;
        auto ans = solve(str, n);
        std::cout << "Case #" << i << ": " << ans << "\n";
    }

    return 0;
}