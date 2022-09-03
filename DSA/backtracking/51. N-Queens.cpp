// row: hang, col : cot
#include <iostream>
#include <vector>
#include <string.h>

int n;

std::vector<std::vector<std::string>> res;
std::vector<int> currAns;
std::vector<std::string> temp; // ["....","....","....","...."]

bool isFoundInCol(int val) {
    for (int num : currAns)
        if (num == val) return true;
    return false;
}

bool isSafe(int col, int row) {
    for (int x = col, y = row; x >= 0 && y >= 0; x--, y--)
        if (currAns[x] == y) // kiem tra duong cheo ben phai
            return false;
    for (int x = col, y = row; x >= 0 && n > y; x--, y++)
        if (currAns[x] == y) // kiem tra duong cheo ben trai
            return false;
    return col >= 0 && n > col && row >= 0 && n > row
        && !isFoundInCol(row);
}

void generalAns() {
    for (int i = 0; i < n; i++)
        temp[i][currAns[i]] = 'Q';

    res.push_back(temp);
        for (auto &str : temp)
            str = std::string(n, '.');
}

// A recursive utility function to solve N Queen problem
void dfs(int col = 0) {
    if (col == n) {
        generalAns();
        return;
    }

    for (int y = 0; y < n; y++)
    {
        if (isSafe(col, y)) {
            currAns[col] = y;
            dfs(col + 1);
            currAns[col] = -1; // backtracking
        }
        // log(y, col, currAns);
    }
}

std::vector<std::vector<std::string>> solveNQueens(int N) {
    n = N;
    currAns.resize(n, -1);
    temp.resize(n, std::string(n, '.'));

    dfs();

    return res;
}

int main()
{
    // n = 4;
    std::cin >> n;
    auto ans = solveNQueens(n);
    log(ans.size());
    // for (auto &v : ans) {
    //     std::cout << v;
    // }

    // test 
    // reset();
    // std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    // currAns[0] = 1;
    // currAns[1] = 3;
    // currAns[2] = 0;
    // currAns[3] = 2;

    // for (int i = 0; i < currAns.size() && currAns[i] != -1; i++)
    //     matrix[i][currAns[i]] = 1;
    // int x = 0, y = 0;
    // matrix[x][y] = 2;
    // std::cout << matrix;
    // log(isSafe(x, y));
}