#include <iostream>
#include <vector>
#include <cstring>

std::vector<int> LPS(std::string str) {
    // TC: O(|str|)
    int n = str.size();
    std::vector<int> lps(n);
    lps[0] = 0;
    int i = 0, j = 1;
    //         0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    //         a a b a a b a a b a  a  c  b  a  c
    // lps = { 0 1 0 1 2 3 4 5 6 7  8  0  0  1  0 } 
    while (j < n) {
        if (str[i] == str[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        }    
        else if (i == 0) {
            lps[j] = 0;
            j++;
        }
        else /* i != 0 */
            i = lps[i - 1];
    }
    return lps;
}

std::vector<int> KMP(std::string str, std::string pattern)
{
    std::vector<int> lps = LPS(str);
    std::vector<int> foundAtIndex;
    
    int i = 0, j = 0;
    // index:   0 1 2 3 4
    // pattern: i s s i p
    // index:   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // str:     m i s s i s s i p p  i
    while (i < str.length())
    {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.length()) {
            foundAtIndex.push_back(i - j); // Khi tim thay thi i se la vi tri cuoi cung cua pat
            j = lps[j - 1];
        }    

        // mismatch after j match
        else if (j == 0 && str[i] != pattern[j])
            i++;
        else if (j != 0 && str[i] != pattern[j])
            j = lps[j - 1];

    }
    
    return foundAtIndex;
}
int main()
{
    std::string str = "mississippi";
    std::string pattern = "issip";

    std::vector<int> foundAtIndex = KMP(str, pattern);
    log(foundAtIndex);
    // std::cin >> str;
}