#:property UseAppHost=false

using System;

// LeetCode 452. Minimum Number of Arrows to Burst Balloons
//
// There are some spherical balloons taped onto a flat wall. The balloons are
// given as an array points where points[i] = [x_start, x_end] denotes a balloon
// whose horizontal diameter stretches between x_start and x_end.
//
// Arrows are shot vertically upward from the x-axis. A balloon with x_start and
// x_end is burst by an arrow shot at x if x_start <= x <= x_end. There is no
// limit to the number of arrows that can be shot; an arrow travels up
// infinitely, bursting any balloon in its path.
//
// Return the minimum number of arrows that must be shot to burst all balloons.
//
// Note: coordinates can reach int.MinValue / int.MaxValue, so a sort comparator
// written as (a, b) => a[0] - b[0] will overflow. Test case 5 covers that.
public class Leetcode452
{
    public int FindMinArrowShots(int[][] balloons)
    {
        if (balloons.Length <= 1) return balloons.Length;

        balloons.Sort((a, b) => a[0].CompareTo(b[0]));
        
        int count = 0;
        int[] current = balloons[0];
        //Console.WriteLine("current=" + current[0] + "," + current[1]);
        for(int b=1; b<balloons.Length; b++) {
            int[] next = balloons[b];
            //Console.WriteLine("next=" + next[0] + "," + next[1]);
            if (next[0] <= current[1]) {
                current[0] = Math.Max(current[0], next[0]);
                current[1] = Math.Min(current[1], next[1]);
                //Console.WriteLine("merged current=" + current[0] + "," + current[1]);
            } else {
                //Console.WriteLine("current=" + current[0] + "," + current[1] + ", next=" + next[0] + "," + next[1]);
                current = next;
                count++;
                //Console.WriteLine("new current=" + current[0] + "," + current[1]);
            }
        }
        count++;

        return count;
    }

    public static void Main()
    {
        var solution = new Leetcode452();

        Console.WriteLine("Test Case 1");
        Console.WriteLine(solution.FindMinArrowShots(new int[][]
        {
            new int[] { 10, 16 }, new int[] { 2, 8 },
            new int[] { 1, 6 }, new int[] { 7, 12 }
        }));                                                    // 2

        Console.WriteLine("Test Case 2");
        Console.WriteLine(solution.FindMinArrowShots(new int[][]
        {
            new int[] { 1, 2 }, new int[] { 3, 4 },
            new int[] { 5, 6 }, new int[] { 7, 8 }
        }));                                                    // 4

        Console.WriteLine("Test Case 3");
        Console.WriteLine(solution.FindMinArrowShots(new int[][]
        {
            new int[] { 1, 2 }, new int[] { 2, 3 },
            new int[] { 3, 4 }, new int[] { 4, 5 }
        }));                                                    // 2

        Console.WriteLine("Test Case 4");
        Console.WriteLine(solution.FindMinArrowShots(
            new int[][] { new int[] { 1, 10 } }));              // 1

        Console.WriteLine("Test Case 5");
        Console.WriteLine(solution.FindMinArrowShots(new int[][]
        {
            new int[] { -2147483646, -2147483645 },
            new int[] { 2147483646, 2147483647 }
        }));                                                    // 2
    }
}
