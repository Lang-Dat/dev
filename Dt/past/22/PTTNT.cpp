/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 43:02:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int target;
std::vector<int> primes = {7, 5, 3, 2};
int ans[10];

void solve(int pos = 0, int curr = 0) {
    if (curr == target) {
        for (int i = 10; i > 0; i--)
            if (ans[i])
                for (int j = 0; j < ans[i]; j++)
                    std::cout << i << " ";
        std::cout << "\n";
        return;
    } else if (curr > target || pos >= primes.size()) return;

    for (int i = pos; i < primes.size(); i++) {
        ans[primes[i]]++;
        solve(i, curr + primes[i]);
        ans[primes[i]]--;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PTTNT.INP", "r", stdin);
    freopen("./PTTNT.OUT", "w", stdout);
    #endif

    std::cin >> target;

    solve();
    return 0;
}