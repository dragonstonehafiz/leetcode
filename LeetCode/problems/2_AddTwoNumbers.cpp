// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

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
        bool carry_over = false;

        ListNode* newNode = new ListNode(0, nullptr);
        ListNode* firstNode = newNode;

        // Only loop if any of the values is > 0
        while (true) {
            // Add up the current nodes numbers
            int l1_ = (l1 != nullptr) ? l1->val : 0;
            int l2_ = (l2 != nullptr) ? l2->val : 0;
            int total = carry_over ? 1 : 0;
            total = total + l1_ + l2_;
            // Move to next node
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            // Find if there is any carry over
            int remainder = total % 10;
            carry_over = bool(total / 10);
            // Update new node and make next node
            newNode->val = remainder;
            if (l1 != nullptr || l2 != nullptr || carry_over)
            {
                newNode->next = new ListNode(0, nullptr);
                newNode = newNode->next;
            }
            else
                break;
        }
        return firstNode;
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
    std::vector<int> input1 = { 2,4,3 };
    std::vector<int> input2 = { 5,6,4 };

    ListNode* l1 = make_linked_list(input1);
    ListNode* l2 = make_linked_list(input2);

    Solution solution;
    solution.addTwoNumbers(l1, l2);
}