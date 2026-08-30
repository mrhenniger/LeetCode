#include <iostream>
#include <vector>
#include <stack>

// LeetCode 2. Add Two Numbers
//
// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.
//
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.
//
// Constraints:
//   - The number of nodes in each linked list is in the range [1, 100].
//   - 0 <= Node.val <= 9
//   - It is guaranteed that the list represents a number without leading zeros.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Leetcode2 {
public:
    // The harness deletes the returned list, so build it from newly allocated
    // nodes rather than reusing nodes from l1 or l2.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first = (l1 == nullptr) ? 0 : l1->val;
        int second = (l2 == nullptr) ? 0 : l2->val;
        int sum = first + second;
        int digit = (int)(sum%10);
        int carry = (int)(sum/10);
        //std::cout << "first" << first << ", second=" << second << ", digit=" << digit << ", carry=" << carry << std::endl;
        ListNode* ptr = new ListNode(digit);
        ListNode* head = ptr;
        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
        while(l1 != nullptr || l2 != nullptr) {
            first = (l1 == nullptr) ? 0 : l1->val;
            second = (l2 == nullptr) ? 0 : l2->val;
            sum = first + second + carry;
            digit = (int)(sum%10);
            carry = (int)(sum/10);
            //std::cout << "first" << first << ", second=" << second << ", digit=" << digit << ", carry=" << carry << std::endl;

            ptr->next = new ListNode(digit);
            ptr = ptr->next;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        if (carry > 0) {
            ptr->next = new ListNode(carry);
        }
        
        return head;
    }
};

// Builds a linked list from the digits in order, so {2, 4, 3} represents 342.
static ListNode* buildList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int v : values) {
        ListNode* node = new ListNode(v);
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

static void printList(ListNode* head) {
    std::cout << "[";
    for (ListNode* node = head; node != nullptr; node = node->next) {
        if (node != head) {
            std::cout << ",";
        }
        std::cout << node->val;
    }
    std::cout << "]" << std::endl;
}

static void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void test(const std::vector<int>& a, const std::vector<int>& b) {
    Leetcode2 solution;

    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);
    ListNode* result = solution.addTwoNumbers(l1, l2);

    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);
}

int main() {
    std::cout << "Test Case - Zero plus zero" << std::endl;
    test({0}, {0});                             // [0]

    std::cout << "Test Case - No carry" << std::endl;
    test({1, 2}, {3, 4});                       // [4,6]

    std::cout << "Test Case - Single carry" << std::endl;
    test({5}, {5});                             // [0,1]

    std::cout << "Test Case - Carry ripples through" << std::endl;
    test({9, 9}, {1});                          // [0,0,1]

    std::cout << "Test Case - Different lengths" << std::endl;
    test({1, 2, 3}, {4, 5});                    // [5,7,3]

    std::cout << "Test Case - Shorter first" << std::endl;
    test({1}, {9, 9, 9});                       // [0,0,0,1]

    std::cout << "Test Case 1" << std::endl;
    test({2, 4, 3}, {5, 6, 4});                 // [7,0,8]

    std::cout << "Test Case 2" << std::endl;
    test({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9});  // [8,9,9,9,0,0,0,1]

    return 0;
}
