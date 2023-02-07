#include <iostream>

const int LIM = 105;
static int matrix[LIM][LIM];
bool mark[LIM][LIM];
int m, n, i0, j0, i1, j1;

void mark_val(int x, int y) {
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i++, j++)
        mark[i][j] = true;
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i--, j--)
        mark[i][j] = true;
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i--, j++)
        mark[i][j] = true;
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i++, j--)
        mark[i][j] = true;
}

int main() {
    freopen("CROSS2.INP", "r", stdin);
    freopen("CROSS2.OUT", "w", stdout);

    std::cin >> m >> n >> i0 >> j0 >> i1 >> j1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
                std::cin >> matrix[i][j];
    }
    mark_val(i0, j0);
    mark_val(i1, j1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            if (mark[i][j])
                ans += matrix[i][j];
    }
    std::cout << ans;
}

