此处为用数组模拟
1. 单链表
	1. 理论上，单链表为每个节点均有一个va储存值l和next指针构成，用数组模拟采用两个数组实现，一个数组储存val，另一个储存对应的下一个数的下标，即next。
	2. 单链表没办法查看自身的前一个点的位置，想找到前一个点只能遍历。
	3. 邻接表
		1. 主要作用存储图和树
		2. 由多个单链表构成（属实也没理解，以后会讲）
2. 双链表
	1. 主要解决优化问题
	2. 理论上，双链表为每个节点均有一个val值和pre，next两个指针构成，用数组模拟采用三个数组实现，一个数组储存val，一个储存左值的下标，即pre，一个储存右值的下标，即next。（此处不设头尾节点，0节点表示头节点）
3. 栈
	1. 特点：先进后出
		1. 单调栈
			1. 单调栈的基本思想和操作：
			    - 如果栈为空，将当前元素入栈。
			    - 如果当前元素小于等于栈顶元素（保持单调递增），将当前元素入栈。
			    - 如果当前元素大于栈顶元素（打破单调递增），则持续出栈栈顶元素，直到栈为空或当前元素小于等于栈顶元素。出栈的元素表示找到了其特定性质，可以在此处进行相应的处理。
			   - 将当前元素入栈，保持单调性。
1. 队列
	1. 特点：先进先出
		1. 单调队列
			1. 单调队列的基本思想和操作：
			- 如果队列为空，将当前元素入队。
			- 如果当前元素大于等于队列尾部的元素（保持单调递增），将队尾元素出队，直到队列为空或当前元素小于队尾元素。出队的元素不可能成为窗口中的最大值，因为后面的元素更大且在更后面，因此可以将其丢弃。
			- 将当前元素入队，保持单调性。
			- 如果队列头部的元素已经超出了窗口的范围（即下标不在窗口内），将队头元素出队。
