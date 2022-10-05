#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <vector>

int start, end;
std::vector<int> ans;
std::string str;

bool isPalindrome() {
    for (int i = start; i < (end + start) / 2; i++)
        if (str[i] != str[end - 1 - i]) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KHOA.INP", "r", stdin);
    freopen("./KHOA.OUT", "w", stdout);

    std::cin >> str;
    
    for (start, end = str.size(); start < str.size() - 1; start++) {
        if (isPalindrome()) ans.push_back(start);
        str
    }
    for (int i : ans)
        if (start == 0) std::cout << 1 << " " < str.size() << "\n";
        else std::cout << start + 1 << " " << start + 2 << "\n";
    return 0;
}