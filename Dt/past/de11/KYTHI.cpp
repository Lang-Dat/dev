#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

using std::vector;
const int LIM = 105;
vector<vector<int>> matrix(LIM, vector<int>(LIM, 0));

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KYTHI.INP", "r", stdin);
    freopen("./KYTHI.OUT", "w", stdout);

    int x, y, z, n;
    std::cin >> n;
    while (std::cin >> x >> y >> z)
    {
        matrix[x][y] = z;
        matrix[y][x] = z;
    }
    
    int diemDat, sum, min = INT32_MAX;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= n; j++)
            sum += matrix[i][j];
        if (sum <= min) {
            min = sum;
            diemDat = i;
        }
    }   
    std::cout << diemDat << "\n" << min;
    return 0;
}