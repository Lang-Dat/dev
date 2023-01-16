/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 11:32:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];

int ind, best = 0;
int n;

void try_excl(int index) {
    int start = (index == 0) ? 1 : 0;
    int gcd = nums[start];
    for (int i = start + 1; i < n; i++) {
        if (i == index) continue;
        gcd = __gcd(gcd, nums[i]);
    }
    
    if (gcd > best) {
        best = gcd;
        ind = index;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BRAIN.INP", "r", stdin);
    freopen("./BRAIN.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        try_excl(i);
    }

    std::cout << ind + 1 << " " << best;
    return 0;
}