/**
 *	author : Lăng Trọng Đạt
 *	creater: 29-01-2023 08:15:56
 *	[29-01-2023 08:37:31]: ý tưởng đầu tiên là tìm con đường với tổng độ hư hỏng ít nhất để đi 
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 5e3 + 5;
static int a[2][LIM], mark[2][LIM];
int n;

int solve(int x, int y) {
    // đánh dấu con đường với độ hư hỏng ít nhất khi đi đến a[0][n-2] hoặc a[1][n-2]
    mark[x][y] = true;
    if (y == 0) {
        
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./lane.INP", "r", stdin);
    freopen("./lane.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[1][i];
    }
    

    return 0;
}