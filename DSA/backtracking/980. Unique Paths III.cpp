// https://leetcode.com/problems/unique-paths-iii/

#include <iostream>
#include <vector>
// You are given an m x n integer array grid where grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.

typedef std::vector<std::vector<int>> matrix;

int count = 0;
int zeroSquareCount = 0;

bool isSafe(int x, int y, matrix& grid) {
    return x >= 0 && x < (int)grid.size()
        && y >= 0 && y < (int)grid[0].size()
        && grid[x][y] != -1;
}

void dfs(int x, int y, int moveCount, matrix& gird) {
    if (isSafe(x, y, gird)) {
        if (gird[x][y] == 2) {
            if (moveCount == zeroSquareCount)
                count++;
            return;
        }
        gird[x][y] = -1;
        dfs(x + 1, y, moveCount + 1, gird);
        dfs(x - 1, y, moveCount + 1, gird);
        dfs(x, y + 1, moveCount + 1, gird);
        dfs(x, y - 1, moveCount + 1, gird);
        gird[x][y] = 0; // Important of backtracking
    }
}

int uniquePathsIII(matrix& grid) {
    int x, y;
    for (int i = 0; i < (int)grid.size(); i++)
        for (int j = 0; j < (int)grid[0].size(); j++)
        {
            if (grid[i][j] == 0) zeroSquareCount++;
            else if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    
    dfs(x, y, 1, grid);
    return count;
}

int main()
{
    // Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
    // Output: 2
    // Explanation: We have the following two paths: 
    // 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
    // 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
    matrix grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // matrix grid = {{1,0,0,0},
    //                {0,0,0,0},
    //                {0,0,0,2}};
    int ans = uniquePathsIII(grid);
    log(ans);
}