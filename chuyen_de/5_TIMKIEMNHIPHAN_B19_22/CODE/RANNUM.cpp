/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 09:09:20
**/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e5 + 5;
static const int MAX = 1001;
int nums[LIM];
int freq[2*MAX];
int n;

bool check(int k) {
    // kiểm tra xem có tồn tại số k ngẫu nhiên hay không

    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < k; i++)
        freq[nums[i] + MAX]++;
    for (int i = k; i < n; i++) {
        if (freq[nums[i] + MAX] > 0)  
            freq[nums[i] + MAX]++;
        freq[nums[i - k] + MAX]--;
    }
    bool is_appear = false;
    for (int i : freq)
        is_appear |= i > 0;
        
    return is_appear;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./RANNUM.OUT", "w", stdout);
    freopen("./RANNUM.INP", "r", stdin);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    int min_k = n / 2 + 1;
    int l = 1, r = min_k;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            min_k = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    std::cout << min_k << "";
    return 0;
}