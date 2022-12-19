/**
 *	author: Lăng Trọng Đạt
 *	create: 23-11-2022 43:47:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 15005;
int w[LIM]; // weights

bool check(int v, int k, int n) {
    // TC: O(N)
    // Kiểm tra xem với k thùng có thể tích là v thì có chứa được hết không
    int dem = 1;
    for (int i = 0, curr = 0; i < n; i++) {
        if (curr + w[i] <= v) curr += w[i];
        else {
            curr = w[i];
            dem++;
        }
    }
    return k >= dem;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./zxy.INP", "r", stdin);
    freopen("./zxy.OUT", "w", stdout);
    #endif

    int n, k, ans = -1;
    int l = INT32_MIN, r = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
        l = max(l, w[i]);
        r += w[i];
    }
    
    // TC: O(log(r - l))
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, k, n)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::cout << ans << "";
    return 0;
}