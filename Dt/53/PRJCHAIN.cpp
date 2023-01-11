/**
 *	author : Lăng Trọng Đạt
 *	creater: 08-01-2023 15:04:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Value {
    int a, b, diff;
};
// static const int LIM = 1e6 + 5;
static const int LIM = 7;
static Value v[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PRJCHAIN.INP", "r", stdin);
    freopen("./PRJCHAIN.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].a;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].b;
        v[i].diff = v[i].a - v[i].b;
    }
    
    sort(v, v + n, [](Value &a, Value &b) -> bool {
        return a.diff < b.diff;
    });
    int ind = 0;
    for (; ind < n and v[ind].diff <= 0; ind++)
    sort(v + ind, v + n, [](Value &a, Value &b) -> bool {
        return a.b > b.b;
    });

    int curr = 0, request = 0;
    for (int i = 0; i < n; i++) {
        if (curr < v[i].a) {
            request += v[i].a - curr;
            curr = v[i].b;
        } else
            curr = curr - v[i].a + v[i].b;
    }

    std::cout << request << "";
    return 0;
}