class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        return find(nums, target, 0, n - 1);
    }
    int find(vector<int> &nums, int target, int l, int r)
    {
        if (l >= r)
        {
            return target > nums[l] ? l + 1 : l;
        }
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            return find(nums, target, l, mid - 1);
        }
        return find(nums, target, mid + 1, r);
    }
};