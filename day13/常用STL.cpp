vector<int> a(10)//长度为10的vector，每个值为0
vector<int> a(10,3)//长度为10的vector，每个值为3
vector<int> a[10]//定义十个vector，每个vector为空
a.size()//时间复杂度为O(1)
a.empty()//时间复杂度为O(1)
//size()和empty()是所有提及的容器都有的成员函数
a.clear()//时间复杂度为O(n)
//vector分配 所需时间与申请次数有关，与申请的总空间无关，所以尽量减少申请
a.push_back()//在vector末尾添加元素，时间复杂度为O(1)
a.pop_back()//删除vector末尾元素，时间复杂度为O(1)
a.begin()//返回指向第一个元素的迭代器，时间复杂度为O(1)
a.end()//返回指向最后一个元素的下一个位置的迭代器，时间复杂度为O(1)
a.front()//返回第一个元素的引用，时间复杂度为O(1)
a.back()//返回最后一个元素的引用，时间复杂度为O(1)
//一般遍历用for(auto x:a)
//支持比较运算符，按字典序比较


//pair
pair<int,int> a;

a.first()//a的第一个元素
a.second()//a的第二个元素
//支持比较运算符，以first为第一关键字

//string
string a;
a+=b;//可以直接在尾部加上字符串
a.substr(1,2);//从第一个位置开始，长度为2的子串
a.c_str();//返回一个以空字符结尾的字符数组

//queue没有clear()函数

//priority_queue默认大根堆
priority_queue<int,vector<int>,greater<int>> a;//小根堆
//或者在插入时使用负数


//stack没有clear()函数

set<int> a;
//不能插入重复元素，如果插入会被忽略
multiset<int> a;
//能插入重复元素
a.insert();//插入元素
a.find()//返回指向元素的迭代器
a.count()//返回元素个数
a.erase()//删除元素,输入元素x删除所有x，输入迭代器删除迭代器指向的元素
a.lower_bound()//返回第一个大于等于x的元素的迭代器
a.upper_bound()//返回第一个大于x的元素的迭代器

map<int,int> a;
//不能插入重复元素，如果插入会被忽略

//unordered_set,unordered_map,unordered_multimap，unordered_multiser基本功能和上面相同但是不支持lower_bound()和upper_bound() 增删改查的时间复杂度为O(1)


//bitset是一个类似数组的结构，但是每个元素只能是0或1，且每个元素只占一位，所以节省空间，是bool的八分之一
bitset<100> a;
a.any()//是否至少有一个1
a.none()//是否全为0
a.set()//全部置为1
a.set(k,v)//将第k位设置为v
a.flip()//全部取反
