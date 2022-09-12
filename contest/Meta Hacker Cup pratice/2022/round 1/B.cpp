#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <utility>

using namespace std;
#define big unsigned long long
const int MOD = 1e9 + 7;
const int LIM = 500000;
int n, q;
// pair<long long, long long> trees[LIM];
big a, b, x, y;
void solve() {
    big sum_a = 0, sum_b = 0, sum_square = 0, res = 0;
    // trees
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum_a = (sum_a + a);
        sum_b = (sum_b + b);
        sum_square = (sum_square + a*a + b*b);
    }
    // log(sum_square);
    cin >> q;
    // big res = (sum_square * q);
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        res = (res + sum_square - 2LL*x*sum_a + n*(x*x + y*y) - 2LL*y*sum_b) % MOD;
        // log(res, i);
    }
    cout << res << "\n";    
}

// void solveNative() {
//     big res = 0;
//     // trees
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> trees[i].first >> trees[i].second;
//     }
//     cin >> q;
//     // big res = (sum_square * q) % MOD;
//     for (int i = 0; i < q; i++) {
//         cin >> x >> y;
//         for (auto[a, b] : trees) {
//             res = (res + (x-a)*(x-a) + (y-b)*(y-b));
//         }
//     }
//     cout << res % MOD << "\n";    
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("./Round 1/watering_well_ch2_input.txt", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}