#include <iostream>
#include <vector>
using std::vector;

int R, C;
vector<vector<char>> matrix;
void solve(int case_i)
{
    int count = 0;
    std::cin >> R >> C;
    matrix = vector<vector<char>>(R, vector<char>(C, '.'));
    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++) {
            std::cin >> matrix[x][y];
            if (matrix[x][y] == '^')
                count++;
        }

    if (count == 0) {
        std::cout << "Case #" << case_i << ": Possible\n";
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++)
                std::cout << matrix[x][y];
            std::cout << "\n";
        }
        return;
    }
    if (R == 1 || C == 1) {
        std::cout << "Case #" << case_i << ": Impossible\n";
        return;
    }
    if (R > 1 && C > 1) {
        std::cout << "Case #" << case_i << ": Possible\n";
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++)
                std::cout << '^';
            std::cout << "\n";
        }
        return;
    }
    


}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }    

    return 0;
}