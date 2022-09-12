#include <iostream>

const int n = 5;
int pattern[n] = {5, 1, 7, 4, 3};
// int pattern[n] = {1, 1, 1, 1, 2, 1, 1, 1, 2};
int B[2*n] = {2, 4, 5, 5, 1, 7, 4, 3, 5, 1};

int LPS[n];

void computeLPS() {
    int len = 0;
    LPS[0] = 0;

    int i = 1;
    while (i < n)
    {
        if (pattern[i] == pattern[len]) {
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
        if (pattern[j] == B[i]) {
            i++;
            j++;
        }
        if (j == n) return true;
        else if (i < 2*n && pattern[j] != B[i]) {
            if (j != 0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    return false;
}
int main() {
    std::cout << KMP() << " ";;
}