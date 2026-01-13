// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* a;
        vector<int>* b;

        // Let A be the shorter array, B be the longer array.
        if (nums1.size() > nums2.size()) {
            a = &nums2;
            b = &nums1;
        }
        else {
            a = &nums1;
            b = &nums2;
        }

        // Let half be the number of elements that must be on the left side of the combined split
        int total = a->size() + b->size();
        int half = (total + 1) / 2;

        // You need to choose how many elements to take from A into the left side. Call that number i.
        int low = 0;
        int high = a->size();

        while (true) {
            // For any chosen i, the number taken from B is forced: j = half - i.
            int i = (low + high) / 2;
            int j = half - i;

            // Look only at the four border values around the split
            int L1 = (i != 0) ? a->at(i - 1): numeric_limits<int>::lowest();
            int L2 = (j != 0) ? b->at(j - 1): numeric_limits<int>::lowest();
            int R1 = (i != a->size()) ? a->at(i) : numeric_limits<int>::max();
            int R2 = (j != b->size()) ? b->at(j) : numeric_limits<int>::max();

            if (L1 <= R2 && L2 <= R1) {

                // if total count is odd → median is the larger of the two "last-left" values
                if (total % 2 != 0) {
                    return (L1 > L2) ? L1 : L2;
                }
                // if total count is even → median is average of (larger of the two "last-left") and (smaller of the two "first-right")
                else {
                    int left = (L1 > L2) ? L1 : L2;
                    int right = (R1 < R2) ? R1 : R2;
                    return (left + right) / 2.0f;
                }
            }
            else {
                // Example:
                // A = [1, 5, 6]
                // B = [2, 3, 4, 7, 8]
                // total=8, half=4
                //
                // Suppose current guess:
                // i=3  (take 3 from A), j=1 (take 1 from B)
                //
                // A: [1, 5, 6 | ]        -> L1 = 6,  R1 = +inf
                // B: [2 | 3, 4, 7, 8]    -> L2 = 2,  R2 = 3
                //
                // Check: L1 <= R2 ?  6 <= 3  NO  (L1 > R2)
                // Meaning: you took too many from A (a big value 6 ended up on the left)
                // Fix: make i smaller -> move high left
                if (L1 > R2)
                    high = i - 1;

                // Example:
                // A = [1, 2, 3]
                // B = [4, 5, 6, 7, 8]
                // total=8, half=4
                //
                // Suppose current guess:
                // i=1 (take 1 from A), j=3 (take 3 from B)
                //
                // A: [1 | 2, 3]          -> L1 = 1,  R1 = 2
                // B: [4, 5, 6 | 7, 8]    -> L2 = 6,  R2 = 7
                //
                // Check: L2 <= R1 ?  6 <= 2  NO  (L2 > R1)
                // Meaning: you took too few from A (small values 2,3 are stuck on the right)
                else if (L2 > R1)
                    low = i + 1;
            }
        }

        return -1;
    }
};


int main()
{
    std::vector<int> input1 = { 1,2 };
    std::vector<int> input2 = { 3,4 };

    Solution solution;
    double output = solution.findMedianSortedArrays(input1, input2);
    std::cout << output << std::endl;
}
