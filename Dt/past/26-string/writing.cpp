/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 03:46:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

int freq_org[129], freq[129];

bool check() {
    for (int i = 0; i < 129; i++)
        if (freq[i] != freq_org[i])
            return false;
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./writing.INP", "r", stdin);
    freopen("./writing.OUT", "w", stdout);
    #endif

    int n, s, count = 0;
    string g, str;
    std::cin >> n >> s >> g >> str;

    for (int i = 0; i < n; i++) {
        freq_org[g[i]]++;
        freq[str[i]]++;
    }

    freq[str[n - 1]]--;

    for (int i = n - 1; i < s; i++) {
        freq[str[i]]++;
        count+= check();
        freq[str[i - n + 1]]--;
    }

    std::cout << count << "";
    return 0;
}