/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 49:32:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NUMCON.INP", "r", stdin);
    freopen("./NUMCON.OUT", "w", stdout);
    #endif
    
    string tmp;
    std::vector<string> str;
    while (std::cin >> tmp)
        str.push_back(tmp);
        
    sort(str.begin(), str.end(), [](string &a, string &b) -> bool {
        for (int i = 0; i < min(a.size(), b.size()); i++)
            if (a[i] != b[i])
                return a[i] > b[i];
        return a.size() < b.size();
    });

    for (string &s : str)
        std::cout << s << "";
    return 0;
}