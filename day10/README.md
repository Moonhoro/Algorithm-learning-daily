1. 字典树（用数组实现）
	1. 作用：高效存储和查找字符串集合
	2. 存储：标记结尾节点
	3. 查找：判断是否存在且是否存在标记
	4. 基本操作：插入 查询
2. 并查集
	1. 基本操作：将两个集合合并 询问两个元素是否在一个集合
	2. 基本原理：每一个集合用一颗树表示。树根的编号就是整个集合的编号。每个节点存储它的父节点.
	3. 如何判断根节点：`if(p[i]==x)`
	4. 如何求x的集合编号：`while(p!=x)p=p[x];`
	5. 如何合并两个集合：`p[y]=x`
	6. 路径压缩：在找到根节点后，让遍历的所有节点都指向根节点。