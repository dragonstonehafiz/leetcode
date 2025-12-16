#pragma once
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            int num_i = nums[i];
            int needed = target - num_i;
            for (int j = i + 1; j < nums.size(); ++j) {
                int num_j = nums[j];
                if (needed == num_j)
                    return { i, j };
            }
        }
    }
};