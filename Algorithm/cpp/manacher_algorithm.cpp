#include <algorithm>
#include <iostream>
#include <string>

/**
 * Find the longest palindrome of substring
 * But, this algorithm can find only odd number palindrome, so
 * add # to string can find only even number palindrome. ex) abba -> ba#b#b#aa -> a#b#b#a -> abba
 * s: input string
 * a: the longest palindrome which middle is i's char.
 * 
 * time complexity: O(N)
 * space complexity: O(N)
 */

int a[100] = { 0, };

int find_longest_palindrome(std::string s)
{
    int r = -1, p = -1, size = s.size();
    //int a[100] = { 0, };
    for (int i = 0; i < size; ++i) {
        if (i <= r)
            a[i] = std::min(a[2 * p - i], r - i);
        else
            a[i] = 0;
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < size &&
               s[i - a[i] - 1] == s[i + a[i] + 1]) {
            ++a[i];
        }
        if (i + a[i] > r)  {
            r = i + a[i]; p = i;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        ans = std::max(ans, a[i]);
    }
    return 2 * ans + 1;
}

int main(void) {
    std::cout << find_longest_palindrome(std::string("babcbabcbaccba")) << std::endl;
    std::cout << find_longest_palindrome(std::string("abaaba")) << std::endl;
    std::cout << find_longest_palindrome(std::string("abababa")) << std::endl;
    std::cout << find_longest_palindrome(std::string("forgeeksskeegfor")) << std::endl;
    std::cout << find_longest_palindrome(std::string("caba")) << std::endl;
    std::cout << find_longest_palindrome(std::string("abacdfgdcaba")) << std::endl;
    std::cout << find_longest_palindrome(std::string("abacdfgdcabba")) << std::endl;
    std::cout << find_longest_palindrome(std::string("abacdedcaba")) << std::endl;
    return 0;
}
