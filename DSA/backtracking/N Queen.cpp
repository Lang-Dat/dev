#include <iostream>
#include <vector>
#include <chrono>

#define log(x) std::cout << " " << x << " ";
#define logl(x) std::cout << x << std::endl;
typedef std::vector<std::vector<int>> matrix;



class NQueenSolution
{
    int N;
    matrix ans;
public:
    NQueenSolution(int n)
        : N(n)
    {
        ans = matrix(N, std::vector<int>(N, 0));
        if (solveUtil(0)) printSolution();
        else logl("No solution found");
    }

    bool isSafe(int row, int col)
    {
        for (int i = 0; i < N; i++)
            if (ans[i][col]) return false;

        // kiem tra duong cheo ben phai
        for (int r = row, c = col; r >= 0 && c < N; r--, c++)
            if (ans[r][c]) return false;

        // kiem tra duong cheo ben trai
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
            if (ans[r][c]) return false;
            
        return true;
    }

    // A recursive utility function to solve N Queen problem
    bool solveUtil(int row)
    {   
        if (row == N) return true;

        for (int col = 0; col < N; col++)
        {
            if (isSafe(row, col))
            {
                ans[row][col] = 1;
                if (solveUtil(row + 1)) return true;
                else ans[row][col] = 0;
            }
        }

        return false;
    }

    void printSolution()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                log(ans[i][j]);
            logl("");
        }
    }
};

int main()
{   
    int N;
    std::cin >> N;
    NQueenSolution object(N);
}