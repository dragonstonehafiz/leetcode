// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> output;
        int numCount = 0;

        int i = 0;
        int j = 0;
        int size = nums1.size() + nums2.size();
        bool isEven = (nums1.size() + nums2.size()) % 2 == 0;

        int middleIndex;
        int lastIndexNeeded;
        if (isEven) {
            middleIndex = (size / 2) - 1;
            lastIndexNeeded = middleIndex + 1;
        }
        else {
            if (size == 0)
                middleIndex = 0;
            else
                middleIndex = (size / 2);
        }

        int currentIndex = 0;
        while (i < nums1.size() || j < nums2.size()) {
            int num1 = i < nums1.size() ? nums1[i] : INT_MAX;
            int num2 = j < nums2.size() ? nums2[j] : INT_MAX;

            // First check if the current num2 number is less than current num1 number
            // then add to output accordingly
            if (num1 < num2) {
                output.push_back(num1);
                ++i;
            }
            else {
                output.push_back(num2);
                ++j;
            }

            if (currentIndex >= middleIndex) {
                // If number of items is even, check if the current index is right of the center
                if (isEven && currentIndex >= middleIndex + 1)
                    return (output[currentIndex] + output[currentIndex - 1]) / 2.f;
                else if (!isEven)
                    return output[currentIndex];
            }
            ++currentIndex;
        }

        return -1;
    }
};


int main()
{
    std::vector<int> input1 = { 1,3 };
    std::vector<int> input2 = { 2 };

    Solution solution;
    double output = solution.findMedianSortedArrays(input1, input2);
    std::cout << output << std::endl;
}
