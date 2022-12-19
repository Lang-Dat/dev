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

        // Assignment operators:
        BigInt& operator=(const BigInt&);
        BigInt& operator=(const std::string&);
        BigInt& operator=(const long long&);

        // Unary arithmetic operators:
        BigInt operator+() const;
        BigInt operator-() const;

        // Binary arithmetic operators:
        BigInt operator+(const BigInt&) const; 
        BigInt operator-(const BigInt&) const; 
        BigInt operator*(const BigInt&) const; 
        BigInt operator/(const BigInt&) const; 
        BigInt operator%(const BigInt&) const; 
        BigInt operator+(const long long&) const; 
        BigInt operator-(const long long&) const; 
        BigInt operator*(const long long&) const; 
        BigInt operator/(const long long&) const; 
        BigInt operator%(const long long&) const; 
        BigInt operator+(const std::string&) const; 
        BigInt operator+(const std::string&) const; 
        BigInt operator-(const std::string&) const; 
        BigInt operator*(const std::string&) const; 
        BigInt operator/(const std::string&) const; 
        BigInt operator%(const std::string&) const; 

        // Relation operator:
        bool operator<(const BigInt&) const;
        bool operator>(const BigInt&) const;
        bool operator<=(const BigInt&) const;
        bool operator>=(const BigInt&) const;
        bool operator==(const BigInt&) const;
        bool operator!=(const BigInt&) const;
        bool operator<(const long long&) const;
        bool operator>(const long long&) const;
        bool operator<=(const long long&) const;
        bool operator>=(const long long&) const;
        bool operator==(const long long&) const;
        bool operator!=(const long long&) const;
        bool operator<(const std::string&) const;
        bool operator>(const std::string&) const;
        bool operator<=(const std::string&) const;
        bool operator>=(const std::string&) const;
        bool operator==(const std::string&) const;
        bool operator!=(const std::string&) const;
        
        // Conversation function:
        std::string to_string() const;
        int to_int() const;
        long long to_long_long() const;

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

// Assignment operators:
BigInt& BigInt::operator=(const BigInt& num) {
    value = num.value;
    sign = num.sign;

    return *this;
}

BigInt& BigInt::operator=(const std::string& num) {
    BigInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

BigInt& BigInt::operator=(const long long&) {

}
/*
    ===========================================================================
    I/O stream operators
    ===========================================================================
*/

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


/*
    ===========================================================================
    unary arithmetic operators
    ===========================================================================
*/

BigInt BigInt::operator+() const {
    return *this;
}

BigInt BigInt::operator-() const {
    BigInt temp;
    temp.value = value;
    if (value != "0") {
        if (sign == '+')
            temp.sign = '-';
        else 
            temp.sign = '+';
    }

    return temp;
}

/*
    ===========================================================================
    Binary arithmetic operators:
    ===========================================================================
*/

BigInt BigInt::operator+(const BigInt &num) const {
    // if the sign is opposite do subtraction
    if (sign == '+' and num.sign == '-') {
        BigInt rhs = num;
        rhs.sign = '+';
        return *this - rhs;
    } else if (sign == '-' and num.sign == '+') {
        BigInt lhs = *this;
        lhs.sign = '+';
        return num - lhs;
    }

    BigInt result;
    short carry, last_sum;
    std::string larger, smaller;
    if (*this >= num) {
        larger = this->value;
        smaller = num.value;
    } else {
        larger = num.value;
        smaller = this->value;
    }

    for (int i = smaller.size(); i >= 0; i--) {
        last_sum = smaller[i] - '0' + larger[i] - '0' + carry;
        result.value = std::to_string(last_sum % 10) + result.value;
        carry = last_sum / (short) 10;
    }
    if (carry)
        result.value = std::to_string(carry) + result.value;

    if (sign == '-' and result.value != "0")
        result.sign = '-';

    return result;
}


BigInt BigInt::operator-(const BigInt& num) const {
    if (sign == '+' and num.sign == '-') {
        BigInt rhs = num;
        rhs.sign = '+';
        return *this + rhs;
    } else if (sign == '-' and num.sign == '+') {
        BigInt lhs = *this;
        lhs.sign = '+';
        return -(lhs + num);
    }

       
}
int main() {
    BigInt num;
    num = BigInt("12143432");
    std::cout << num;
    while (std::cin >> num)
        std::cout << num << "";
}