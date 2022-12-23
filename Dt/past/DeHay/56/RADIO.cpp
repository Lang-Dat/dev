// https://stackoverflow.com/questions/18620942/find-the-smallest-period-of-input-string-in-on
/**
 *	author: Lang Dat
 *	create: 12.10.2022 07.17.21
**/
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> build_LIS_table(string &pattern) {
    int n = pattern.size();
    std::vector<int> table(n, 0);
    for (int i = 0, j = 1; j < n; j++) {
        while (pattern[i] != pattern[j] && i > 0) {
            i = table[i-1];
        }
        if (pattern[i] == pattern[j]) {
            i++; 
        }
        table[j] = i;
    }
    return table;
}
int find_period(string pattern) {
    std::vector<int> LIS_table = build_LIS_table(pattern);
    int k = pattern.size() - 1;
    while (k >= 0 && LIS_table[k] != 0) {
        k -= LIS_table[k];
    }
    return k + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./radio.inp", "r", stdin);
    freopen("./radio.out", "w", stdout);

    string str;
    int n;
    std::cin >> n >> str;   
    std::cout << find_period(str);
    return 0;
}