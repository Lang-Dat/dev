#include <iostream>

const int LIM = 105;
static int matrix[LIM][LIM];

int main() {
    freopen("CROSS.INP", "r", stdin);
    freopen("CROSS.OUT", "w", stdout);

    int m, n, x, y;
    std::cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
                std::cin >> matrix[i][j];
    }
    int ans = matrix[x][y];
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i++, j++)
        ans += matrix[i][j];
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i--, j--)
        ans += matrix[i][j];
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i--, j++)
        ans += matrix[i][j];
    for (int i = x, j = y; i > 0 and j > 0 and i <= m and j <= n; i++, j--)
        ans += matrix[i][j];
    std::cout << ans - matrix[x][y] * 4;
}
