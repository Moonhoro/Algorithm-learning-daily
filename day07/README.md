1. 区间合并
	- 多个区间有交集，合并成一个区间。
	- 具体思路：
		1. 按区间左端点排序
		2. 每次维护一个区间，对处理区间，则有三个情况：
			1. 完全包含，不变
			2. 部分包含，延长
			3. 不包含，维护区间提出，维护处理区间
