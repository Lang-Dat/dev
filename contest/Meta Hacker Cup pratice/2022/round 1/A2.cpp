#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 500005;
int A[LIM], B[LIM];
int n, k;
void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> A[i];
    for (int i = 0; i < n; i++) std::cin >> B[i];

    int start;
    for (int i = 0; i < n; i++)
        if (B[i] == A[0]) {
            start = i;
            break;
        }

    for (int i = 0; i < n; i++, start++)
        if (A[i] != B[start % n]) {
            std::cout << "NO\n";
            return;
        }

    if ((k == 0 && A[0] != B[0]) || (k == 1 && A[0] == B[0] /* no change */))
         std::cout << "NO\n";
    else std::cout << "YES\n";
}

int main()
{
    std::cin.tie(nullptr);
    freopen("./in/consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    // freopen("./in/in.inp", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}