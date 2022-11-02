#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

const int LIM = 1e6 + 4;
const int NUM_OF_CHAR = 26;
int freq_L[NUM_OF_CHAR], freq_R[NUM_OF_CHAR];
pair<int, int> q[LIM];
int Q;
std::string str;
#define L first
#define R second

bool isBalance(int l, int r) {
    if ((r - l + 1) % 2 == 0) {
        for (int i = 0; i < NUM_OF_CHAR; i++)
            if (freq_L[i] != freq_R[i]) return false;
        return true;
    }
    else {
        // Xoa o nua ben phai
        bool isDel = false, isPass = true;
        for (int i = 0; i < NUM_OF_CHAR; i++)
            if (freq_L[i] != freq_R[i] && !isDel) {
                isDel = true;
                if (freq_L[i] != freq_R[i] - 1) {isPass = false; break;};
            }
            else if (freq_L[i] != freq_R[i] && isDel) {isPass = false; break;};
        if (isPass) return true;

        // xoa o nua ben trai
        freq_L[str[(r-l+1) / 2] - 'a']++;
        freq_R[str[(r-l+1) / 2] - 'a']--;
        isDel = false, isPass = true;
        for (int i = 0; i < NUM_OF_CHAR; i++) {
            if (freq_L[i] != freq_R[i] && !isDel) {
                isDel = true;
                if (freq_L[i] - 1 != freq_R[i]) {isPass = false; break;};
            }
            else if (freq_L[i] != freq_R[i] && isDel) {isPass = false; break;};
        }
        // freq_L[str[(r-l+1) / 2] - 'a']--;
        // freq_R[str[(r-l+1) / 2] - 'a']++;
        if (isPass) return true;
    }
    return false;
} 

void solve() {
    int ans = 0, l, r;
    std::cin >> str >> Q; 
    for (int i = 0; i < Q; i++) {
        std::cin >> l >> r;
        q[i].L = l - 1; q[i].R = r - 1;
    }
    for (int i = 0; i < Q; i++) {
        // if (i == 10005) {
        //     log(q[i].L, q[i].R) break;
        // }
        for (int i = 0; i < NUM_OF_CHAR; i++) {
            freq_L[i] = 0; 
            freq_R[i] = 0; 
        }
        for (int j = (int)q[i].L; j < (int)(q[i].R + q[i].L + 1) / 2; j++)
            freq_L[str[j] - 'a']++;
        for (int j = (q[i].R + q[i].L + 1) / 2; j <= q[i].R; j++) 
            freq_R[str[j] - 'a']++;
        // std::cout << "\n";
        // for (int i : freq_L)
        //     std::cout << i << " ";
        // std::cout << "\n";
        // for (int i : freq_R)
        //     std::cout << i << " ";
        // std::cout << "\n";

        ans += (int)isBalance(q[i].L, q[i].R);
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./in/perfectly_balanced_chapter_1_validation_input.txt", "r", stdin);
    freopen("./in/in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}