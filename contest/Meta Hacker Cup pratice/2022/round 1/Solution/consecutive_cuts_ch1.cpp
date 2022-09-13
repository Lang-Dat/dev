#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int LIM = 500000;

int N, K;
vector<int> A, B;

string solve() {
  bool is_equal = A == B;
  // Check special cases.
  if (K == 0) {
    return is_equal ? "YES" : "NO";
  }
  if (K == 1 && is_equal) {
    return "NO";
  }
  if (N == 2) {
    if (is_equal) {
      return K % 2 == 0 ? "YES" : "NO";
    }
    return K % 2 == 0 ? "NO" : "YES";
  }
  // Check array is rotated.
  int num_out_of_order = 0;
  unordered_map<int, int> pos;
  for (int i = 0; i < N; i++) {
    pos[A[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    if (pos[B[i]] > pos[B[(i + 1) % N]]) {
      num_out_of_order++;
    }
  }
  return num_out_of_order == 1 ? "YES" : "NO";
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N >> K;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
