#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <vector>

#define ull unsigned long long
int n;
std::vector<ull> fib;
std::string first, second, str, tmp;

// count how many time string str appear in string s
int countAppear(std::string s) {
    if (str.size() > s.size()) return 0;
    int count = 0;
    for (int i = 0; i <= s.size() - str.size(); i++) {
        for (int j = 0; j < str.size(); j++)
            if (str[j] != s[j + i]) goto cnt;
        count++;
        cnt:;
    }
    return count;
}
void modifyString(std::string &s) {
    int left = -1, right = 0;
    for (int l = str.size() - 1; l > 0; l--) {
        // find str suffix also s prefix
        if (s.substr(0, l) == str.substr(str.size() - l, l)) {
            left = l - 1;
            break;
        }
    }
    for (int l = str.size() - 1; l > 0; l--) {
        // find str suffix also s prefix
        if (str.substr(0, l) == s.substr(s.size() - l, l)) {
            right = s.size() - l;
            break;
        }
    }
    if (left < right)
        s.erase(left + 1, right - left - 1);
    else if (left >= 0 && right == 0)
        s.erase(left + 1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("FIBOS.INP", "r", stdin);
    freopen("FIBOS.OUT", "w", stdout);

    std::cin >> n >> first >> second >> str;
    fib.resize(n + 1, 0);

    // precompute
    fib[1] = countAppear(first);
    fib[2] = countAppear(second);

    for (int i = 3; i <= n; i++) {
        tmp = second + first;
        fib[i] = fib[i-1] + fib[i-2] + countAppear(tmp);
        modifyString(tmp);
        first = second;
        second = tmp;
    }
    std::cout << fib[n];
}