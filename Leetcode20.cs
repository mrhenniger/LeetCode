#:property UseAppHost=false

using System;

// LeetCode 20. Valid Parentheses
//
// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
//   1. Open brackets must be closed by the same type of brackets.
//   2. Open brackets must be closed in the correct order.
//   3. Every close bracket has a corresponding open bracket of the same type.
public class Leetcode20
{
    public bool IsValid(string s)
    {
        Stack<char> stack = new Stack<char>();

        foreach (char c in s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.Push(c);
            }
            else
            {
                if (stack.Count == 0) return false;

                char top = stack.Pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }

        return stack.Count == 0;
    }

    public static void Main()
    {
        var solution = new Leetcode20();

        Console.WriteLine("Test Case 1");
        Console.WriteLine(solution.IsValid("()"));          // True
        Console.WriteLine("Test Case 2");
        Console.WriteLine(solution.IsValid("()[]{}"));      // True
        Console.WriteLine("Test Case 3");
        Console.WriteLine(solution.IsValid("(]"));          // False
        Console.WriteLine("Test Case 4");
        Console.WriteLine(solution.IsValid("([])"));        // True
        Console.WriteLine("Test Case 5");
        Console.WriteLine(solution.IsValid("([)]"));        // False
        Console.WriteLine("Test Case 6");
        Console.WriteLine(solution.IsValid("]"));           // False
        Console.WriteLine("Test Case 7");
        Console.WriteLine(solution.IsValid("("));           // False
    }
}
