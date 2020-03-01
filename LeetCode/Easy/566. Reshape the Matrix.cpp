#include "tools"
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int _r = nums.size(), _c = nums[0].size();
        if (_r * _c != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res[i][j] = nums[(i * c + j) / _c][(i * c + j) % _c];
        return res;
    }
};