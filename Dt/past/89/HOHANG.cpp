/**
 *	author: Lang Dat
 *	create: 06-11-2022 30:00:10
**/
#include <iostream>
#include <cstring>
using namespace std;

int freq[28];
string s1, s2;
int T, n;

bool check() {
    std::cin >> n >> s1 >> s2;
    memset(freq, 0, sizeof freq);
    for (int i = 0; i < n; i++) {
        freq[s1[i] - 'A']--;
        freq[s2[i] - 'A']++;
    }
    for (int i : freq)
        if (i != 0)
            return false;
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./HOHANG.INP", "r", stdin);
    freopen("./HOHANG.OUT", "w", stdout);
    #endif
    
    std::cin >> T;
    while (T--) {
        std::cout << check() << "\n";
    }
    return 0;
}