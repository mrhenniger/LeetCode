#:property UseAppHost=false

using System;

// LeetCode 1. Two Sum
//
// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice. You can return the answer in any order.
public class Leetcode1
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> numToIndex = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];
            if (numToIndex.ContainsKey(complement))
            {       
                return new int[] { numToIndex[complement], i };
            }
            numToIndex[nums[i]] = i;
        }

        // TODO: implement
        return new int[0];
    }

    public static void Main()
    {
        var solution = new Leetcode1();

        Console.WriteLine("Test Case 1");
        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 2, 7, 11, 15 }, 9)));  // 0,1
        Console.WriteLine("Test Case 2");
        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 3, 2, 4 }, 6)));       // 1,2
        Console.WriteLine("Test Case 3");
        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 3, 3 }, 6)));          // 0,1
    }
}
