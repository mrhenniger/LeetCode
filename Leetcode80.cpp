#include <iostream>
#include <vector>

// LeetCode 80. Remove Duplicates from Sorted Array II
//
// Given an integer array nums sorted in non-decreasing order, remove some
// duplicates in-place such that each unique element appears at most twice. The
// relative order of the elements should be kept the same.
//
// Since it is impossible to change the length of the array in some languages,
// you must instead have the result be placed in the first part of the array
// nums. More formally, if there are k elements after removing the duplicates,
// then the first k elements of nums should hold the final result. It does not
// matter what you leave beyond the first k elements.
//
// Return k after placing the final result in the first k slots of nums.
class Leetcode80 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // k is both the write position and the count of elements kept so far.
        //
        // Because the array is sorted, every copy of a value is contiguous, so
        // the only thing that decides whether we keep nums[i] is what we have
        // already written. nums[k - 2] is the second-most-recent element kept:
        // if it equals the candidate, we have kept two copies of that value
        // already and must skip this one. Otherwise we keep it.
        //
        // The k < 2 guard lets the first two elements through unconditionally
        // and keeps the nums[k - 2] index in bounds.
        int k = 0;
        for (int n : nums) {
            if (k < 2 || nums[k - 2] != n) {
                nums[k] = n;
                k++;
            }
        }

        return k;
    }
};

// removeDuplicates mutates nums in-place, so keep a reference to the same
// vector we pass in and print only the first k elements.
void test(std::vector<int> nums) {
    Leetcode80 solution;
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

    std::cout << "Test Case - Exactly two of each" << std::endl;
    test({1, 1, 2, 2});                         // k = 4, [1,1,2,2]

    std::cout << "Test Case - All the same" << std::endl;
    test({2, 2, 2, 2});                         // k = 2, [2,2]

    std::cout << "Test Case - Triples at the front" << std::endl;
    test({1, 1, 1, 2, 3});                      // k = 4, [1,1,2,3]

    std::cout << "Test Case - Triples at the back" << std::endl;
    test({1, 2, 3, 3, 3});                      // k = 4, [1,2,3,3]

    std::cout << "Test Case - Negative numbers" << std::endl;
    test({-3, -3, -3, -1, 0, 0});               // k = 5, [-3,-3,-1,0,0]

    std::cout << "Test Case 1" << std::endl;
    test({1, 1, 1, 2, 2, 3});                   // k = 5, [1,1,2,2,3]

    std::cout << "Test Case 2" << std::endl;
    test({0, 0, 1, 1, 1, 1, 2, 3, 3});          // k = 7, [0,0,1,1,2,3,3]

    return 0;
}
