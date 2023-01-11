/**
 *	author : Lăng Trọng Đạt
 *	creater: 06-01-2023 53:36:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e3 + 5;
static int nums[LIM][LIM];
int n, q, target;

void search() {
    int x = 1, y = n;
    while (nums[x][y] != target)
        if (nums[x][y] < target)
            x++;
        else 
            y = lower_bound(nums[x], nums[x] + n, target) - nums[x];
    
    std::cout << x << " " << y << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TABLE.INP", "r", stdin);
    freopen("./TABLE.OUT", "w", stdout);
    #endif

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= n; j++)
            std::cin >> nums[i][j];
    }

    while (std::cin >> target) {
        search();
    }

    return 0;
}