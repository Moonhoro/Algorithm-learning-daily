1.  快排：

时间复杂度为O(nlogn)（并不稳定）

空间复杂度为O(nlogn)

    基本思路
    1.  确定分界点x 一般取数组第一个或数组中间值或随机数（分界点选取影响效率）
    2.  调整位置 让大于x的数位于x左边 小于x的数位移x右边
    3.  递归
    4.  实现如下

此处为数据传入过程

```#include<iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& nums,int l,int r);

int main()
{
    vector<int>nums;
//输入数的个数
    int n;
    cin>>n;
//存入容器
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }
 cout << "排序前：";
    for(int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    
    quick_sort(nums, 0, nums.size() - 1);
    
    cout << "排序后：";
    for(int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
```

此处为快排实现

    void quick_sort(vector<int> &nums, int l, int r) {
      // 如果左边界和右边界重合，说明只有一个元素或已经排好序了
      if (l >= r)
        return;
      // 取边界点
      int i = l - 1, j = r + 1, x = nums[l + r >> 1];
      // 此处为l+r>>1即为(l+r)/2 采用移位运算符速度更快
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

```
```

2.  归并

时间复杂度为O(nlogn)

空间复杂度为O(nlogn)

    基本思路
    1.  确定分界点位置
    2.  先进行递归
    3.  合并
    4.  实现如下

此处为数据传入过程

```#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int l, int r);
 vector<int> temp;//归并排序需要一个临时数组
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

  merge_sort(nums, 0, nums.size() - 1);

  cout << "排序后：";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}
```

此处为归并实现过程

```
void merge_sort(vector<int> &nums, int l, int r)
{

  if(l>=r) return;
  //确认不超过边界
  int x = l+r>>1;
  int k=0,i=l,j=x+1;
  //取分界点
    temp.resize(nums.size());
  merge_sort(nums,l,x);
  merge_sort(nums,x+1,r);
  //递归
while(i<=x&&j<=r)
{
if(nums[i]<=nums[j]) temp[k++]=nums[i++];
else temp[k++]=nums[j++];
//将较小的数放入临时数组
}
while(i<=x) temp[k++]=nums[i++];
while(j<=r) temp[k++]=nums[j++];
//将剩余的数放入临时数组
for(int i=l;i<=r;i++) nums[i]=temp[i-l];
return;

}
}

```
3. 二分
    
    1.二分更多是一种思想
    
    前提条件：要使用二分法，必须是对一个有序（不一定是以大小为序列）的数据集合进行操作，例如有序数组。
    
    初始化：确定搜索范围的起始点 `low` 和终止点 `high`，通常初始时为整个数据集合的起始和结束位置。
    
    循环查找：重复以下步骤直到找到目标值或确定目标值不存在。
    
    计算中间位置：`mid = (low + high) / 2`，取中间位置作为分割点。
    
    比较目标值与分割点的大小关系：
    
    如果目标值等于分割点的值，则找到目标值，结束查找。
    
    如果目标值小于分割点的值，则目标值可能在分割点的左侧，将搜索范围缩小到左侧子数组，更新 `high = mid - 1`。
    
    如果目标值大于分割点的值，则目标值可能在分割点的右侧，将搜索范围缩小到右侧子数组，更新 `low = mid + 1`。
    
    结束条件：找到目标值位置或当搜索范围为空，即 `low > high`，表示目标值不存在于数据集合中。

二分法的优点是在每次比较后可以将搜索范围缩小一半，因此具有较高的查找效率。它适用于有序数据集合，并且可以用于查找特定元素、判断元素是否存在、查找边界值等场景。
