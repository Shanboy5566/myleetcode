/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() & 1 == 1)
            return false;
        stack<char> seen;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                seen.push(c);
            }
            else
            {
                if (seen.size() == 0)
                    return false;
                char top = seen.top();
                if ((top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']'))
                    seen.pop();
                else
                    return false;
            }
        }

        return seen.size() == 0;
    }
};
// @lc code=end
