#include <iostream>
#include <algorithm>

#define db(x) std::cout << #x << ": " << x << "\n";

double a[3];

int main() {
    freopen("TAMGIAC.INP", "r", stdin);
    freopen("TAMGIAC.OUT", "w", stdout);

    int t;
    std::cin >> t;
    while (std::cin >> a[0] >> a[1] >> a[2]) {
        std::sort(a, a + 3);
        if (a[0] + a[1] + a[2] == 180.0 and a[0] > 0 and a[1] > 0 and a[2] > 0) {
            if (a[2] == 90.0) std::cout << "VUONG\n";
            else if (a[2] < 90.0) std::cout << "NHON\n";
            else std::cout << "TU\n";
        } else {
            std::cout << "0\n";
        }
    }
}

//26.11 90.00 63.89
