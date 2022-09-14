#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./GAME.INP", "r", stdin);
    freopen("./GAME.OUT", "w", stdout);

    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + n);
    int d = std::min(arr[1] - arr[0], arr[n-1] - arr[n-2]);
    std::vector<int> canM = {d};
    for (int i = 2; i * i <= d; i++) {
        if (d % i == 0 && i * i != d) {
            canM.push_back(i);
            canM.push_back(d/i);
        }
        else if (i * i == d)
            canM.push_back(i);
    }

    std::sort(canM.begin(), canM.end());
    
    for (int m : canM) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] % m != arr[i + 1] % m) goto cnt;
        std::cout << m << " ";
        cnt:;
    }
    return 0;
}