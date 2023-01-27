/**
 *	author : Lăng Trọng Đạt
 *	creater: 26-01-2023 09:06:50
**/
#include <iostream>
#include <algorithm>
using namespace std;


// BigInt utility
inline int val(char &c) {
    return c - '0';
}

// cộng giá trị số của hai chuỗi
std::string plus_str(string a, string b) {
    if (a.size() <= b.size()) {
        b = '0' + b;
        a = string(b.size() - a.size(), '0') + a;
    } else {
        a = '0' + a;
        b = string(a.size() - b.size(), '0') + b;
    } // bây giờ hai chuỗi có cùng chiều dài
    bool carry = false;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = val(a[i]) + val(b[i]) + carry;
        carry = (sum >= 10);
        a[i] = (sum % 10) + '0';
    }
    return (a[0] == '0' ? a.substr(1) : a);
}

std::string operator*(string a, int multiplier) {
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int curr = val(a[i]) * multiplier + carry;
        carry = curr / 10;
        a[i] = curr % 10 + '0';
    }
    return (carry ? (char)(carry + '0') + a : a);
}

std::string operator*(string &a, string &multiplier /* nhân tử */) {
    string res = "";
    for (int i = multiplier.size() - 1, exponent = 0; i >= 0; i--, exponent++) {
        res = plus_str(res, a*val(multiplier[i]) + string(exponent, '0'));
    }    
    return res;
}

/// 
string str;
string ans = "", clz = "1";

void solve(int start, string &num) {
    if (start == str.size()) {
        if (num != "")
            ans = plus_str(ans, num);
    } else {
        solve(start + 1, num); // exclude
        num += str[start]; 
        solve(start + 1, num); // include
        num.pop_back();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MAHOA.INP", "r", stdin);
    freopen("./MAHOA.OUT", "w", stdout);
    #endif

    getline(cin, str);
    int start = 0;
    while (start < str.size() and str[start] == '0') {
        start++;
        clz = plus_str(clz, "1");
    }

    string num = "";
    solve(start, num);

    std::cout << ans * clz << "";

    return 0;
}