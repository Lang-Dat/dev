#include <iostream>
#include <algorithm>

static const int LIM = 1e5 + 5;
static int nums[LIM], dp[LIM][LIM]; // dp[i][j]: kết quả nhỏ nhất khi suất phát tại i và với j bước nhảy

int main() {
//    freopen("jumfrog.inp", "r", stdin);
    freopen("./TEST21_TVPBC/jumfrog/TEST001/jumfrog.inp", "r", stdin);
//    freopen("jumfrog.out", "w", stdout);
    int n, k;

    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::cout << maximum;
}
