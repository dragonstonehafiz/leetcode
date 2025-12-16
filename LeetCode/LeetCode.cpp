// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_int = this->getNum(l1);
        int l2_int = this->getNum(l2);
        int sum = l1_int + l2_int;

        cout << l2_int << endl;

        ListNode* output = this->getLL(sum);

        return output;
   }

    int getNum(ListNode* l) {
        ListNode* currNode = l;
        int total = 0;
        int loops = 0;
        while (currNode != nullptr) {
            unsigned int currNum = 0;
            if (loops == 0)
                currNum = currNode->val;
            else 
                currNum = pow(10, loops) * currNode->val;

            total += currNum;
            loops += 1;
            currNode = currNode->next;
        }
        return total;
    }

    ListNode* getLL(int num) {
        // How this function works is we modulus the input num with powers of 10 (10, 100, 1000, etc...)
        // if the modulus of the input number and the power of 10 is the modulus number, then we have found how 'big' the number is.
        // (I say big, but that's not quite accurate. I think I am trying to say we know how many zeroes it should have?)
        // i.e. 807 % 1000 = 807, this means if we divide 807 by 100 we can get 8 which we can use to compute the tens and ones position.
        int largest_tens = 0;
        int loopTimes = 0;
        for (int i = 1; i <= 100; ++i) {
            int tens = pow(10, i);
            int mod = num % tens;
            if (mod == num)
                break;
            largest_tens = tens;
            loopTimes += 1;
        }

        // Now that we have the largest tens, we can work our way down and make all nodes
        // example 857
        // remainder 856
        // 857 % 100 = 57
        // remainder 57
        // 57 % 10 = 7
        int remainder = num;
        ListNode* prevNode = nullptr;
        for (int i = loopTimes; i >= 0; --i) {
            int tens = pow(10, i);
            int divided = remainder / tens;
            remainder = remainder % tens;
            ListNode* newNode = new ListNode(divided, prevNode);
            prevNode = newNode;
        }
        return prevNode;
    }
};

ListNode* make_linked_list(std::vector<int> input) {
    ListNode* prevNode = nullptr;
    for (int i = input.size() - 1; i >= 0; --i) {
        ListNode* newNode = new ListNode(input[i], prevNode);
        prevNode = newNode;
    }
    return prevNode;
}

int main()
{
    std::vector<int> input1 = { 9 };
    std::vector<int> input2 = { 1,9,9,9,9,9,9,9,9,9 };

    ListNode* l1 = make_linked_list(input1);
    ListNode* l2 = make_linked_list(input2);

    Solution solution;
    solution.addTwoNumbers(l1, l2);
}
