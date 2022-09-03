#include <iostream>
#include <vector>
using namespace std;

int hang, cot;
vector<vector<char>> mang;
void solve(int th)
{
    int count = 0;
    cin >> hang >> cot;
    mang = vector<vector<char>>(hang, vector<char>(cot, '.'));
    for (int x = 0; x < hang; x++)
        for (int y = 0; y < cot; y++) {
            cin >> mang[x][y];
            if (mang[x][y] == '^')
                count++;
        }

    if (count == 0) {
        cout << "Case #" << th << ": Possible\n";
        for (int x = 0; x < hang; x++) {
            for (int y = 0; y < cot; y++)
                cout << mang[x][y];
            cout << "\n";
        }
        return;
    }
    if (hang == 1 || cot == 1) {
        cout << "Case #" << th << ": Impossible\n";
        return;
    }
    if (hang > 1 && cot > 1) {
        cout << "Case #" << th << ": Possible\n";
        for (int x = 0; x < hang; x++) {
            for (int y = 0; y < cot; y++)
                cout << '^';
            cout << "\n";
        }
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }    

    return 0;
}