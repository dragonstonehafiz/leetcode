// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <bitset>

class Solution {
public:
    std::bitset<256> seen;

    int lengthOfLongestSubstring(std::string s) {
        // Index of the first and last character of the current tracked substring
        int start = -1;
        int longest_streak = 0;
        int current_streak = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // If the current character has not already been seen
            if (!seen.test(c)) {
                ++current_streak;
                seen.set(c);

                if (start < 0) {
                    start = i;
                }
            }
            // If the current character has already been seen reset and reset to character after the current starting character
            else {
                seen.reset();
                i = start;
                start = -1;
                current_streak = 0;
            }

            if (current_streak > longest_streak) {
                longest_streak = current_streak;
            }
        }

        return longest_streak;
    }
};

int main()
{
    Solution solution;

    std::string s = "dvdf";
    int length = solution.lengthOfLongestSubstring(s);
    std::cout << "length:" << length << std::endl;
}
