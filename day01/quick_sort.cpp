#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r);

int main() {
  vector<int> nums;
  // 输入数的个数
  int n;
  cin >> n;
  // 存入容器
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
  cout << "排序前：";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  quick_sort(nums, 0, nums.size() - 1);

  cout << "排序后：";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

void quick_sort(vector<int> &nums, int l, int r) {
  // 取边界点
  int pivot = nums[l];
  // 如果左边界和右边界重合，说明只有一个元素或已经排好序了
  if (l >= r)
    return;
  int i = l - 1, j = r + 1, x = nums[l + r >> 1];
  // 取中间的数为数组中间值 此处为l+r>>1即为(l+r)/2 采用移位运算符速度更快
  while (l < r) {
    do
      j--;
    while (nums[j] > pivot); // 当右边界的值大于基准值时，右边界左移
    do
      i++;
    while (nums[i] < pivot); // 当左边界的值小于基准值时，左边界右移
    if (i < j) // 如果左边界和右边界没有重合，交换左右边界的值
      swap(nums[i], nums[j]);   // 交换左右边界的值
    quick_sort(nums, l, j);     // 递归处理左边界
    quick_sort(nums, j + 1, r); // 递归处理右边界
    return;
  }
}