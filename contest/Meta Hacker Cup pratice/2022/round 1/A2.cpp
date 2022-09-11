#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 500005;
int A[LIM], B[2*LIM], LPS[LIM];
int n, k, tmp;

void computeLPS() {
    int len = 0;
    LPS[0] = 0;

    int i = 1;
    while (i < n)
    {
        if (A[i] == A[len]) {
            len++;
            LPS[i] = len;
            i++;
        }
        else if (len == 0) {
            LPS[i] = 0;
            i++;
        }
        else if (len != 0) {
            len = LPS[len - 1];
        }
    }
}
bool KMP() {
    computeLPS();
    int i = 0, j = 0;
    while ((2*n - i) >= (n - j))
    {
        if (A[j] == B[i]) {
            i++;
            j++;
        }
        if (j == n) return true;
        else if (i < 2*n && A[j] != B[i]) {
            if (j != 0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    return false;
}

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> A[i];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        B[i] = tmp;
        B[i + n] = tmp;
    }
    if (!KMP()) {
        std::cout << "NO\n";
        return;
    }

    if (((k == 0 || (n == 2 && k % 2 == 0)) && A[0] != B[0]) || 
        ((k == 1 || (n == 2 && k % 2 == 1)) && A[0] == B[0]))
         std::cout << "NO\n";
    else std::cout << "YES\n";
}

int main()
{
    std::cin.tie(nullptr);
    freopen("./in/consecutive_cuts_chapter_2_input.txt", "r", stdin);
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