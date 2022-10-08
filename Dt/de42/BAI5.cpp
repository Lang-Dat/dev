#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <cstring>

const int LIM = 10;
std::vector<std::string> ans;
char ops[LIM];
int n;

short calc(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
}

void dfs(int pos = 1) {
    if (pos == n) {
        std::string str = "";
        int sum = 1;
        for (int i = 1; i < n; i++) {
            str += (char)(i + '0');
            str += ops[i];
            sum = calc(sum, i + 1, ops[i]);
        }
        str += (char)(n + '0');
        if (sum == 0)
            ans.push_back(str);
        return;
    }
    ops[pos] = '-';
    dfs(pos + 1);
    ops[pos] = '+';
    dfs(pos + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    // freopen("./test/bai3/test3/BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    std::cin >> n;
    dfs();
    std::cout << ans.size() << "\n";
    for (std::string str : ans)
        std::cout << str << "\n";
    return 0;
}