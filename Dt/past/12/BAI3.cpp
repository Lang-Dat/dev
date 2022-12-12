/**
 *	author: Lăng Trọng Đạt
 *	create: 04-12-2022 09:59:09
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int n = 4;
bool positive[n];
int nums[n];
int total = 0;

void solve(int pos = 0, int curr = 0) {
    if (pos == 4) {
        int sum = 2*curr - total; 
        if (sum % 10 == 0 && sum > 0) {
            for (int i = 0; i < n; i++) {
                cout << (positive[i] ? '+' : '-') << nums[i];
            }
            cout << "=" << sum << "\n";
        }
        return;
    }
    solve(pos + 1, curr);
    positive[pos] = true;
    solve(pos + 1, curr + nums[pos]);
    positive[pos] = false;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        total += nums[i];
    }
        
    solve();
    return 0;
}