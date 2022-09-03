#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> nums;
const double target = 24.00;
const double eps = 1e-9;
const char ops[4] = {'+', '-', '*', '/'};
bool isFound = false;

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

std::vector<double> getEvalution(int l = 0, int r = 3)
{
    if (isFound)
        return {};
    if (l == r)
        return {nums[l]};

    std::vector<double> temp;

    for (int i = l; i < r; i++)
    {
        std::vector<double> resR = getEvalution(l, i), resL = getEvalution(i + 1, r);

        for (double L : resL)
        {
            for (double R : resR)
            {
                for (char op : ops)
                {
                    if (op == '/' && L == 0)
                        continue; // avoid division by 0
                    temp.push_back(calc(R, L, op));
                    if (l == 0 && r == 3 && abs(temp.back() - target) < eps)
                    {
                        isFound = true;
                    }
                }
            }
        }
    }
    return temp;
}

bool judgePoint24(std::vector<int> &Cards)
{
    nums = std::vector<double>(Cards.begin(), Cards.end());
    std::sort(nums.begin(), nums.end());

    do
    {
        getEvalution();
        if (isFound)
            return true;
    } while (std::next_permutation(nums.begin(), nums.end()));

    return isFound;
}

int main()
{
    // (8 - 4) * (7 - 1) = 24
    // std::vector<int> card = {4, 1, 8, 7}; // true
    // std::vector<int> card = {1,2,1,2}; // false
    // std::vector<int> card = {8, 1, 6, 6}; // true
    std::vector<int> card = {1,9,1,2}; // true
    bool ans = judgePoint24(card);
    log(ans);
}