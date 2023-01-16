/**
 *	author: Lăng Trọng Đạt
 *	create: 03-01-2023 09:33:19
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./Chiahetk.INP", "r", stdin);
    freopen("./Chiahetk.OUT", "w", stdout);
    #endif

    int curr_sum = 0;
    int n, k, tmp;
    int ans = 0;
    
    std::cin >> n >> k;
    while (std::cin >> tmp) {
        curr_sum = (curr_sum + tmp) % k;
        ans += (curr_sum == 0);
        ans += freq[curr_sum];
        freq[curr_sum]++;
    }

    std::cout << ans << "";
    return 0;
}