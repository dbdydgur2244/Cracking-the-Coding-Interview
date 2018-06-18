/**
 * Implementation Moore's Voting Algorithm
 *
 * Time Complexity: O(N), max 1.5N
 * Space Complexity: O(1)(no need additional space)
 */
#include <algorithm>
#include <vector>

/**
 * assume that there is majority element.
 * return majority element's number
 */
int majority_element(std::vector<int> cand)
{
    int maj_idx = 0, cnt = 1;

    for (int i = 1; i < cand.size(); ++i) {
        if(cand[maj_idx] == cand[i])
            ++cnt;
        else
            --cnt;
        if (cnt == 0) {
            maj_idx = i; cnt = 1;
        }
    }
    return cand[maj_idx];
}

// check is real majority element
bool isMajority(std::vector<int> a, int cand)
{
    int cnt = 0, size = a.size();
    for (auto candidate: a) {
        if (candidate == cand)
            cnt++;
    }
    return (cnt > size / 2) ? true : false;
}
