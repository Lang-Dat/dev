// Bài này test rất hiểm    
#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    std::string str, tmp = "";
    std::vector<std::string> ans;
    std::getline(std::cin, str);
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] >= '0' && str[i] <= '9')
            tmp += str[i];
        else if (!tmp.empty()) {
            ans.push_back(tmp);
            tmp = "";
        }
        if (i == str.size() - 1 && !tmp.empty())
            ans.push_back(tmp);
    }
    for (std::string a : ans)
        std::cout << a << "\n";
    if (ans.empty())
        std::cout << "No";
    return 0;
}