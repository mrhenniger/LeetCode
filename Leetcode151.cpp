#include <iostream>
#include <string>
#include <vector>

// LeetCode 151. Reverse Words in a String
//
// Given an input string s, reverse the order of the words.
//
// A word is defined as a sequence of non-space characters. The words in s will
// be separated by at least one space.
//
// Return a string of the words in reverse order concatenated by a single space.
//
// Note that s may contain leading or trailing spaces or multiple spaces between
// two words. The returned string should only have a single space separating the
// words. Do not include any extra spaces.
class Leetcode151 {
public:
    std::string reverseWords(std::string s) {
        // Trim leading and trailing spaces
        size_t start = s.find_first_not_of(' ');
        size_t end = s.find_last_not_of(' ');
        if (start == std::string::npos) {
            return ""; // String is all spaces
        }
        s = s.substr(start, end - start + 1);

        // Reverse the entire string
        reverseWord(s, 0, s.length() - 1);

        // Reverse each word in the reversed string
        size_t word_start = 0;
        for (size_t i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                reverseWord(s, word_start, i - 1);
                word_start = i + 1;
            }
        }

        // Remove extra spaces between words
        std::string result;
        bool in_word = false;
        for (char c : s) {
            if (c != ' ') {
                result += c;
                in_word = true;
            } else if (in_word) {
                result += ' ';
                in_word = false;
            }
        }

        // Remove trailing space if any
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

    void reverseWord(std::string& s, int start, int end) {
        while (start < end) {
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Leetcode151 solution;

    //std::string sample = "sample";
    //solution.reverseWord(sample, 0, 5);
    //std::cout << "sample reveresed:  " << sample << std::endl; // "fedcba"

    std::vector<std::string> tests = {
        "sample",                   // "sample"
        "the sky is blue",          // "blue is sky the"
        "  hello world  ",          // "world hello"
        "a good   example",         // "example good a"
        "single",                   // "single"
        "   lots   of   space   ",  // "space of lots"
    };

    for (size_t i = 0; i < tests.size(); i++) {
        std::cout << "Test Case " << (i + 1) << std::endl;
        std::cout << "\"" << solution.reverseWords(tests[i]) << "\"" << std::endl;
    }

    return 0;
}
