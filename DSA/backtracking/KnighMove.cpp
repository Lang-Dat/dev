#pragma GCC optimize("O2")

#include <iostream>
#include <iomanip> // setw()
#include <vector>

#define log(x) std::cout << x << " ";
#define logl(x) std::cout << x << std::endl;

class BackTrackingSolution
{
public:
	const int N;
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	BackTrackingSolution(int n)
		: N(n) { solveKT(); }

	bool isSafe(int x, int y)
	{
		return (x >= 0 && x < N && y >= 0 && y < N);
	}
	void solveKT()
	{
		// Time Complexity :
		// There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8N^2).
		// Auxiliary Space: O(N2)

		std::vector<std::vector<int>> sol(N, std::vector<int>(N, -1));
		// index sol[i][j] equal sol[i*N + j]
		sol[0][0] = 0;

		if (solveKTUtil(0, 0, 1, sol))
		{
			printSolution(sol);
		}
		else
		{
			logl("Solution does not exist");
			// printSolution(sol);
		}
	}

	bool solveKTUtil(int x, int y, int moveCount, std::vector<std::vector<int>> &sol)
	{
		if (moveCount == N * N)
			return true;
		for (int k = 0; k < 8; k++)
		{
			int next_x = x + xMove[k];
			int next_y = y + yMove[k];
			if (isSafe(next_x, next_y) && sol[next_x][next_y] == -1)
			{
				sol[next_x][next_y] = moveCount;
				if (solveKTUtil(next_x, next_y, moveCount + 1, sol))
					return true;
				else
					sol[next_x][next_y] = -1; // backtracking
			}
		}
		return false;
	}

	void printSolution(std::vector<std::vector<int>> sol)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
				// log(sol[x][y]);
				std::cout << " " << std::setw(2) << sol[x][y] << " ";
			logl("");
		}
		logl("");
	}
};

int main()
{
	int N = 8;
	// std::cin >> N;
	BackTrackingSolution object(N);
}