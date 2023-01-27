/**
 *	author : Lăng Trọng Đạt
 *	creater: 26-01-2023 09:06:50
**/
#include <iostream>
#include <algorithm>
using namespace std;

string str;
uint64_t ans;

void solve(int start, string &num) {
    if (start == str.size()) {
        if (num != "")
            ans += stoull(num);
    } else {
        solve(start + 1, num); // exclude
        num += str[start]; 
        solve(start + 1, num); // include
        num.pop_back();
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    freopen("./MAHOA.INP", "r", stdin);
    // freopen("./MAHOA.OUT", "w", stdout);
    // #endif

    getline(cin, str);
    int start = 0, clz = 1;
    while (start < str.size() and str[start] == '0') {
        start++;
        clz++;
    }

    string num = "";
    solve(start, num);

    std::cout << ans * clz << "";

    return 0;
}