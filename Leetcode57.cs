#:property UseAppHost=false

using System;

// LeetCode 57. Insert Interval
//
// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [start_i, end_i] represent the start and the end of the ith
// interval, and intervals is sorted in ascending order by start_i. You are also
// given an interval newInterval = [start, end].
//
// Insert newInterval into intervals such that intervals is still sorted in
// ascending order by start_i and still does not have any overlapping intervals
// (merge overlapping intervals if necessary).
//
// Return intervals after the insertion. You don't need to modify intervals
// in-place; you can make a new array and return it.
public class Leetcode57
{
    public int[][] Insert(int[][] intervals, int[] newInterval)
    {
        List<int[]> result = new List<int[]>();
        int i = 0;
        int n = intervals.Length;

        // Everything that ends before newInterval starts passes through untouched.
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.Add(intervals[i]);
            i++;
        }

        // Absorb every interval that starts at or before the running end. The end
        // can grow as we go, so this keeps swallowing intervals the widened range
        // now reaches.
        int start = newInterval[0];
        int end = newInterval[1];
        while (i < n && intervals[i][0] <= end)
        {
            start = Math.Min(start, intervals[i][0]);
            end = Math.Max(end, intervals[i][1]);
            i++;
        }
        result.Add(new int[] { start, end });

        // The rest all start after the merged interval ends.
        while (i < n)
        {
            result.Add(intervals[i]);
            i++;
        }

        return result.ToArray();
    }

    public static void Main()
    {
        var solution = new Leetcode57();

        Console.WriteLine("Test Case 1");
        Print(solution.Insert(
            new int[][] { new int[] { 1, 3 }, new int[] { 6, 9 } },
            new int[] { 2, 5 }));                                      // [[1,5],[6,9]]

        Console.WriteLine("Test Case 2");
        Print(solution.Insert(
            new int[][]
            {
                new int[] { 1, 2 }, new int[] { 3, 5 }, new int[] { 6, 7 },
                new int[] { 8, 10 }, new int[] { 12, 16 }
            },
            new int[] { 4, 8 }));                                      // [[1,2],[3,10],[12,16]]

        Console.WriteLine("Test Case 3");
        Print(solution.Insert(new int[0][], new int[] { 5, 7 }));      // [[5,7]]

        Console.WriteLine("Test Case 4");
        Print(solution.Insert(
            new int[][] { new int[] { 3, 5 }, new int[] { 8, 10 } },
            new int[] { 1, 2 }));                                      // [[1,2],[3,5],[8,10]]

        Console.WriteLine("Test Case 5");
        Print(solution.Insert(
            new int[][] { new int[] { 1, 5 } },
            new int[] { 2, 3 }));                                      // [[1,5]]
    }

    private static void Print(int[][] intervals)
    {
        Console.WriteLine("[" + string.Join(",",
            Array.ConvertAll(intervals, i => "[" + string.Join(",", i) + "]")) + "]");
    }
}
