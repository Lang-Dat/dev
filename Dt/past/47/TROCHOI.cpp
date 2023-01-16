/**
 *	author: Lăng Trọng Đạt
 *	create: 04-01-2023 51:05:08
**/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

static const int LIM = 1e4 + 5;
static pair<string, int> str[LIM];

int so_chu_so(string &str) {
    int count = 0;
    for (char c : str)
        count += (c >= '0' and c <= '9');
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TROCHOI.INP", "r", stdin);
    freopen("./TROCHOI.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> str[i].first;
        str[i].second = so_chu_so(str[i].first);
    }
    
    stable_sort(str, str + n, [](pair<string, int> s1, pair<string, int> s2) -> bool {
        return s1.second < s2.second;
    });

    for (int i = 0; i < n; i++)
        std::cout << str[i].first << "\n";
    return 0;
}