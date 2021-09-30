/*
 Following soln works on ide but gives sigsev on GFG
    $ :Issue was for (int j = 1 ; j <  dp[0].size() ; i++)
       It should have been j++ not i++

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:

    int isSumPossible(int arr[], int n, int sum) {

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        //initialize the first row with 0
        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[0][i] = 0;
        }

        //initialize the first column with 1
        for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < dp.size() ; i++) {
            for (int j = 1 ; j <  dp[0].size() ; i++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];

    }

    int minDifference(int arr[], int n)  {

        int totalSum = 0;

        for (int i = 0 ; i < n ; i++) {
            totalSum += arr[i];
        }

        vector<int> allPossibleSums(totalSum + 1, 0);

        //calculating all possible sums which the subsets may have
        for (int i = 0 ; i <= totalSum ; i++) {
            if (isSumPossible(arr, n, i)) {
                allPossibleSums[i] = 1;
            }
        }


        int res = 0;
        for (int i = 0 ; i <= totalSum / 2 ; i++) {
            if (allPossibleSums[i])
                res = i;
        }

        //cout << "Minimum sum : " << totalSum - res;

        return totalSum - 2 * res;
    }
};


// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends


/*
    Implementing in such a way that the dp vector is created only once
    $ : Accepted & optimized
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:


    int minDifference(int arr[], int n)  {

        int totalSum = 0;

        for (int i = 0 ; i < n ; i++) {
            totalSum += arr[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));

        //initialize the first row with 0
        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[0][i] = 0;
        }

        //initialize the first column with 1
        for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < dp.size() ; i++) {
            for (int j = 1 ; j <  dp[0].size() ; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        vector<int> allPossibleSums(totalSum + 1, 0);

        //calculating all possible sums which the subsets may have
        for (int i = 0 ; i <= totalSum ; i++) {
            //if any value of that {i->sum} column is true then possible
            for (int x = 0 ; x < dp.size() ; x++) {
                if (dp[x][i] == 1) {
                    allPossibleSums[i] = 1;
                    break;
                }
            }
        }

        int res = 0;
        for (int i = 0 ; i <= totalSum / 2 ; i++) {
            if (allPossibleSums[i])
                res = i;
        }

        return totalSum - 2 * res;
    }
};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends


/*
    In the above solution, there is no need to go through all the sum columns
    instead, we can go through the last row {dp[n][x]} and if it is set to 1, it means that there is a subset of the array considering all elements which has the sum equal to x
    Hence, we can mark that {sum:x} to allPossibleSums vector to 1
    $ : Accepted

*/

class Solution {

public:


    int minDifference(int arr[], int n)  {

        int totalSum = 0;

        for (int i = 0 ; i < n ; i++) {
            totalSum += arr[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));

        //initialize the first row with 0
        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[0][i] = 0;
        }

        //initialize the first column with 1
        for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < dp.size() ; i++) {
            for (int j = 1 ; j <  dp[0].size() ; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        vector<int> allPossibleSums(totalSum + 1, 0);

        //calculating all possible sums which the subsets may have
        for (int i = 0 ; i <= totalSum ; i++) {
            //if any value of that {i->sum} column is true then possible
            for (int x = 0 ; x < dp.size() ; x++) {
                if (dp[x][i] == 1) {
                    allPossibleSums[i] = 1;
                    break;
                }
            }
        }

        int res = 0;
        for (int i = 0 ; i <= totalSum / 2 ; i++) {
            if (allPossibleSums[i])
                res = i;
        }

        return totalSum - 2 * res;
    }
};

/*
    In fact, there is no need of allPossibleSums vector too, we can directly analyze the last row of DP matrix.
    $ : accepted
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:


    int minDifference(int arr[], int n)  {

        int totalSum = 0;

        for (int i = 0 ; i < n ; i++) {
            totalSum += arr[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));

        //initialize the first row with 0
        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[0][i] = 0;
        }

        //initialize the first column with 1
        for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < dp.size() ; i++) {
            for (int j = 1 ; j <  dp[0].size() ; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int res = 0;
        for (int i = 0 ; i <= totalSum / 2 ; i++) {
            if (dp[n][i])
                res = i;
        }

        return totalSum - 2 * res;
    }
};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends
