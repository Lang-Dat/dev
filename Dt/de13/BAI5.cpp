#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>

std::vector<double> area;
std::vector<int> X;
std::vector<int> Y;

double calcArea(int numOfVertex) {
// The area is then given by the formula
// |(x1.y2 − y1.x2) + (x2.y3 − y2.x3) + .... +  (xn.y1 − yn.x1)| / 2
    double sum = 0;
    for (int i = 0; i < numOfVertex - 1; i++)
        sum += X[i]*Y[i+1] - Y[i]*X[i+1];
    sum += X[numOfVertex-1]*Y[0] - Y[numOfVertex-1]*X[0];
    sum = std::abs(sum) / 2;
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    int n, numOfVertex;
    std::cin >> n;
    area.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numOfVertex;
        X.resize(numOfVertex);
        Y.resize(numOfVertex);
        for (int j = 0; j < numOfVertex; j++)
            std::cin >> X[j] >> Y[j];
        area[i] = calcArea(numOfVertex);
    }

    std::vector<double> tmp = area;
    std::sort(tmp.begin(), tmp.end());
    for (int i : area)
        std::cout << n - 1 - (int)(std::lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin()) << "\n";
    return 0;
}