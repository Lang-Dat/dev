#include <iostream>
#include <algorithm>

struct Car {
    int64_t start, end, cost;
    int k; // so lan do xang
};

static const int MAXN = 1e5 + 5;
int pos[MAXN]; // pos[i]: vi tri cua xe thu i (tang dan)
int64_t ans = 0;
Car xe;
int64_t n, so_xe;

bool check(int64_t v, Car& x) { // O(N)
    // tra ve true neu xe x co the hoan thanh nhiem vu voi luong xang la v
    int64_t cnt = -1, curr_pos = pos[x.start]; // curr_pos: vi tri cua xe tai moi thoi diem
    while (curr_pos != pos[x.end]) {
        int ind = std::upper_bound(pos + 1, pos + x.end + 1, curr_pos + v / x.cost) - pos;
        if (curr_pos == pos[ind - 1]) // nếu không thể đi đến đại lý tiếp theo thì bỏ luôn
            return false;
        cnt++; // sau mỗi lần thay đổi đại lý thì ta tăng số lần đổ xăng lên 1
        curr_pos = pos[ind - 1];
    }
    return cnt <= x.k;
}

int64_t minimum_v(Car& x) { // O(log(hi - lo))
    // tra ve luong xang toi thieu de xe x hoan thanh nhiem vu
    int64_t res = (pos[x.end] - pos[x.start]) * x.cost;
    int64_t lo = ans, hi = res; // vì ans là giá trị thể tích lớn nhất để các xe đi được nên khởi tạo lo = ans sẽ đỡ đi vài bước
    while (lo <= hi) {
        int64_t mid = (lo + hi) / 2;
        if (check(mid, x)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("DAILY.INP", "r", stdin);
    freopen("DAILY.OUT", "w", stdout);

    // TC: O(so_xe*log(max_v)*n)
    // trong đó max_v là lượng xăng tối đa một xe cần tính theo công thức
    // max_v = (pos[x.end] - pos[x.start]) * x.cost (với mọi xe)
    std::cin >> n >> so_xe;

    for (int i = 1; i <= n; i++) {
        std::cin >> pos[i];
    }
    for (int i = 0; i < so_xe; i++) { // O(so_xe)
        std::cin >> xe.start >> xe.end >> xe.cost >> xe.k;
        ans = std::max(ans, minimum_v(xe));
    }

    std::cout << ans;
}
