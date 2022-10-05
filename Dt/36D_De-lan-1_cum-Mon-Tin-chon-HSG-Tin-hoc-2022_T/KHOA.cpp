#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <vector>

int start, end;
std::vector<int> ans;
std::string str;

bool isPalindrome() {
    for (int i = start, j = end - 1; i < j; i++, j--)
        if (str[i] != str[j]) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KHOA.INP", "r", stdin);
    freopen("./KHOA.OUT", "w", stdout);

    std::cin >> str;
    str += str;
    for (start = 0, end = str.size() / 2; start < str.size() / 2; start++, end++)
        if (isPalindrome()) ans.push_back(start);
    std::cout << ans.size() << "\n";
    for (int i : ans)
        if (i == 0) std::cout << 1 << " " << str.size() / 2 << "\n";
        else std::cout << i << " " << i + 1 << "\n";
    return 0;
}