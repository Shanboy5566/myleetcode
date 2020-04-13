/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (auto c : moves)
        {
            if (c == 'R')
                x++;
            else if (c == 'L')
                x--;
            else if (c == 'U')
                y++;
            else
                y--;
        }
        return (x == 0 && y == 0);
    }
};
// @lc code=end
