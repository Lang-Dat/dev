/**
 *	author : Lăng Trọng Đạt
 *	creater: 27-01-2023 19:19:18
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int best = 0;

    for (int start = 0; start < s1.size(); start++) { // O(nm)
        for (int i = start, j = 0, count = 0; i < s1.size() and j < s2.size(); i++, j++) {
            (s1[i] == s2[j] ? count++ : count = 0);
            best = max(best, count);
        }
    }
    for (int start = 0; start < s2.size(); start++) { // O(nm)
        for (int i = start, j = 0, count = 0; i < s2.size() and j < s1.size(); i++, j++) {
            (s2[i] == s1[j] ? count++ : count = 0);
            best = max(best, count);
        }
    }

    std::cout << best << "";
    return 0;
}