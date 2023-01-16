/**
 *	author: Lăng Trọng Đạt
 *	create: 03-01-2023 18:36:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int freq[LIM];
bool is_selected[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MODK.INP", "r", stdin);
    freopen("./MODK.OUT", "w", stdout);
    #endif

    int n, k, tmp, curr;
    std::cin >> n >> k;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        curr = std::abs(tmp) % k;
        if (tmp < 0)
            curr = k - curr;
        
        freq[curr]++;
    }
    
    int count = freq[0] != 0;

    for (int i = 1; i < k; i++) {
        if (!is_selected[k - i]) {
            count += freq[i];
            is_selected[i] = true;
        }
    }

    std::cout << count << "";

    return 0;
}