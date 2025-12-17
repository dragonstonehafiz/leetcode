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
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        bool carry_over = false;

        ListNode* newNode = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* firstNode = nullptr;

        // Only loop if any of the values is > 0
        while (l1_curr != nullptr || l2_curr != nullptr || carry_over) {
            int total = carry_over ? 1 : 0;
            if (l1_curr != nullptr) {
                total += l1_curr->val;
                ListNode* prev = l1_curr;
                l1_curr = l1_curr->next;
                delete prev;
            }
            if (l2_curr != nullptr) {
                total += l2_curr->val;
                ListNode* prev = l2_curr;
                l2_curr = l2_curr->next;
                delete prev;
            }

            if (total >= 10) {
                total -= 10;
                carry_over = true;
            }
            else
                carry_over = false;

            newNode = new ListNode(total, nullptr);
            if (prevNode != nullptr)
                prevNode->next = newNode;
            if (firstNode == nullptr)
                firstNode = newNode;
            cout << total;
            prevNode = newNode;
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
