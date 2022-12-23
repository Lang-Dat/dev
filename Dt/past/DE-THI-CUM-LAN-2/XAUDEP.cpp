#pragma GCC optimize("O2")
#include <iostream>
using std::string;

bool is_palindrome(string &str) {
    if (str.size() % 2 == 1) return false;
    for (int i = 0; i < str.size() / 2; i++)
        if ((i % 2 == 0 && str[i] != str[str.size() - 1 - i]) ||
            (i % 2 != 0 && str[i] == str[str.size() - 1 - i]))
            return false;
    return true;
}

int longestPalindrome(string &s) {
    int best = 0, n = s.size();
    string subs;

    for (int l = 0; l < n; l++) {
        subs = s.substr(l);
        for (;subs.size() > best; subs.pop_back())
            if (is_palindrome(subs))
                best = subs.size();
    }
    return best;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./XAUDEP.INP", "r", stdin);
    // freopen("./XAUDEP/XAUDEP/test01/XAUDEP.INP", "r", stdin);
    freopen("./XAUDEP.OUT", "w", stdout);

    int n;
    string str;
    std::cin >> n >> str;

    std::cout << longestPalindrome(str) << " ";

    return 0;
}