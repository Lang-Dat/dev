#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
using std::vector;

const short NUM_OF_STATUS = 3;
int N, M, S, tmp, ans = 0;
// vector<vector<int>> matrix;
vector<int> col_singal;
vector<int> row_singal;
vector<vector<int>> countStatusByCol; // 0: tat; 1: xanh; 2: do
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LED.INP", "r", stdin);
    freopen("./LED.OUT", "w", stdout);

    std::cin >> M >> N >> S;
    row_singal.resize(M + 1);
    col_singal.resize(N + 1);
    countStatusByCol.resize(N+1, vector<int>(3, 0));
    unsigned char matrix[M+1][N+1];
    // matrix.resize(M + 1, vector<int>(N + 1))

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> matrix[i][j];
    
    while (S--) {
        std::cin >> tmp;
        if (tmp > M) col_singal[tmp - M]++;
        else row_singal[tmp]++;
    }
    for (int i = 1; i <= M; i++) {
        int process = row_singal[i] % NUM_OF_STATUS;
        for (int j = 1; j <= N; j++) {
            matrix[i][j] = (matrix[i][j] + process) % NUM_OF_STATUS;
            countStatusByCol[j][matrix[i][j]]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        int process = col_singal[i] % NUM_OF_STATUS;
        ans += countStatusByCol[i][(NUM_OF_STATUS - process) % NUM_OF_STATUS];
    }
    std::cout << ans << " ";
    return 0;
}