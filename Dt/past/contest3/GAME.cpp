/**
 *	author: Lăng Trọng Đạt
 *	create: 26-11-2022 42:03:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 105;
int matrix[2][LIM];
char tmp;
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GAME.INP", "r", stdin);
    freopen("./GAME.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> tmp;
            matrix[i][j] = tmp - '0';
        }
    }
    
    for (int j = 0; j < n-1; j++) {
        if (matrix[0][j] + matrix[1][j] + matrix[0][j+1] + matrix[1][j+1] > 3) {
            cout <<  "NO";
            return 0;
        }
    }
    cout <<  "YES";
    return 0;
}