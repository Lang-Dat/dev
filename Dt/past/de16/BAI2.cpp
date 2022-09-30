#pragma GCC optimize("O2")
#include <iostream>

void solve(std::string str) {
    int count = 0, ans = 0;
    for (char c : str)
        if (c == '(') {count++;}
        else if (c == ')' && count >= 1) {count--; ans++;};
    std::cout << ans << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    // freopen("./BAI2.OUT", "w", stdout);
    int n;
    std::cin >> n;
    std::string str;
    while(std::cin >> str)
        solve(str);
    return 0;
}