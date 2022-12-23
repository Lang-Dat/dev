#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./HAITAO.INP", "r", stdin);
    // freopen("./test/Haitao/Test13/HAITAO.INP", "r", stdin);
    freopen("./HAITAO.OUT", "w", stdout);

    ull n, m, best = 0;
    std::cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++) std::cin >> nums[i];
    if (nums[0] <= m) {
        best += nums[0]; 
        nums[0] = 0;
    }
    else {
        best += m;
        nums[0] -= m;
    }
    for (int i = 1; i < n; i++) {
        if (nums[i-1] <= m) {
            best += nums[i-1];
            int remind = m - nums[i-1];
            if (nums[i] <= remind) {
                best += nums[i];
                nums[i] = 0;
            }
            else {
                best += remind;
                nums[i] -= remind;
            }
        }   
        else best += m;
    }
    if (nums[n-1] > 0 && nums[n-1] < m) 
        best += nums[n-1];
    else if (nums[n-1] > m)
        best += m;
    std::cout << best;
    return 0;
}