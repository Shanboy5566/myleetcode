/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_set<string> seen;

        const int m = matrix.size(); // row
        if (m == 0){
            return ans;
        }
        const int n = matrix[0].size(); // col
        // if (m == 1 && n == 1){
        //     ans.push_back(matrix[0][0]);
        //     return ans;
        // }

        int i = 0, j = -1;
        while(seen.find("row " + to_string(i) + " col " + to_string(++j) + " seen!") == seen.end() && i < m && i >=0 && j < n && j >= 0 ){
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "===========\n";

            // j++;
            while(j < n && j >= 0 && seen.insert("row " + to_string(i) + " col " + to_string(j) + " seen!").second){ // move right
                // cout << "push!! with i: " << i << " j: " << j << endl;
                ans.push_back(matrix[i][j]);
                j++;
            }
            j--;
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "======right end=====\n";

            i++;
            while(i < m && i >= 0 && seen.insert("row " + to_string(i) + " col " + to_string(j) + " seen!").second){ // move_down
                ans.push_back(matrix[i][j]);
                i++;
            }
            i--;
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "======down end=====\n";

            j--;
            while(j < n && j >= 0 && seen.insert("row " + to_string(i) + " col " + to_string(j) + " seen!").second){ // move_left
                ans.push_back(matrix[i][j]);
                j--;
            }
            j++;
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "======left end=====\n";

            i--;
            while(i < m && i >= 0 && seen.insert("row " + to_string(i) + " col " + to_string(j) + " seen!").second){ // move_up
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "======up end=====\n";
        }
        return ans;
    }
};
// @lc code=end

