/**
 *	author: Lang Dat
 *	create: 18-11-2022 15:25:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e6 + 50;
int prefix[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./Test/BAI5/Test03/BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    ull k, count = 0, n;
    string str;
    std::cin >> k >> str;
    n = str.size();
    for (int i = 1; i < n + 1; i++) {
        prefix[i] = prefix[i-1];
        if (str[i-1] == '1') prefix[i]++;
    }

    for (int i = 0; i < n + 1; i++) {
        int ind = lower_bound(prefix + i + 1, prefix + n + 1, prefix[i] + k) - prefix;
        if (prefix[ind] - prefix[i] == k) {
            ull end = lower_bound(prefix + ind + 1, prefix + n + 1, prefix[ind] + 1) - prefix;
            count += end - ind;
        }
        // db(prefix[i], ind)
    }
    std::cout << count << "";
    return 0;
}