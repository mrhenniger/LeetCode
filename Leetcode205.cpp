#include <iostream>
#include <unordered_map>
#include <string>

// LeetCode 205. Isomorphic Strings
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings s and t are isomorphic if the characters in s can be replaced to
// get t.
//
// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character, but a character may map to itself.
//
// Constraints:
//   - 1 <= s.length <= 5 * 10^4
//   - t.length == s.length
//   - s and t consist of any valid ascii character.
class Leetcode205 {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int sLen = s.length();
        if (sLen != (int)t.length()) {
            return false;
        }

        std::unordered_map<char, char> char_map;
        std::unordered_map<char, char> reverse_char_map;
        for(int i=0; i<sLen; i++) {
            char from =s[i];
            char to = t[i];
            //std::cout << "Mapping " << from << " to " << to << std::endl;

            auto it = char_map.find(from);
            if (it == char_map.end()) // from is not in the map
            {
                auto it_rev = reverse_char_map.find(to);
                if (it_rev != reverse_char_map.end()) // to is already mapped to a different character
                {
                    //std::cout << "Conflict: " << to << " is already mapped to " << it_rev->second << std::endl;
                    return false;
                }

                //std::cout << "Adding mapping " << from << " -> " << to << std::endl;
                char_map[from] = to;
                reverse_char_map[to] = from;
            }
            else
            {
                //std::cout << "Found existing mapping for " << from << " -> " << char_map[from] << std::endl;
                if (char_map[from] != to) // from is in the map but maps to a different character
                {
                    //std::cout << "Conflict: " << from << " maps to " << char_map[from] << " but trying to map to " << to << std::endl;
                    return false;
                }
            }
        }

        std::cout << "All characters mapped successfully." << std::endl;
        return true;
    }
};

void test(std::string s, std::string t) {
    Leetcode205 solution;
    bool result = solution.isIsomorphic(s, t);

    std::cout << "\"" << s << "\", \"" << t << "\" -> "
              << (result ? "true" : "false") << std::endl;
}

int main() {
    std::cout << std::endl << "Test Case - Single character" << std::endl;
    test("a", "a");                     // true

    std::cout << std::endl << "Test Case - Maps to itself" << std::endl;
    test("abc", "abc");                 // true

    std::cout << std::endl << "Test Case - Two characters collapse to one" << std::endl;
    test("ab", "aa");                   // false

    std::cout << std::endl << "Test Case - One character splits in two" << std::endl;
    test("aa", "ab");                   // false

    std::cout << std::endl << "Test Case - Conflict only at the last character" << std::endl;
    test("badc", "baba");               // false

    std::cout << std::endl << "Test Case - Swapped pair" << std::endl;
    test("ab", "ba");                   // true

    std::cout << std::endl << "Test Case - Non-letter characters" << std::endl;
    test("13", "42");                   // true

    std::cout << std::endl << "Test Case 1" << std::endl;
    test("egg", "add");                 // true

    std::cout << std::endl << "Test Case 2" << std::endl;
    test("foo", "bar");                 // false

    std::cout << std::endl << "Test Case 3" << std::endl;
    test("paper", "title");             // true

    return 0;
}
