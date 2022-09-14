#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("TAXI.INP", "r", stdin);
    freopen("TAXI.OUT", "w", stdout);

    int n, tmp, numOfTaxi = 0;
    std::vector<int> c(5, 0); // Dem so nguoi trong moi nhom
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        c[tmp]++;
    }
    
    numOfTaxi += c[4];
    if (c[3] >= c[1]) {
        numOfTaxi += c[1];
        c[3] -= c[1];
        numOfTaxi += c[3];
        c[1] = 0;
    }
    else if (c[3] < c[1]) {
        numOfTaxi += c[3];
        c[1] -= c[3];
        c[3] = 0;
    }
    numOfTaxi += c[2] / 2;
    c[2] = (c[2] % 2 == 1);   
    numOfTaxi += ((c[1] + c[2])/4 + (c[1] + c[2] % 4 != 0));
    std::cout << numOfTaxi;
    return 0;
}