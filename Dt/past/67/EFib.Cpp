/**
 *	author : Lăng Trọng Đạt
 *	creater: 29-01-2023 07:38:16
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<uint64_t> fib;
uint64_t a = 0, b = 1, n = 1e18;

int solve(int start = fib.size() - 1, uint64_t curr_sum = 0, int count = 0) {
    if (curr_sum == n)
        return count;
    else if (curr_sum > n)
        return -1;
    for (int i = start; i >= 0; i--) {
        int curr_ans = solve(i, curr_sum + fib[i], count + 1);
        if (curr_ans != -1) {
            return curr_ans;
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./EFib.INP", "r", stdin);
    freopen("./EFib.OUT", "w", stdout);
    #endif

    std::cin >> n;
    while (b <= n) {
        uint64_t tmp = b;
        b += a;
        a = tmp;
        fib.push_back(b);
    } 

    std::cout << solve() << "";
    return 0;
}