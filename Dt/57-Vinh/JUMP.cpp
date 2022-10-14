/**
 *	author: Lang Dat
 *	create: 14.10.2022 33.31.19
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ull unsigned long long

const int LIM = 30005;
int nums[LIM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("./JUMP.INP", "r", stdin);
    freopen("./JUMP.OUT", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    ull prev1 = 0, prev2 = std::abs(nums[1] - nums[0]), curr, tmp;
    for (int i = 2; i < n; i++) {
        tmp = prev2;
        prev2 = min(prev1 + std::abs(nums[i] - nums[i-1]), prev2 + 3*std::abs(nums[i] - nums[i-2]));
        prev1 = tmp;
    }
    cout << prev2;
    return 0;
}