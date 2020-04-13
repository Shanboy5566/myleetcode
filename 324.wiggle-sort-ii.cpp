/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution
{
public:
    /*
        The similar question is Dutch national flag problem (https://en.wikipedia.org/wiki/Dutch_national_flag_problem)

        This problem can also be viewed in terms of rearranging elements of an array. Suppose each of the possible elements could be classified into exactly one of three categories (bottom, middle, and top). For example, if all the elements are in 0 ... 1, the bottom could be defined as elements in 0 ... 0.1 (not including 0.1), the middle as 0.1 ... 0.3 (not including 0.3) and the top as 0.3 and greater.

        The time complexity is O(N)

        In this example, supposed the input is [1, 5, 1, 1, 6, 4] and the given number is '4'. I would like to 'rerange' the input array to three parts:
        1. smaller than '4'
        2. equal '4'
        3. larger than '4'
        So the output array would be like [1, 1, 1, 4, 6, 5]

        Note: the part1 and part3 does not be sorted.

        Back to our question, what is the different between 'Wiggle Sort' and DNF?

        If!! we could manipulate the 'index' in array!!

        the odd index would smaller than 'something'
        the even index would larger than 'something'

        If we could make our lower pointer jumps correctly with the begin of odd index (e.g. 1) and upper pointer jumps correctly with the end of even index (e.g. 4)
        And we could make the path of pointer like: 1->3->5->0->2->4

        That it would be very similar with DNF!!!

        Only if we could solve this two question:
        1. how to select 'something'?
        2. how to make the pointer path like: 1->3->5->0->2->4?

        Ans:
        1. Choose median!!  nums[i] < nums[i+1] = median
        2. 
            suppose n = 6
            j           0   1   2   3   4   5
            1+2j%(n|1)  1   3   5   0   2   4

            the insight of n|1 is these might two condition with whether n is even or not.

            suppose n = 6
            j           0   1   2   3   4   5
            1+2j%n      1   3   5   1   3   5 <- Not O.K.

            suppose n = 5
            j           0   1   2   3   4
            1+2j%n      1   3   0   2   4   <- O.K.


    */
#define A(i) nums[(1 + 2 * i) % (nums.size() | 1)]
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();

        // Find median
        auto midptr = nums.begin() + (n / 2);
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (A(j) > mid) // swap j to i (odd) position
            {
                swap(A(i), A(j));
                i++;
                j++;
            }
            else if (A(j) < mid) // swap j to k (even) position
            {
                swap(A(j), A(k));
                k--;
            }
            else // j move on
            {
                j++;
            }
        }
    }
};
// @lc code=end
