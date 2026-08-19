#:property UseAppHost=false

using System;

// LeetCode 242. Valid Anagram
//
// Given two strings s and t, return true if t is an anagram of s,
// and false otherwise.
public class Leetcode242
{
    public bool IsAnagram(string s, string t)
    {
        int slength = s.Length;
        int tlength = t.Length;
        if (slength != tlength) return false;
        
        Dictionary<string, int> letters = new Dictionary<string, int>();

        for(int si=0; si<slength; si++) {
            string charKey = s[si].ToString();
            if (letters.ContainsKey(charKey)) {
                letters[charKey]++;
            } else {
                letters[charKey] = 1;
            }
        }

        for(int ti=0; ti<tlength; ti++) {
            string charKey = t[ti].ToString();
            if (letters.ContainsKey(charKey)) {
                letters[charKey]--;
                if (letters[charKey] < 0) return false;
            } else {
                return false;
            }
        }

        return true;
    }

    public static void Main()
    {
        var solution = new Leetcode242();

        Console.WriteLine(solution.IsAnagram("anagram", "nagaram")); // True
        Console.WriteLine(solution.IsAnagram("rat", "car"));         // False
        Console.WriteLine(solution.IsAnagram("a", "ab"));            // False
        Console.WriteLine(solution.IsAnagram("", ""));               // True
        Console.WriteLine(solution.IsAnagram("aacc", "ccac"));       // False
    }
}
