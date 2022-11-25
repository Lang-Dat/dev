/**
 *	author: Lang Dat
 *	create: 18-11-2022 58:17:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
static const int LIM = 1e4 + 5;
int arr[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4_trau.OUT", "w", stdout);
    #endif

    arr[1] = 1;
    int n;
    std::cin >> n;
    for (int i = 1; 2*i + 1 <= n; i++) {
        arr[2*i] = 2*arr[i] + 1;
        arr[2*i + 1] = 3*arr[i] + 1;
    }
    sort(arr, arr + n + 1);
    // for (int i = 0; i < 20; i ++)
    //     std::cout << arr[i] << " ";
        // db(i, arr[i])
    std::cout << arr[n] << "";
    return 0;
}