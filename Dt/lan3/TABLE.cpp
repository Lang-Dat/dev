/**
 *	author: Lang Dat
 *	create: 08-11-2022 01:53:15
**/
#include <iostream>
using namespace std;

const int LIM = 1e3 + 5;
int nums[LIM][LIM];
int n, q, target;

void searchInMatrix(int target, int row = 0, int col = n - 1) {
    while (row < n && col > -1) {
        int curr = nums[row][col];
        if (curr > target) col--;
        else if (curr == target) {
            std::cout << row + 1 << " " << col + 1 << "\n";
            return;
        } else row++;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TABLE.INP", "r", stdin);
    freopen("./TABLE.OUT", "w", stdout);
    #endif

    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cin >> nums[i][j];
    }
    while (std::cin >> target) {
        searchInMatrix(target);
    }
    return 0;
}