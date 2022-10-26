/**
 *	author: Lang Dat
 *	create: 21-10-2022 44:12:20
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MV.INP", "r", stdin);
    freopen("./MV.OUT", "w", stdout);

    int n, prev, minimum = INT32_MAX, count = 0, tmp;
    std::cin >> n >> prev;
    count += prev == 0;
    while (std::cin >> tmp) {
        if (tmp == 0) {
            count++;
        } else {
            if (count > 1 && count < minimum) {
                minimum = count;
            }
            count = 0;
        }
    }
    if (count > 1 && count < minimum) {
        minimum = count;
    }
    std::cout << minimum;

    return 0;
}