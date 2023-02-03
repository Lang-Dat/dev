/**
 *	author : Lăng Trọng Đạt
 *	creater: 03-02-2023 19:18:47
**/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SELENUM.INP", "r", stdin);
    freopen("./SELENUM.OUT", "w", stdout);

    int n;
    vector<int> ans;
    string str;
    std::cin >> n;

    while (std::cin >> str) {
        string temp = "";
        for (char c : str) {
            if ('0' <= c and c <= '9') {
                // if ((temp.empty() and c != '0') or !temp.empty())
                temp.push_back(c);
            } else if (!temp.empty()) {
                // db(temp)
                ans.push_back(atoi(temp.c_str()));
                temp.clear();
            }
        }
        if (!temp.empty())
            ans.push_back(atoi(temp.c_str()));
    }

    sort(ans.begin(), ans.end());
    for (auto &i : ans)
        std::cout << i << "\n";
        
    return 0;
}