/*
This doesn't work for TC {
    [0,0,0,0,0,0,0,0,1]
    1
    $ : WA
}
*/



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        int n = nums.size();
        int totalSum = 0;


        for (int i = 0 ; i < n ; i++)
            totalSum += nums[i];

        if (totalSum < abs(target))
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));

        //Setting the first row with 0
        for (int i = 0 ; i < totalSum + 1 ; i++) {
            dp[0][i] = 0;
        }

        //Setting the first column with 1
        for (int i = 0 ; i < n + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the matrix
        for (int i = 1 ; i < n + 1 ; i++) {
            for (int j = 1 ; j < totalSum + 1 ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 1 ;  j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }

        // Using the concept from {Count the number of subset with a given difference}
        int cnt = dp[n][(target + totalSum) / 2];

        return cnt;
    }
};

/*  This works
    Instead of for(int j = 1 ; j < totalSum + 1 ; j++) ,
    do for(int j = 0 ; j < totalSum + 1 ; j++)

    $ : WA for test case : {
        [7,9,3,8,0,2,4,8,3,9]
        0
    }

*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        int n = nums.size();
        int totalSum = 0;


        for (int i = 0 ; i < n ; i++)
            totalSum += nums[i];

        if (totalSum < abs(target))
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));

        //Setting the first row with 0
        for (int i = 0 ; i < totalSum + 1 ; i++) {
            dp[0][i] = 0;
        }

        //Setting the first column with 1
        for (int i = 0 ; i < n + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the matrix
        for (int i = 1 ; i < n + 1 ; i++) {
            for (int j = 0 ; j < totalSum + 1 ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ;  j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }

        // Using the concept from {Count the number of subset with a given difference}
        int cnt = dp[n][(target + totalSum) / 2];

        return cnt;
    }
};

/*
    This runs fine for above TC
    Added a check to see if (totalSum+target)/2 !=0 -> return 0
    $ : WA for test case : {
        [1,1,1,1,1]
        3
        O/P : 0
        Exp : 5
    }
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        int n = nums.size();
        int totalSum = 0;


        for (int i = 0 ; i < n ; i++)
            totalSum += nums[i];

        if (totalSum < abs(target) || (totalSum + target) / 2 != 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));

        //Setting the first row with 0
        for (int i = 0 ; i < totalSum + 1 ; i++) {
            dp[0][i] = 0;
        }

        //Setting the first column with 1
        for (int i = 0 ; i < n + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the matrix
        for (int i = 1 ; i < n + 1 ; i++) {
            for (int j = 0 ; j < totalSum + 1 ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ;  j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }

        // Using the concept from {Count the number of subset with a given difference}
        int cnt = dp[n][(target + totalSum) / 2];

        return cnt;
    }
};

/* This works fine for above failed TC
    instead of (totalSum+target)/2 !=0,
    do (totalSum+target)%2 !=0

    $ : Accepted 300ms 14.7MB
        Without printing the dp matrix -> 12ms 15MB

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        int n = nums.size();
        int totalSum = 0;


        for (int i = 0 ; i < n ; i++)
            totalSum += nums[i];

        if (totalSum < abs(target) || (totalSum + target) % 2 != 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));

        //Setting the first row with 0
        for (int i = 0 ; i < totalSum + 1 ; i++) {
            dp[0][i] = 0;
        }

        //Setting the first column with 1
        for (int i = 0 ; i < n + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the matrix
        for (int i = 1 ; i < n + 1 ; i++) {
            for (int j = 0 ; j < totalSum + 1 ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ;  j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }

        // Using the concept from {Count the number of subset with a given difference}
        int cnt = dp[n][(target + totalSum) / 2];

        return cnt;
    }
};


/*

Reason for Starting with j = 1

Thanks for this DP series Aditya! Great tutorial but I spotted one small potential mistake in the initialization part at 10:40. The problem is, that initializing the entire column with 1 will work only if the input array has all non-zero elements.

As me and a few others have pointed out, the method fails when the input array has any zeros.
For eg: n=3, sum=0.
We can have a set here as {0,1,2}, so there'll be subsets of {} and {0} possible hence count will be 2. This is true for multiple other input arrays where actually count >1 for sum=0, but we initialized count=1 for all input arrays when sum=0.

Here's a small fix I found to the issue:

We initialize the first column of the array acc to the formula: 2 ^ (no of zeros in the array at that size).

Hence, for eg: arr={0,0,1,0}, sum=0
For n=0, value will be 2^0 = 1, i.e {}
For n=1, value will be 2^1 = 2, i.e. {} and {0}
For n=2, value will be 2^2= 4, i.e. {}, {0}, {0} and {0,0}
For n=3, value will be 2^2 = 4, i.e. {}, {0], {0}, and {0,0}
For n=4, value will be 2^3 = 8 i.e. {}, .............., {0,0,0}

Reason:
In the sum of subset problem, we simply needed to return whether or not a set exists for sum=0, which was always True as empty set {} was always existing. Here, we need to return count of subsets for sum=0 (for first column), which will include all possible subsets in the array which add up to 0.



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Alternative to this :

For those who has problem with test case  [0,0,0,0,0,0,0,0,1], target = 1.

The solution doesn't consider presence of "0"s in the array. Why the output is different ?

Because, if we have "0", then, it can have +0 and -0 and still will not effect the sum of a set. For example: Target value is = 2

1) {0,2} = {+0,2}, {-0,2}.  Ans: 2

But if we increase number of 0s,

2) {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2} . Ans: 4



So, if you observe, your answer increase by (2^number of 0s) i.e. pow(2,number of zeros).

So, make a small change as follows:

1) on count of subsetsum function,

if(nums[i-1] > j )    => change to:  if (nums[i-1] > j || nums[i-1] == 0)

      dp[i][j] = dp[i-1][j];

 //make no change and put the previous value as it is in the next subproblem. (I.e. 2, in example above)

And then at the end, you answer will be

return (int)Math.pow(2, number of 0s) * dp[nums.length][target] ;

Also, other cases we need to handle is:
if (S > sum || (sum + S) % 2 != 0){ //S is target

            return 0;

 }


*/

