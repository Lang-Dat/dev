/**
 *	author: Lang Dat
 *	create: 23-10-2022 48:23:15
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

const int LIM = 2*1e5 + 5;
ull chan[LIM], le[LIM], nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Daysodep.INP", "r", stdin);
    freopen("./Daysodep.OUT", "w", stdout);

    int n, k, ans = 0;
    std::cin >> n >> k;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 1; i <= n; i++) {
        chan[i] = chan[i-1];
        le[i] = le[i-1];
        if (nums[i] % 2 == 0) {
            chan[i] += nums[i];
        } else {
            le[i] += nums[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int tong_chan = chan[j] - chan[i-1]; 
            int tong_le = le[j] - le[i-1]; 
            if ((tong_chan != 0) && 
                (tong_le != 0) && 
                (tong_chan - tong_le >= 0 ) && 
                (tong_chan - tong_le <= k))
                ans++;
        }
    }
    std::cout << ans;
    return 0;
}