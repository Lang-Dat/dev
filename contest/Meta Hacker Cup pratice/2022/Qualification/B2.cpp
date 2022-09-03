#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
using std::vector;

int R, C;
vector<vector<char>> matrix;
std::map<short, short> toaDocay; // x, y
std::set<std::pair<short, short>> cannotPlace; // x, y
std::set<std::pair<short, short>> dotCoors; // x, y

void ImpossibleCout(int &case_i) {
    std::cout << "Case #" << case_i << ": Impossible\n";
}
void PossibleCout(int &case_i) {
    std::cout << "Case #" << case_i << ": Possible\n";
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++)
            std::cout << matrix[x][y];
        std::cout << "\n";
    }
}

bool isSafe(int x, int y) {
    short c = 0;
    if (x > 0 && matrix[x-1][y] != '#' && !cannotPlace.count({x-1, y})) c++;
    if (y > 0 && matrix[x][y - 1] != '#' && !cannotPlace.count({x, y-1})) c++;
    if (R - 1 > x && matrix[x+1][y] != '#' && !cannotPlace.count({x+1, y})) c++;
    if (C - 1 > y && matrix[x][y+1] != '#' && !cannotPlace.count({x, y+1})) c++;

    if (c >= 2) return true;
    else return false;
}

void solve(int case_i)
{
    // reset var
    toaDocay.clear();
    dotCoors.clear();
    cannotPlace.clear();
    std::cin >> R >> C;
    matrix = vector<vector<char>>(R, vector<char>(C, '^'));
    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++) {
            std::cin >> matrix[x][y];
            if (matrix[x][y] == '^')
                toaDocay[x] = y;
            if (matrix[x][y] == '.')
                dotCoors.insert({x, y});
        }

    // Khi khong co cay nao ca    
    if (toaDocay.size() == 0) {
        PossibleCout(case_i);
        return;
    }
    if (R == 1 || C == 1) {
        ImpossibleCout(case_i);
        return;
    }
    

    bool isModify = true;
    while (isModify)
    {
        isModify = false;
        for (auto[x, y] : cannotPlace) {
            // if (dotCoors.count({x, y}))
                dotCoors.erase({x, y});
        }
        for (auto[x, y] : dotCoors) {
            if (!isSafe(x, y)) {
                isModify = true;
                cannotPlace.insert({x, y});
            }
        }
    }

    // Kiem tra cac cay ban dau coi co cay nao khong dat duoc khong
    for (auto[x, y] : toaDocay) {
        if (!isSafe(x, y)) {
            ImpossibleCout(case_i);
            return;
        }
    }
    
    for (auto[x, y] : dotCoors) 
        matrix[x][y] = '^';

    // std::cout << "\n";
    // for (auto[x, y] : cannotPlace) 
    //     std::cout << "(" << x << ", " << y << "); ";
    PossibleCout(case_i);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);
    
    int T;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }    

    return 0;
}