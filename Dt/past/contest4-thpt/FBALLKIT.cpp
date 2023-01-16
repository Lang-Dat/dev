/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 45:37:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int freq[LIM], san_nha[LIM], san_khach[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./FBALLKIT.INP", "r", stdin);
    freopen("./FBALLKIT.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> san_nha[i] >> san_khach[i];
        freq[san_nha[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        int u = freq[san_khach[i]] + (n-1);
        std::cout << u << " " << 2*(n-1) - u << "\n";
    }
    return 0;
}