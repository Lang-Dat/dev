#include <iostream>
#include <vector>
#include <algorithm>

const double target = 24.00;
bool isFound = false;
const char ops[4] = {'+', '-', '*', '/'};
const double eps = 1e-9;
std::vector<double> cards;

double calc(double x, double y, char op)
{
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    if (op == '*')
        return x * y;
    else
        return x / y;
}

std::vector<double> getEvaluations(int l, int r)
{
    if (isFound)
        return {};
    if (l == r)
        return {cards[l]};

    std::vector<double> ret;
    for (int i = l; i < r; i++)
    {
        auto resL = getEvaluations(l, i), resR = getEvaluations(i + 1, r);

        for (auto L : resL)
        {
            for (auto R : resR)
            {
                for (char op : ops)
                {
                    if (op == '/' && R == 0)
                        continue; // avoid dividing by 0

                    ret.push_back(calc(L, R, op));

                    if (l == 0 && r == 3 && (abs(ret.back() - 24.0) < eps)) {
                        isFound = true;
                    }
                }
            }
        }
    }
    return ret;
}

bool judgePoint24(std::vector<int> &Cards)
{
    cards = std::vector<double>(Cards.begin(), Cards.end());
    std::sort(cards.begin(), cards.end());
    do
    {
        getEvaluations(0, 3);
        if (isFound)
            return true;
    } while (std::next_permutation(cards.begin(), cards.end()));

    return isFound;
}

int main()
{
    // (8 - 4) * (7 - 1) = 24
    // std::vector<int> card = {4, 1, 8, 7};
    // std::vector<int> card = {1,2,1,2};
    // std::vector<int> card = {8,1,6,6}; // true
    std::vector<int> card = {1,9,1,2}; // true

    bool ans = judgePoint24(card);
    log(ans);
}