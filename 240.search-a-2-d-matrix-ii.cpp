/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* 
        Time: O(m + n)
        Space: O(1)
        
        r = 0 , c = n-1
        if m[r][c] > taget : c--
        if m[r][c] < taget : r++
        else: return true

        target = 5
        1. m[0][4] = 15 > target => c--
        2. m[0][3] = 11 > target => c--
        3. m[0][2] = 7  > target => c--
        4. m[0][1] = 4 > target  => r++
        5. m[1][1] = 5 == target => return true

        target = 20
        1. m[0][4] = 15 < target => r++
        2. m[1][4] = 19 < target => r++
        3. m[2][4] = 22 > target => c--
        4. m[2][3] = 16 < target => r++
        5. m[3][3] = 17 < target => r++
        6. m[4][3] = 26 > target => c--
        ...
        *. m[4][0] = 18 < target => r++ , stop search no match
        */
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int r = 0 , c = n - 1;
        while(r < m && c >= 0){
            if (matrix[r][c] > target) c--;
            else if (matrix[r][c] < target) r++;
            else return true;
        }
        return false;

    }


};
// @lc code=end

