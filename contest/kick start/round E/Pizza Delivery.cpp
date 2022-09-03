#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int N, P, M, Ar, Ac, maxMoney = 0;
map<char, pair<char, int>> ops; // Huong: {op, k}
// vector<vector<int>> matrix(10, vector<int>(10, 0));
int matrix[10][10];

int calMoney(char huong, int money)
{
    auto[op, k] = ops[huong];
    if (op == '+') return money += k;
    if (op == '-') return money -= k;
    if (op == '*') return money *= k;
    else return money /= k;
}

void dfs(int x, int y, int moveCount = 0, int money = 0)
{
    if (x >= 0 && y >= 0 && x < N && y < N && matrix[x][y] != -1)
    {
        // log(moveCount);
        if (moveCount == M) {
            // logm("pass");
            if (maxMoney < money) maxMoney = money;
            return;
        }

        matrix[x][y] = -1;
        dfs(x - 1, y, moveCount + 1, calMoney('N', money)); // Di len (N)
        dfs(x, y + 1, moveCount + 1, calMoney('E', money)); // Di len (E)
        dfs(x + 1, y, moveCount + 1, calMoney('S', money)); // Di xuong (S)
        dfs(x, y - 1, moveCount + 1, calMoney('W', money)); // Di len (W)
        dfs(x, y, moveCount + 1, money); // dung yen
        matrix[x][y] = 0;
    }
}

void solve(int i)
{
    // Subtest 1:
    // N: grid size
    // P: the number of pizzas to deliver
    // M: the minutes in which all pizzas should be delivered
    cin >> N >> P >> M >> Ar >> Ac;

    ops.clear();
    maxMoney = 0;
    int k;
    char op;
    cin >> op >> k; ops['N'] = {op, k}; // di len
    cin >> op >> k; ops['E'] = {op, k}; // di sang phai
    cin >> op >> k; ops['S'] = {op, k}; // di xuong
    cin >> op >> k; ops['W'] = {op, k}; // di sang trai

    dfs(Ar - 1, Ac - 1);
    cout << "Case #" << i << ": " << maxMoney << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.inp", "r", stdin);
    // freopen("in.out", "w", stdout);

    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }

    return 0;
}