#include <iostream>
#include <cstring>
#include <algorithm>

namespace bruceForce
{
    // using only recursion -> bruceForce
    int lcs(int last1, int last2, std::string text1, std::string text2) {
    if (last1 < 0 || last2 < 0) return 0;
    else if (text1[last1] == text2[last2]) return 1 + lcs(last1 - 1, last2 - 1, text1, text2);
    else return std::max(lcs(last1 - 1, last2, text1, text2), lcs(last1, last2 - 1, text1, text2));
    return 0;
    }

    int longestCommonSubsequence(std::string text1, std::string text2) {
        return lcs(text1.size() - 1, text2.size() - 1, text1, text2);    
}
} // namespace bruceForce

const int LIM = 1e4 + 1;
int m[2][LIM];

namespace dp
{
    // using recursion + memory -> dynamic programing
    int longestCommonSubsequence(std::string text1, std::string text2) {
        for (int i = 0; i < text1.size(); i++)
            for (int j = 0; j < text2.size(); j++)
                if (text1[i] == text2[j]) m[!(i % 2)][j+1] = 1 + m[i % 2][j];
                else m[!(i % 2)][j+1] = std::max(m[i % 2][j+1], m[!(i % 2)][j]);
        return m[text1.size() % 2][text2.size()];
    }
} // namespace dp

class Solution {
public:
    /*int longestCommonSubsequence_sub(std::vector<std::vector<int>>& container, string& text1, int size2, int index1, int index2, int count, std::vector<std::vector<int>>& mem) {
        if (index1 == text1.size() || index2 == size2) {
            return count;
        }
        std::vector<std::vector<int>> container_temp = container;
        if (mem[index1][index2] != -1) {
            return mem[index1][index2] + count;
        }
        for (int index = index1; index < text1.size(); index++) {
            for (auto it = container[text1[index] - 'a'].begin(); it != container[text1[index] - 'a'].end(); it++) {
                if (*it >= index2) {
                    std::vector<std::vector<int>> container_temp = container;
                    int temp = *it;
                    *it = -1;
                    mem[index1][index2] = std::max(longestCommonSubsequence_sub(container, text1, size2, index + 1, temp + 1, count + 1, mem), longestCommonSubsequence_sub(container_temp, text1, size2, index1 + 1, index2, count, mem)) - count;
                    return mem[index1][index2] + count;
                }
            }
        }
        return count;
    }

    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> container(26);
        std::vector<int> temp(1000, -1);
        std::vector<std::vector<int>> mem(1000, temp);
        int size = text2.size();
        for (int index = 0; index < size; index++) {
            container[text2[index] - 'a'].emplace_back(index);
        }
        int op = longestCommonSubsequence_sub(container, text1, text2.size(), 0, 0, 0, mem);
        return op;
    }*/
    // int longestCommonSubsequence(string &a, string &b) {
    //     short m[2][1000] = {};
    //     for (int i = 0; i < a.size(); ++i)
    //         for (int j = 0; j < b.size(); ++j)
    //             m[!(i % 2)][j + 1] = a[i] == b[j] ? m[i % 2][j] + 1 : max(m[i % 2][j + 1], m[!(i % 2)][j]);
    //     return m[a.size() % 2][b.size()];
    // }
};

int main() {
    std::cout << dp::longestCommonSubsequence("abc", "def");
}