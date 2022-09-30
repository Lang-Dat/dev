#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int row = 1;
int max = 0;
std::vector<std::pair<int, std::string>> ans;

void find(std::string str) {
    char c;
    int maxLength = 0, currMax = 1;
    for (int i = 1; i < str.size(); i++)
        if (str[i] == str[i-1]) currMax++;
        else {
            if (currMax > maxLength) {
                c = str[i-1];
                maxLength = currMax;
            }
            currMax = 1;
        }
    if (maxLength == max)
        ans.push_back({row, std::string(maxLength, c)});
    else if (maxLength > max) {
        ans.clear();
        ans.push_back({row, std::string(maxLength, c)});
        max = maxLength;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./XEPHANG.INP", "r", stdin);
    freopen("./XEPHANG.OUT", "w", stdout);

    std::string str;
    while(std::cin >> str) {
        find(str);
        row++;
    }
    for (auto &p : ans)
        std::cout << p.first << " " << p.second << "\n";
    return 0;
}