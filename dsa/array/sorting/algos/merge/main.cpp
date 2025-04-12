#include <bits/stdc++.h>
using namespace std;

class Solution {
  static void merge(vector<int> &nums, int i, int j, int mid) {
    vector<int> merger;

    int p1 = i, p2 = mid + 1;

    while (p1 <= mid || p2 <= j) {

      if (p1 <= mid && p2 <= j) {
        if (nums[p1] <= nums[p2]) {
          merger.push_back(nums[p1]);
          p1++;
        } else {
          merger.push_back(nums[p2]);
          p2++;
        }
      }

      else if (p2 == j + 1) {
        merger.push_back(nums[p1]);
        p1++;
      } else if (p1 == mid) {
        merger.push_back(nums[p2]);
        p2++;
      }
    }

    for (int k = i, l = 0; k <= j; k++, l++) {
      nums[k] = merger[l];
    }
  }

public:
  void merge_sort_internal(vector<int> &nums, int i, int j) {
    if (i == j) {
      return;
    }
    if (j - i == 1) {
      if (nums[i] > nums[j]) {
        swap(nums[i], nums[j]);
      }
      return;
    }

    int mid = (j + i) / 2;

    merge_sort_internal(nums, i, mid);
    merge_sort_internal(nums, mid + 1, j);

    merge(nums, i, j, mid);
  }

  vector<int> mergeSort(vector<int> &nums) {
    merge_sort_internal(nums, 0, nums.size() - 1);
    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  vector<int> v{7, 4, 1, 5, 3};

  s.mergeSort(v);

  for (const auto n : v) {
    cout << n << ",";
  }

  cout << "\n";

  return 0;
}
