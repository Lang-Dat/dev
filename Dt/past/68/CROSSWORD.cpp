/**
 *	author : Lăng Trọng Đạt
 *	creater: 31-01-2023 20:49:03
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CROSSWORD.INP", "r", stdin);
    freopen("./CROSSWORD.OUT", "w", stdout);
    #endif

    string x, y;
    std::cin >> x >> y;
    int ind_x = -1, ind_y;

    do {
        ind_x++;
        ind_y = y.find(x[ind_x]);
    } while (ind_y == string::npos);
    for (int i = 0; i < ind_y; i++)
        std::cout << string(ind_x, '.') << y[i] << string(x.size() - ind_x - 1, '.') << "\n";
    std::cout << x << "\n";
    for (int i = ind_y + 1; i < y.size(); i++)
        std::cout << string(ind_x, '.') << y[i] << string(x.size() - ind_x - 1, '.') << "\n";
    return 0;
}