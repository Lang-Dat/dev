/**
 *	author : Lăng Trọng Đạt
 *	creater: 29-01-2023 07:34:52
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2e3 + 5;
static int points[LIM];
int n, pos = 1000, best = 0;
char c;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MoveRect.INP", "r", stdin);
    freopen("./MoveRect.OUT", "w", stdout);
    #endif

    points[pos] = 1;
    std::cin >> n;
    
    while (std::cin >> c) {
        (c == 'L') ? points[--pos]++ : points[++pos]++;
        best = max(points[pos], best);
    }

    std::cout << best << "";

    return 0;
}