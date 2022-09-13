#include <iostream>
using namespace std;

using LL = long long;
const int LIM = 500000;
const int MOD = 1000000007;

inline LL add(LL a, LL b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

inline LL sub(LL a, LL b) {
  return (((a - b) % MOD) + MOD) % MOD;
}

inline LL mul(LL a, LL b) {
  return (a % MOD)*(b % MOD) % MOD;
}

int solve() {
  int N, Q;
  LL A, B, X, Y;
  LL sumA = 0, sumAsq = 0;
  LL sumB = 0, sumBsq = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    sumA = (sumA + A) % MOD;
    sumB = (sumB + B) % MOD;
    sumAsq = (sumAsq + (A*A % MOD)) % MOD;
    sumBsq = (sumBsq + (B*B % MOD)) % MOD;
  }
  cin >> Q;
  LL ans = 0;
  for (int i = 0; i < Q; i++) {
    cin >> X >> Y;
    // sum_{j} ((X - A_j)^2) = sum(X^2) - 2*X*sum(A_j) + sum(A_j^2)
    ans = add(ans, add(sub(mul(mul(X, X), N), mul(2LL*X, sumA)), sumAsq));
    ans = add(ans, add(sub(mul(mul(Y, Y), N), mul(2LL*Y, sumB)), sumBsq));
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
