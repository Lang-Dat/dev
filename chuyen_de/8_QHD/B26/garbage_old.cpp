// https://claoj.edu.vn/problem/garbage
/**
 *	author: Lang Dat
 *	create: 29-10-2022 10:44:15
**/
#include <iostream>
using namespace std;

struct Value {
    int next_x = -1, next_y = -1, val = 0, max = 0; // luong rac thai lon nhat thu duoc 
};
// const int LIM = 1e3 + 3;
const int LIM = 10;
Value m[LIM][LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
       std::cin.tie(nullptr);
    // freopen("./GARBAGE.INP", "r", stdin);
    // freopen("./GARBAGE.OUT", "w", stdout);

    int col, row;
    int best = 0, start;
    std::cin >> row >> col;
    for (int i = 1; i <= row; i++)   
        for (int j = 1; j <= col; j++) {
            std::cin >> m[i][j].val;
        }

    for (int i = row; i > 0; i--) {
        for (int j = 1; j <= col; j++) {
            if (m[i + 1][j - 1].max + m[i][j].val > m[i][j].max) {
                m[i][j].max = m[i + 1][j - 1].max + m[i][j].val;
                m[i][j].next_x = i + 1;
                m[i][j].next_y = j - 1;
            }
            if (m[i + 1][j].max + m[i][j].val > m[i][j].max) {
                m[i][j].max = m[i + 1][j].max + m[i][j].val;
                m[i][j].next_x = i + 1;
                m[i][j].next_y = j;
            }
            if (m[i + 1][j + 1].max + m[i][j].val > m[i][j].max) {
                m[i][j].max = m[i + 1][j + 1].max + m[i][j].val;
                m[i][j].next_x = i + 1;
                m[i][j].next_y = j + 1;
            }
            if (i == 1 && m[i][j].max > best) {
                best = m[i][j].max;
                start = j;
            }
        }
    }
    std::cout << best << "\n" << start << "\n";
    for (int i = 1, j = start, tmp; i < row;) {
        tmp = i;
        i = m[i][j].next_x;
        j = m[tmp][j].next_y;
        std::cout << j << "\n";
    }
    return 0;
}