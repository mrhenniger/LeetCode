#include <iostream>
#include <vector>

// LeetCode 26. Remove Duplicates from Sorted Array
//
// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same. Then return the
// number of unique elements in nums.
//
// Consider the number of unique elements of nums to be k, to get accepted you
// need to do the following things:
//   - Change the array nums such that the first k elements of nums contain the
//     unique elements in the order they were present in nums initially. The
//     remaining elements of nums are not important as well as the size of nums.
//   - Return k.
class Leetcode26 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen <= 1) {
            return numsLen;
        }

        int tail = 0;
        int head = 1;
        while (head < numsLen) {
            if (nums[head] != nums[tail]) {
                tail++;
                nums[tail] = nums[head];
            }
            head++;
        }

        return tail + 1;
    }
};

// removeDuplicates mutates nums in-place, so keep a reference to the same
// vector we pass in and print only the first k elements.
void test(std::vector<int> nums) {
    Leetcode26 solution;
    int k = solution.removeDuplicates(nums);

    std::cout << "k = " << k << ", [";
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            std::cout << ",";
        }
        std::cout << nums[i];
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Test Case - Empty array" << std::endl;
    test({});                                   // k = 0, []

    std::cout << "Test Case - Single element" << std::endl;
    test({1});                                  // k = 1, [1]

    std::cout << "Test Case - No duplicates" << std::endl;
    test({1, 2, 3});                            // k = 3, [1,2,3]

    std::cout << "Test Case - All the same" << std::endl;
    test({2, 2, 2, 2});                         // k = 1, [2]

    std::cout << "Test Case - Duplicates at the front" << std::endl;
    test({1, 1, 1, 2, 3});                      // k = 3, [1,2,3]

    std::cout << "Test Case - Duplicates at the back" << std::endl;
    test({1, 2, 3, 3, 3});                      // k = 3, [1,2,3]

    std::cout << "Test Case - Negative numbers" << std::endl;
    test({-3, -3, -1, 0, 0});                   // k = 3, [-3,-1,0]

    std::cout << "Test Case 1" << std::endl;
    test({1, 1, 2});                            // k = 2, [1,2]

    std::cout << "Test Case 2" << std::endl;
    test({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});       // k = 5, [0,1,2,3,4]

    return 0;
}
