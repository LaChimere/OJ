#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for (int j = 1; j <= len2; j++)
            dp[0][j] = dp[0][j - 1] + 1;
        for (int i = 1; i <= len1; i++)
            dp[i][0] = dp[i - 1][0] + 1;
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++){
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        }
        
        return dp[len1][len2];
    }
};