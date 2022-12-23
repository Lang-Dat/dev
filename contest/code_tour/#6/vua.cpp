/**
 *	author: Lang Dat
 *	create: 30-10-2022 36:04:07
**/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./vua.INP", "r", stdin);
    // freopen("./vua.OUT", "w", stdout);

    char x, y, t_x, t_y; // x la so, y la chu
    std::vector<string> ans;
    std::cin >> y >> x >> t_y >> t_x;
    // db(x, y, t_x, t_y)
    while (x != t_x || y != t_y) {
        if (t_x > x) {
            if (t_y > y) {
                ans.push_back("RU");
                x++;
                y++;
            } else {
                ans.push_back("LU");
                x++;
                y--;
            }
        } else if (t_x < x) {
            if (t_y > y) {
                ans.push_back("RD");
                x--;
                y++;
            } else {
                ans.push_back("LD");
                x--;
                y--;
            }
        }
        // db(x, y)
    }   
    while (t_x != x || t_y != y) {
        if (t_x == x) {
            if (t_y > y) {
                ans.push_back("R");
                y++;
            } else {
                ans.push_back("L");
                y--;
            }
        } else if (t_y > y) {
            if (t_x > x) {
                ans.push_back("U");
                x++;
            } else {
                ans.push_back("D");
                x--;
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (string s : ans) 
        std::cout << s << "\n";
    return 0;
}
