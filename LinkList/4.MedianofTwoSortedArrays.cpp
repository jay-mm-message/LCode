#include <iostream>
using namespace std;

void show_vec(vector<int> nums3) {
    for (int t : nums3) {
        cout << t << ' ';
    }
    cout << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double res = 0.0;

    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());

    if (nums1.size() == 1) {
        return nums1[0];
    }

    for (int i = 0, j = nums1.size() - 1 ; i <= j ; ++i, --j) {
        if ( i == j ) {
            res = nums1[i];
        }
        if ( i + 1 == j) {
            res = (nums1[i] + nums1[j]) / 2.0;
        }
    }
    return res;
}

int main(void) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    // vector<int> nums1 = {1, 3};
    // vector<int> nums2 = {2};

    // vector<int> nums1 = {};
    // vector<int> nums2 = {1};

    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}

//Input: nums1 = [1,3], nums2 = [2]
//Input: nums1 = [1,2], nums2 = [3,4]
