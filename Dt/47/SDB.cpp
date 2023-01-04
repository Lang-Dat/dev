/**
 *	author: Lăng Trọng Đạt
 *	create: 04-01-2023 29:59:07
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> freq;
static const int LIM = 1e6 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SDB.INP", "r", stdin);
    freopen("./SDB.OUT", "w", stdout);
    #endif

    int n, tmp, count = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        freq[nums[i]]++;
    }
    
    for (auto &p : freq)
        count += p.second == 1;
    std::cout << count << "\n";
    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == 1)
            std::cout << nums[i] << "\n";
    }
    
    return 0;
}