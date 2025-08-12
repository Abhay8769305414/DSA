class Solution {
public:
    // recursion + memo TC - O(nxm) SC - O(nxm)+ O(n+m)
    bool solve(string& s, string& p, int m, int n, vector<vector<int>>& dp) {
        // base cases
        if (m < 0 && n < 0) {
            return true;
        }

        // if s is left bit the pattern is over (as first test case)
        if (m >= 0 && n < 0) {
            return false;
        }

        // below means there are some char remained in p so that can be * also
        // wo if * are there then we can make it empty so check for all are * or
        // not if anyone not found * mark it false
        if (m < 0 && n >= 0) {
            for (int i = 0; i <= n; i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        // check for the dp stored ans
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s[m] == p[n] || p[n] == '?') {
            return dp[m][n] = solve(s, p, m - 1, n - 1, dp);
        } 
        if (p[n] == '*') {
            return dp[m][n] =
                       (solve(s, p, m - 1, n, dp) || solve(s, p, m, n - 1, dp));
        }
        return dp[m][n] = false; // we have got char not matching directly
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n , -1));
        return solve(s, p, m - 1, n - 1, dp);
    }
};