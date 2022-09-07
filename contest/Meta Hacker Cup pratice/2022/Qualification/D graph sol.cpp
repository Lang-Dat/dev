#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// using undirected graph
const int LIM = 200005;
int N, M, Q, x, y, c;
vector<vector<int>> *matrix = new vector<vector<int>>(LIM, vector<int>(LIM, 0));

void calc(int x, int y) {
    long long res = (*matrix)[x][y] * 2; // di thang

    // duyet theo hang ngang
    for (int i = 1; i <= N; i++)
        res += min((*matrix)[x][i], (*matrix)[i][y]);

    cout << res << " ";
}

void solve() {
    cin >> N >> M >> Q;
    // reset (*matrix) O(n^2)
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            (*matrix)[i][j] = 0;
            
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        cin >> c;
        (*matrix)[x][y] = c;
        (*matrix)[y][x] = c;
    }
    // for (int i = 1; i <= N; i++) {
    //     logm("\n")
    //     for (int j = 1; j <= N; j++)
    //         cout << (*matrix)[i][j] << " ";
    // }
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        calc(x, y);
    }
    logm("\n")
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./in/in.inp", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    // (*matrix).resize(LIM, vector<int>(LIM, 0));
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        // solve();
    }

    return 0;
}