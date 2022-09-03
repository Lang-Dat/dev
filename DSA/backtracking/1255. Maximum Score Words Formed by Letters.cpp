#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;


// Runtime: 169 ms
// Memory Usage: 47 MB
class Solution1
{
public:
    map<char, short> countGivenLetters;
    map<string, pair<short, map<char, short>>> wordsInfo;
    set<string> ignoreWord;

    int res = 0;
    int n;

    void debugInfo() {
        for (auto[word, info] : wordsInfo) 
        {
            auto[score, count] = info;
            for (auto[letter, countt] : count)
                std::cout << letter << ": " << countt << " ";
            log(word, score);
        }
        log(ignoreWord);
        std::cout << "countGivenLetters: ";
        for (auto &p : countGivenLetters)
            cout << p.first << " : " << p.second << "; ";    
    }

    short countingScore(vector<string> &wordsChoice)
    {
        // asume that wordsChoice is valid set
        short score = 0;
        for (string word : wordsChoice) 
            score += wordsInfo[word].first;

        return score;
    }

    bool isValid(vector<string> &wordsChoice)
    {
        map<char, short> count;
        for (string word : wordsChoice) {
            map<char, short> countLetter = wordsInfo[word].second;
            for (auto[c, counting] : countLetter)
                count[c] += counting;
        }
        for (auto[cha, counting] : count) {
            if (countGivenLetters[cha] - counting < 0) return false;
        }

        return true;
    }

    // generate all valid subset
    void dfs(vector<string>& words, vector<string> wordsChoice, int pos = 0)
    {
        if (isValid(wordsChoice))
        {
            if (pos == n) {
                short score = countingScore(wordsChoice);
                if (score > res) res = score;
                return;
            }

            dfs(words, wordsChoice, pos + 1);           // exclude
            if (!ignoreWord.count(words[pos])) {
                wordsChoice.push_back(words[pos]);
                dfs(words, wordsChoice, pos + 1);       // include
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scores) {
    // preprocess
    n = words.size();
    for (char letter : letters)
        countGivenLetters[letter]++;

    // get word score and count letter in word
    for (string word : words)
    {
        short score = 0;
        map<char, short> count;

        for (char c : word) {
            // tuc la tu nay co mot ki tu khong dc cho
            if (countGivenLetters.count(c) == 0) {
                ignoreWord.insert(word);
                goto cnt;
            }
            score += scores[c - 'a'];
            count[c]++;
        }

        wordsInfo[word] = {score, count};
        cnt:;
    }
    
    vector<string> wordsChoice = {};
    dfs(words, wordsChoice);
    return res;
}
};

// Runtime: 12 ms, faster than 69.96% 
// Memory Usage: 18.4 MB, less than 56.56% 
class Solution3
{
public:
    int MaxScore(int pos, vector<string>& words, vector<int> &char_score, vector<int> letter_count)
    {
        if (pos == words.size()) return 0;

        int excluding = MaxScore(pos + 1, words, char_score, letter_count);

        // Doan nay de xem co nen tinh so nay hay khong
        // Cai tien doan nay se mang lai hieu qua dang ke
        int score = 0;
        for (char c : words[pos]) {
            if (letter_count[c - 'a'] > 0) {
                score += char_score[c - 'a'];
                letter_count[c - 'a']--;
            }
            else
                // Vi neu vao truong hop nay thi excluding = including nen ta khong phai tinh no hai lan
                // dong nay lam runtime giam di rat nhieu
                return excluding;
        }

        int including = MaxScore(pos + 1, words, char_score, letter_count) + score;
        return (including > excluding) ? including : excluding;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> letter_count(26);
        for (char c : letters)
            letter_count[c - 'a']++;

        return MaxScore(0, words, score, letter_count);
    }
};

int main()
{
    // test 1
    // Output: 23
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> scores = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    // Explanation:
    // Score  a=1, c=9, d=5, g=3, o=2
    // Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
    // Words "dad" and "dog" only get a score of 21.

    // test 2
    // Output: 27
    // vector<string> words = {"xxxz","ax","bx","cx"};
    // vector<char> letters = {'z','a','b','c','x','x','x'};
    // vector<int> scores = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    
    // test 3
    // Output: 0
    // vector<string> words = {"leetcode"};
    // vector<char> letters = {'l','e','t','c','o','d'};
    // vector<int> scores = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    
    Solution2 obj;
    int ans = obj.maxScoreWords(words, letters, scores);
    log(ans);

    return 0;
}