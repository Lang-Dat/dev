/**
 *	author: Lăng Trọng Đạt
 *	create: 26-12-2022 31:52:22
**/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Value {
    int pos, v;
};
static const int LIM = 1e5 + 5;
// static int pos[LIM], v[LIM];
static Value val[LIM];

int n;

int search(int l, int r, double target) {
    int ind = l;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((double)val[mid].pos >= target) {
            ind = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ind;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NOEL.INP", "r", stdin);
    // freopen("./NOEL/Test05/NOEL.INP", "r", stdin);
    freopen("./NOEL.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> val[i].pos;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> val[i].v;
    }
       
    sort(val, val + n, [](Value &a, Value &b) -> bool {
        return a.pos < b.pos;
    });

    double time = 0;
    for (int i = 0; i < n; i++) {
        int start = search(i + 1, n, val[i].pos + (double)val[i].v*time);
        for (int j = start; j < n; j++) {
            int distance = std::abs(val[j].pos - val[i].pos);
            time = max(time, (double)distance/(val[i].v + val[j].v));
        }
    }

    // printf("%.7f", time);
    std::cout << fixed << setprecision(6) << time;
    return 0;
}