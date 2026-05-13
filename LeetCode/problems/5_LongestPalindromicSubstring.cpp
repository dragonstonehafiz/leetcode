// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
            return s;

        int max_len = 0;
        std::string longest = s.substr(0, 1);

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                int range = (j - i) + 1;
                std:string current = s.substr(i, range);
                bool palindrome = this->isPalindrome(current);
                bool is_longer = current.length() > max_len;
                if (is_longer && palindrome) {
                    longest = s.substr(i, range);
                    max_len = longest.length();
                }
            }
        }

        return longest;
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};


int main()
{
    std::string input = "bb";

    Solution solution;
    std::string output = solution.longestPalindrome(input);
    std::cout << output << std::endl;
}
