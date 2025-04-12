#include <bits/stdc++.h>
using namespace std;

void move_zeros(vector<int> &nums) {
  int l = 0, r = 0;

  while (r < nums.size()) {
    while (nums[r] == 0)
      r++;

    nums[l] = nums[r];

    l++;
    r++;
  }

  while (l < nums.size()) {
    nums[l] = 0;
    l++;
  }
}

int main(int argc, char *argv[]) {
  vector<int> nums{1, 0, 2, 3, 0, 4, 0, 1};

  move_zeros(nums);

  for (const auto n : nums) {
    cout << n << ", ";
  }

  cout << "\n";

  return 0;
}
