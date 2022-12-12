/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 38:01:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;

bool isPalindrome(int l, int r) {
    // TC: O(r - l)
    for (; l <= r; l++, r--)
        if (str[l] != str[r])
            return false;
    return true;
}
int LPS() {
    // longest palindrome substring
    // only bruce force
    // TC: O(|str|^3)
    int best = 1;
    for (int i = 0; i < str.size(); i++) { // TC: O(|str|^2)
        for (int j = str.size() - 1; j - i + 1 > best; j--) {
            if (isPalindrome(i, j)) best = j - i + 1;
        }
    }
    return best;
}

int explane_around(int l, int r) {
    while (l >= 0 && r <= str.size() && str[l] == str[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}
int longest_palindrome_substring() {
    // TC: O(n^2)
    // nhận thấy rằng là một palindrome sẽ đối xứng quanh tâm của nó
    // và sẽ có tất cả là 2n - 1 tâm
    int best = 1;
    for (int i = 0; i < str.size(); i++)
        best = max(best, max(explane_around(i, i), explane_around(i, i + 1)));
    return best;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PASSW.INP", "r", stdin);
    freopen("./PASSW_trau.OUT", "w", stdout);
    #endif

    std::cin >> str;
    std::cout << LPS() << "";
    return 0;
}