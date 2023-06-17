#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float average = 0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2) {
            average = nums1[nums1.size() / 2];
        }
        else {
            int median = nums1.size() / 2;
            average = (nums1[median] + nums1[median - 1]) / 2.0;
        }
        return average;
    }
};

int main() {
    vector<int> nums1, nums2;

    nums1 = {1, 2};
    nums2 = {3, 4};

    Solution s;
    float result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
}