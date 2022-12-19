/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 09:54:07
**/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;


#define PI 3.141592 //65358979323846

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    double a, goc, h;
    std::cin >> a >> goc >> h;

    double ans = a / tan(goc * PI / 180) + h;
    printf("%.3f", ans);

    return 0;
}