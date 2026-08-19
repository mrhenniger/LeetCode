#:property UseAppHost=false

using System;

// LeetCode 392. Is Subsequence
public class Leetcode392 {
    public bool IsSubsequence(string s, string t) {
        if (s.Length == 0) return true;
        if (s==t) return true;
        if (t.Length == 0) return false;

        int si = 0;
        int ti = 0;
        while(si<s.Length && ti<t.Length) {
            //Console.WriteLine("LOOP START - si=" + si + "/" + s[si] + ", ti=" + ti + "/" + t[ti]);
            while(ti<t.Length && s[si]!=t[ti]) {
                //Console.WriteLine("before increment - ti=" + ti);
                ti++;
                //Console.WriteLine("after increment - ti=" + ti);
            }
            //Console.WriteLine("si=" + si + "/" + s[si] + ", ti=" + ti + "/" + t[ti]);

            if (ti<t.Length && s[si] == t[ti] && si == (s.Length - 1)) {
                //Console.WriteLine("match");
                return true;
            }
            //Console.WriteLine("MADE IT TO HERE - A");
            
            si++;
            ti++;
            //Console.WriteLine("LOOP END - si=" + si + "/" + s[si] + ", ti=" + ti + "/" + t[ti]);
        }

        //Console.WriteLine("not found");
        return false;
    }
    
    public static void Main()
    {
        var solution = new Leetcode392();

        Console.WriteLine(solution.IsSubsequence("abc", "ahbgdc"));   // True
        Console.WriteLine(solution.IsSubsequence("axc", "ahbgdc"));  // False           // True
    }
}

