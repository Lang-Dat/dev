/**
 *	author: Lang Dat
 *	create: 13-11-2022 42:45:18
**/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static const int LIM = 1e4 + 5;
int vao[LIM], ra[LIM], freq[LIM], add[LIM];

void solve() {
    memset(freq, 0, sizeof freq);
    int n, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> vao[i];
    for (int i = 0; i < n; i++)
        std::cin >> ra[i];
    for (int i = 0; i < n; i++) {
        freq[vao[i]]++;
        freq[ra[i]]--;
    }
    for (int i = 1; i < LIM; i++) {
        add[i] = add[i-1] + freq[i-1];
        best = max(best, add[i]);
    }
    std::cout << best << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MINPLACES.INP", "r", stdin);
    freopen("./MINPLACES.OUT", "w", stdout);
    #endif

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }   

    return 0;
}