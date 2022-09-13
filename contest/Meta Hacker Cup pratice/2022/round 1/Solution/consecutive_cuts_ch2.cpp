#include <iostream>
#include <vector>
using namespace std;

class KMP {
  const vector<int> &needle;
  vector<int> table;

 public:
  KMP(const vector<int> &needle) : needle(needle), table(needle.size()) {
    for (int i = 1, j = 0; i < (int)needle.size(); i++) {
      while (j > 0 && needle[i] != needle[j]) {
        j = table[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      table[i] = j;
    }
  }

  int find_in(const vector<int> &haystack) {
    int m = needle.size();
    if (m == 0) {
      return 0;
    }
    for (int i = 0, j = 0; i < (int)haystack.size(); i++) {
      while (j > 0 && needle[j] != haystack[i]) {
        j = table[j - 1];
      }
      if (needle[j] == haystack[i]) {
        j++;
      }
      if (j == m) {
        return i + 1 - m;
      }
    }
    return -1;
  }
};

int N, K;
vector<int> A, B;

string solve() {
  bool is_equal = A == B;
  // Check special cases.
  if (K == 0) {
    return is_equal ? "YES" : "NO";
  }
  if (N == 2) {
    if (A[0] == A[1]) {
      return "YES"; // Same numbers.
    }
    // Different numbers.
    if (is_equal) {
      return K % 2 == 0 ? "YES" : "NO";
    }
    return K % 2 == 0 ? "NO" : "YES";
  }
  // Check array is rotated by searching for B within (A + A).
  vector<int> AA(A.begin(), A.end());
  AA.insert(AA.end(), A.begin(), A.end());
  if (K == 1 && is_equal) {
    // If K = 1 and A = B, we can't match at index 0 or N-1 of (A + A),
    // since cuts of 0 or N cards are not allowed.
    AA.erase(AA.begin());
    AA.pop_back();
  }
  return KMP(B).find_in(AA) >= 0 ? "YES" : "NO";
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
