/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {

        /*

        Core: How to detect whether two string share common letters?

        Sol>1 brute force O(N*N*K*K) N is the size of words, K is the size of the string of the words 
        a. Scan firsr string, put every char to set
        b. Scan every char in second string, if char in set return 'Find common letter!!'.

        Sol>2 O(N*N)
        bit - manipulation
        make char -> bit represent
        e.g. "b"    -> 0...10 {1 << char - 'a'}
             "ab"   -> 0...11

        word1 & word2 == 0 -> no common letter!! 

        */
        if (words.empty())
            return 0;
        vector<int> bits(words.size());
        int max_ = 0;

        for (int i = 0; i < words.size(); i++)
        {
            int n = 0;
            for (int j = 0; j < words[i].length(); j++)
            {
                n |= 1 << words[i][j] - 'a';
            }
            bits[i] = n;
            // for (int j = 1; j < words.size(); j++)
            for (int j = 0; j < i; j++)
            {
                // cout << "word i bit: " << bits[i] << endl;
                // cout << "word j bit: " << bits[j] << endl;
                if ((bits[i] & bits[j]) == 0)
                { // if two string not share any letters.
                    // cout << "word i: " << words[i] << endl;
                    // cout << "word j: " << words[j] << endl;
                    max_ = max(max_, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return max_;
    }
};
// @lc code=end
