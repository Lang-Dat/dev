// Largest subarray having sum greater than k
/**
 *	author: Lang Dat
 *	create: 17-10-2022 16:19:08
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
struct Value {
    ll val = 0;
    int index = -1;
};
const int LIM = 5 * 1e5 + 5;
ll nums[LIM];
int minInd[LIM];
Value prefix_sum[LIM];
int n, p;

int find_ind(int start, int end, ll val) {
    // find the last occur of val in prefix sum
    int low = start, high = end, mid, ans = -1;

    while (low <= high) {
        mid = (high + low) / 2;
        if (prefix_sum[mid].val <= val) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
void solve() {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        prefix_sum[i].val = sum;
        prefix_sum[i].index = i;
    }
    sort(prefix_sum, prefix_sum + n, [](Value &a, Value &b) -> bool {
        return a.val < b.val;
    });
    int ind_min = INT32_MAX;
    for (int i = 0; i < n; i++) {
        ind_min = min(prefix_sum[i].index, ind_min);
        minInd[i] = ind_min;
    }
    sum = 0;
    int best_length = 0, l = -1, r = -1, ind;
    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];
        if (sum >= p) {
            best_length = i + 1;
            l = 0; r = i + 1;
        } else {
            ind = find_ind(0, i, sum - p);
            if (ind != -1 && minInd[ind] < i && i - minInd[ind] + 1 > best_length) {
                best_length = i - minInd[ind] + 1;
                l = minInd[ind] + 1 + 1; r = i + 1;
            }
        }
    }
    if (l != -1) {
        std::cout << l << " " << r << " ";
    } else {
        std::cout << -1;
    }
    // return best_length;   
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DISH.INP", "r", stdin);
    freopen("./DISH.OUT", "w", stdout);

    std::cin >> n >> p;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    solve();   
    return 0;
}