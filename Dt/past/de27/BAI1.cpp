#pragma GCC optimize("O2")
#include <iostream>
#include <stdio.h>

int main()
{
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    float n, cost = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i > 25) cost += 10300;
        else if (i > 15) cost += 9200;
        else if (i > 5) cost += 7800;
        else cost += 6500;
    }
    float vat = 0.12 * cost;
    printf("%.2f\n", cost);
    printf("%.2f\n", vat);
    printf("%.2f\n", vat + cost);




    return 0;
}