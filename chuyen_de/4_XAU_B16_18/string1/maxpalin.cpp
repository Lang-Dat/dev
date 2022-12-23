/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 12:15:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

int explane_around(int l, int r, std::string &str) {
    while (l >= 0 && r <= str.size() && str[l] == str[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}
int longest_palindrome_substring(std::string &str) {
    // TC: O(n^2)
    // nhận thấy rằng là một palindrome sẽ đối xứng quanh tâm của nó
    // và sẽ có tất cả là 2n - 1 tâm
    int best = 1;
    for (int i = 0; i < str.size(); i++)
        best = std::max(best, std::max(explane_around(i, i, str), explane_around(i, i + 1, str)));
    return best;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./maxpalin.INP", "r", stdin);
    freopen("./maxpalin.OUT", "w", stdout);
    #endif

    int n;
    string str;    
    std::cin >> n >> str;

    std::cout << longest_palindrome_substring(str) << "";
    return 0;
}