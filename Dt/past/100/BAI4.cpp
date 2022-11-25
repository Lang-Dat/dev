/**
 *	author: Lang Dat
 *	create: 18-11-2022 42:14:19
**/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define ull unsigned long long
static const int LIM = 1e6 + 5;
ull arr[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./Test/BAI4/Test01/BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif
    int n, pos = 1;
    std::set<int> s;
    std::cin >> n;
    arr[1] = 1;
    for (int i = 1; 2*i + 1 <= LIM; i++) {
        arr[2*i] = 2*arr[i] + 1;
        arr[2*i + 1] = 3*arr[i] + 1;
    }
    while (s.size() < n) {
        s.insert(arr[pos++]);
        // db(s.size(), pos, arr[pos])
    }
    std::cout << arr[pos] << "";
    // sort(arr + 1, arr + n);
    // std::cout << arr[n] << "";

    return 0;
}