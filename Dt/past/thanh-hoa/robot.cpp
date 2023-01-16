/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 11:15:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./robot.INP", "r", stdin);
    freopen("./robot.OUT", "w", stdout);
    #endif

    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int x_d = max(x1, x2) - min(x1, x2);
    int y_d = max(y1, y2) - min(y1, y2);
    int val = min(x_d, y_d);

    std::cout << val + (x_d - val) + (y_d - val) << "";
    return 0;
}