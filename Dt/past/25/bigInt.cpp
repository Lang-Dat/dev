#include <iostream>

class BigInt {
    char sign;
    std::string value;
    public:
        // Contructors:
        BigInt();
        BigInt(const BigInt&);
        BigInt(const std::string&);
        BigInt(const int&);

    // I/O stream operators:
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend std::ostream& operator<<(std::ostream&, BigInt&);
};


/*
    ===========================================================================
    Utility functions
    ===========================================================================
*/

void strip_leading_zero(std::string &num) {

}

bool is_vaild_number(std::string &num) {
    return true;
}

// Contructor;

BigInt::BigInt() {
    this->sign = '-';
    this->value = "0";
}

BigInt::BigInt(const BigInt& num) {
    value = num.value;
    sign = num.sign;
}

BigInt::BigInt(const std::string& num) {
    if (num[0] == '+' or num[0] == '-') {
        std::string remain = num.substr(1);
        if (is_vaild_number(remain)) {
            value = remain;
            sign = num[0];
        } 
    } else { // no sign is defind
        if (is_vaild_number) {
            value = num;
            sign = '+';
        } else {
            throw std::invalid_argument("Input have error");
        }
    }
    strip_leading_zero(value);
}

BigInt::BigInt(const int& num) {
    BigInt(std::to_string(num));
}

// End contructor

// I/O stream operators:

std::istream& operator>>(std::istream& in, BigInt& num) {
    std::string input;
    in >> input;
    num = BigInt(input);
    return in;
}

std::ostream& operator<<(std::ostream& out, BigInt& num) {
    if (num.sign == '-' and num.value != "0") {
        out << '-';
    }
    out << num.value;

    return out;
}

int main() {
    BigInt num;
    num = BigInt("12143432");
    std::cout << num;
    while (std::cin >> num)
        std::cout << num << "";
}