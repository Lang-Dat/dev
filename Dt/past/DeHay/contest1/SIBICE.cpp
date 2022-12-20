/**
 *	author: Lang Dat
 *	create: 15.10.2022 43.41.16
**/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SIBICE.INP", "r", stdin);
    freopen("./SIBICE.OUT", "w", stdout);

    int n, w, h;
    std::cin >> n >> w >> h;
    float a = sqrt(w*w+h*h), tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        if (tmp <= a) {
            std::cout << "DA\n";
        } else {
            std::cout << "NE\n";
        }
    }
    
    return 0;
}