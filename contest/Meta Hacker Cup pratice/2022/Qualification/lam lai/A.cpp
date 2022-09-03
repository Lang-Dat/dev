#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
void solve(int th)
{
    int n, k, temp;
    cin >> n >> k;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        count[temp]++;
    }

    if (2 * k < n)
    {
        cout << "Case #" << th << ": "
                  << "NO\n";
        return;
    }

    for (auto &p : count)
    {
        if (p.second > 2)
        {
            cout << "Case #" << th << ": "
                      << "NO\n";
            return;
        }
    }
    cout << "Case #" << th << ": "
              << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }

    return 0;
}