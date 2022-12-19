/**
 *	author: Lăng Trọng Đạt
 *	create: 13-12-2022 24:39:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

// Unsigned bigint class
class BigInt {
    public:
        string val;
        BigInt();
        BigInt(const int&);
        BigInt(const BigInt&);
        BigInt& operator=(const BigInt&);
        BigInt operator+(const BigInt&);

};

BigInt::BigInt() {
    val = "0";
}
BigInt::BigInt(const int& num) {
    val = std::to_string(num);
}
BigInt::BigInt(const BigInt& num) {
    val = num.val;
}
BigInt& BigInt::operator=(const BigInt& num) {
    val = num.val;
    return *this;
}

BigInt BigInt::operator+(const BigInt& num) {
    std::string smaller, larger;
    if (val >= num.val) {
        larger = val;
        smaller = num.val;
    } else {
        smaller= num.val;
        larger = val;
    }

    smaller = std::string(larger.size() - smaller.size(), '0') + smaller;
    BigInt result;      
    result.val = "";  
    short carry = 0, sum;
    // add the two vals

    for (long i = larger.size() - 1; i >= 0; i--) {
        sum = larger[i] - '0' + smaller[i] - '0' + carry;
        result.val = std::to_string(sum % 10) + result.val;
        carry = sum / (short) 10;
    }
    if (carry)
        result.val = std::to_string(carry) + result.val;

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./fibonaci.INP", "r", stdin);
    freopen("./fibonaci.OUT", "w", stdout);
    #endif

    BigInt prev(1), curr(1);
    int n;
    std::cin >> n;

    for (int i = 3; i <= n; i++) {
        BigInt tmp(curr);
        curr = curr + prev;
        prev = tmp;
    }

    std::cout << curr.val << "";
    return 0;
}