#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> num_count(10);
string ans = "";

string largestPalindromic(string num) {
    for (char c: num)
        num_count[c - '0']++;

    for (int i = 9; i >= 0; i++)
    {
        int tmp = num_count[i] / 2;
        num_count[i] = num_count[i] % 2;
        if (tmp == 0) continue;
        string add = string(tmp, to_string(i)[0]);
        log(add);
        ans += add;
        ans.insert(0, add);
    }
    log(num_count);
    log(ans);
}

int main()
{
    // Input: num = "444947137"
    // Output: "7449447"   
    // Input: num = "00009"
    // Output: "9"
    string num = "444947137";
    string res = largestPalindromic(num);
    log(res);
}