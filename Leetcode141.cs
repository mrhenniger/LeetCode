#:property UseAppHost=false

using System;

// LeetCode 141. Linked List Cycle
//
// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.
//
// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to. Note that pos is not passed as a parameter.
//
// Return true if there is a cycle in the linked list. Otherwise, return false.
public class Leetcode141
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x)
        {
            val = x;
            next = null;
        }
    }

    public bool HasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next;
            if (fast == null) return false;
            fast = fast.next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Builds a linked list from values, connecting the tail's next pointer back
    // to the node at index pos. Use pos = -1 for no cycle.
    private static ListNode BuildList(int[] values, int pos)
    {
        if (values.Length == 0) return null;

        ListNode[] nodes = new ListNode[values.Length];
        for (int i = 0; i < values.Length; i++)
        {
            nodes[i] = new ListNode(values[i]);
            if (i > 0) nodes[i - 1].next = nodes[i];
        }

        if (pos >= 0) nodes[values.Length - 1].next = nodes[pos];

        return nodes[0];
    }

    public static void Main()
    {
        var solution = new Leetcode141();

        Console.WriteLine("Test Case 1");
        Console.WriteLine(solution.HasCycle(BuildList(new int[] { 3, 2, 0, -4 }, 1)));  // True
        Console.WriteLine("Test Case 2");
        Console.WriteLine(solution.HasCycle(BuildList(new int[] { 1, 2 }, 0)));         // True
        Console.WriteLine("Test Case 3");
        Console.WriteLine(solution.HasCycle(BuildList(new int[] { 1 }, -1)));           // False
        Console.WriteLine("Test Case 4");
        Console.WriteLine(solution.HasCycle(BuildList(new int[] { 1, 2, 3, 4 }, -1)));  // False
        Console.WriteLine("Test Case 5");
        Console.WriteLine(solution.HasCycle(BuildList(new int[] { }, -1)));             // False
    }
}
