#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <vector>

std::vector<int> ans;
std::string str;

bool isPalindrome(int start, int end) {
    for (int i = start, j = end; i < j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KHOA.INP", "r", stdin);
    freopen("./KHOA.OUT", "w", stdout);

    std::cin >> str;
    int l = str.size();
    for (int i = 0; i < l; i++)
        if ((i < l/2 + 1 && isPalindrome(0, i * 2 - 1) && isPalindrome(i * 2, l - 1)) || 
             (i >= l / 2 && isPalindrome(2*i - l, l - 1) && isPalindrome(0, 2*i - l - 1)))
            ans.push_back(i);
    if (ans.size() == 0) {
        std::cout << -1;
        return 0;
    }
    std::cout << ans.size() << "\n";
    for (int i : ans) {
        if (i == 0) std::cout << i + 1 << " " << l << "\n";
        else std::cout << i << " " << i + 1 << "\n";
    }
    return 0;
}