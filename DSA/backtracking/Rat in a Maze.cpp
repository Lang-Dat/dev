#include <iostream>
#include <vector>

#define log(x) std::cout << " " << x << " ";
#define logl(x) std::cout << x << std::endl;
typedef std::vector<std::vector<int>> matrix;

// Complexity Analysis: 

// Time Complexity: O(2^(n^2)). 
// The recursion can run upper-bound 2^(n^2) times.
// Space Complexity: O(n^2). 
// Output matrix is required so an extra space of size n*n is needed.
class RatInAMaze
{
private:
    matrix maze;
    matrix ans;
    int maxtrixSize;
public:
    RatInAMaze(matrix _maze)
    {
        maze = _maze;
        maxtrixSize = maze.size();
        ans = matrix(maxtrixSize, std::vector<int>(maxtrixSize, 0));

        if (solveMazeUtil(0, 0))
            printSolution();
        else
            log(-1);
    }

    // A recursive utility function to solve Maze problem
    bool solveMazeUtil(int x, int y)
    {
        if (x == maxtrixSize - 1 && y == maxtrixSize - 1)
        {
            ans[x][y] = 1;
            return true;
        }

        if (isSafe(x, y))
        {
            ans[x][y] = 1;
            if (solveMazeUtil(x + 1, y) || solveMazeUtil(x, y + 1))
                return true;
            else ans[x][y] = 0;
        }
        return false;
    }

    bool isSafe(int x, int y)
    {
        return (x >= 0 && x < maxtrixSize && y >= 0 && y < maxtrixSize && 
                maze[x][y] == 1 && ans[x][y] == 0);
    }

    void printSolution()
    {
        for (int i = 0; i < maxtrixSize; i++)
        {
            for (int j = 0; j < maxtrixSize; j++)
                log(ans[i][j]);
            logl("");
        }
    }
};

int main()
{
    matrix maze = {{1, 0, 0, 0},
                   {1, 1, 1, 1},
                   {0, 1, 0, 1},
                   {1, 1, 0, 1}};

    RatInAMaze solutionObject(maze);

    return 0;
}
