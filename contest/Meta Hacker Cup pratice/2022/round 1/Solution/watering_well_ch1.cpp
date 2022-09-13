#include <iostream>
using namespace std;

const int LIM = 500000;
const int LIM2 = 3005;
const int MOD = 1000000007;

int N, Q;
int A[LIM], B[LIM];

int solve() {
  int cntX[LIM2] = {0}, cntY[LIM2] = {0};
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    cntX[A[i]]++;
    cntY[B[i]]++;
  }
  cin >> Q;
  long long X, Y, ans = 0;
  for (int i = 0; i < Q; i++) {
    cin >> X >> Y;
    for (int x = 0; x < LIM2; x++) {
      ans = (ans + ((long long)cntX[x]*(X - x) % MOD)*(X - x)) % MOD;
    }
    for (int y = 0; y < LIM2; y++) {
      ans = (ans + ((long long)cntY[y]*(Y - y) % MOD)*(Y - y)) % MOD;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
