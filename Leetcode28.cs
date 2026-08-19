#:property UseAppHost=false

using System;

// LeetCode 28. Find the Index of the First Occurrence in a String
//
// Given two strings needle and haystack, return the index of the first
// occurrence of needle in haystack, or -1 if needle is not part of haystack.
public class Leetcode28
{
    public int StrStr(string haystack, string needle)
    {
        if (string.IsNullOrEmpty(needle)) return 0;
        if (needle.Length > haystack.Length) return -1;
        if (haystack == needle) return 0;
        
        for (int h=0; h<haystack.Length;) {
            //Console.WriteLine("h=" + h);
            
            int hp=h;
            int np=0;
            while(hp<haystack.Length && np<needle.Length && haystack[hp]==needle[np]) {
                //Console.WriteLine("hp=" + hp + "/" + haystack[hp] + ", np=" + np + "/" + needle[np]);
                if (np==(needle.Length - 1)) {
                    //Console.WriteLine("match");
                    return h;
                }
                
                hp++;
                np++;
            }
            
            h++;
        }
        
        return -1;
    }

    public static void Main()
    {
        var solution = new Leetcode28();

        Console.WriteLine(solution.StrStr("sadbutsad", "sad"));   // 0
        Console.WriteLine(solution.StrStr("leetcode", "leeto"));  // -1
        Console.WriteLine(solution.StrStr("hello", "ll"));        // 2
        Console.WriteLine(solution.StrStr("aaaaa", "bba"));       // -1
        Console.WriteLine(solution.StrStr("mississippi", "issip"));// 4
        Console.WriteLine(solution.StrStr("abc", ""));            // 0
    }
}
