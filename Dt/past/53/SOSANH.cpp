/**
 *	author: Lang Dat
 *	create: 12.10.2022 59.18.09
 *	[12.10.2022 27.02.20] Bug: quên xét trường hợp bằng 0, mất 0.75 điểm
**/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("./SOSANH.INP", "r", stdin);
    freopen("./SOSANH.OUT", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0) {
        std::cout << 0;
    } else if (c % 2 == 0) {
        if (abs(a) > abs(b)) cout << 1;
        else if (abs(a) < abs(b)) cout << -1;
        else if (abs(a) == abs(b)) cout << 0;
    } else {
        if (a > b) cout << 1;
        else if (a < b) cout << -1;
        else if (a == b) cout << 0;
    }

    return 0;
}