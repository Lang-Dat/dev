/**
 *	author: Lăng Trọng Đạt
 *	create: 04-12-2022 41:08:10
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string period(string num) {
    // TC: O(n^2) ~ O(250^2)
    string tmp = "";
    tmp += num.front();
    for (int i = 1; i < num.size(); i++) {
        tmp += num[i];
        for (int j = i + 1; j < num.size(); j++) {
            if (num[j] != tmp[j % i]) goto cnt;
        }
        tmp.pop_back();
        return tmp;
        cnt:;
    }
    return "";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n, m;
    std::cin >> n >> m;
    cout << n / m << ".";
    n -= n / m * m;

    string phan_du = "";

    while (phan_du.size() < 250 and n % m != 0) {
        n *= 10;
        if (n > m) {
            phan_du += to_string(n / m);
            n -= n / m * m;
        }
    }
    if (n != 0 && phan_du.size() < 250) 
        phan_du += to_string(n / m);
    string check = period(phan_du);
    if (check == "")   
        cout << phan_du;
    else cout << "(" << check << ")";
    return 0;
}