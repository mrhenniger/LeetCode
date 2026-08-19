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
        // TODO: implement
        return new int[0];
    }

    public static void Main()
    {
        var solution = new Leetcode1();

        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 2, 7, 11, 15 }, 9)));  // 0,1
        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 3, 2, 4 }, 6)));       // 1,2
        Console.WriteLine(string.Join(",", solution.TwoSum(new int[] { 3, 3 }, 6)));          // 0,1
    }
}
