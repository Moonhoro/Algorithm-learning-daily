#include <iostream>
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