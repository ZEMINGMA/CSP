# 格式化输出
#### printf
```cpp
printf("%d\n", 10);  // 整数
printf("%f\n", 1.23);  // 浮点数
printf("%.2f\n", 1.23);  // 保留两位小数
printf("%6d\n", 10);  // 宽度为6
printf("%06d\n", 10);  // 宽度为6, 空余的地方补0
printf("%s\n", "hello");  // 字符串
printf("%c\n", 'c');  // 字符
```

#### iostream
```cpp
#include <iostream>
#include <iomanip>
cout << fixed << setprecision(2) << 1.23 << endl;  // 保留两位小数
cout << setw(6) << 10 << endl;  // 宽度为6
cout << setw(6) << setfill('0') << 10 << endl;  // 宽度为6, 空余的地方补0
cout << dec << 15;//10
cout << hex << 15;//16
cout << oct << 15;//8
cout << left << setw(10) << "Hello";//左对齐
cout << right << setw(10) << "Hello";//右对齐
```

#### 文件操作
```cpp
#include<fstream>
ifstream input_file("input.txt");  // 通过构造函数打开文件
ofstream output_file;
output_file.open("output.txt");  // 通过.open()函数打开文件


ifstream input_file("input.txt");
int a;
input_file >> a;  // 读取一个整数

char c;
input_file.get(c);  // 读取一个字符

string line;
getline(input_file, line);  // 读取一整行

ofstream output_file("output.txt");
output_file << "Hello, world!\n";  // 写入一个字符串

ifstream input_file("input.txt");
if (!input_file) {
    cerr << "Failed to open the file.\n";
}

input_file.close();
output_file.close();

```

# vector

1. `push_back()`：在vector的尾部添加一个新元素。

2. `pop_back()`：移除vector的最后一个元素。

3. `insert()`：在vector的指定位置插入一个或多个元素。

4. `erase()`：删除vector的指定位置或指定范围的元素。

5. `clear()`：清空vector中的所有元素。

6. `size()`：返回vector中元素的数量。

7. `empty()`：检查vector是否为空。

8. `resize()`：更改vector的大小。

9. `capacity()`：返回vector当前的容量。

10. `operator[]`：返回指定位置的元素的引用。

11. `at()`：返回指定位置的元素的引用。



**增**（添加元素）

```cpp
vector<int> vec;
vec.push_back(1);  // 添加一个元素到尾部
vec.insert(vec.begin(), 0);  // 在指定位置插入元素
```

**删**（删除元素）

```cpp
vector<int> vec = {0, 1, 2, 3, 4};
vec.pop_back();  // 删除尾部元素
vec.erase(vec.begin());  // 删除指定位置元素
vec.clear();  // 清空所有元素
```

**改**（修改元素）

```cpp
vector<int> vec = {0, 1, 2, 3, 4};
vec[0] = 5;  // 使用下标修改元素
vec.at(1) = 6;  // 使用at函数修改元素
```

**查**（访问元素）

```cpp
vector<int> vec = {0, 1, 2, 3, 4};
int first_element = vec[0];  // 使用下标访问元素
int second_element = vec.at(1);  // 使用at函数访问元素
```

请注意，`at()`函数和`operator[]`在访问超出范围的元素时，行为不同。`at()`函数将抛出一个`out_of_range`异常，而`operator[]`没有定义超出范围的行为，可能会导致未定义的行为。


**1. 使用经典的for循环**

```cpp
vector<int> vec = {0, 1, 2, 3, 4};
for (size_t i = 0; i < vec.size(); ++i) {
    cout << vec[i] << endl;
}
```

**2. 使用迭代器**

```cpp
vector<int> vec = {0, 1, 2, 3, 4};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << endl;
}
```


# set
    按特定的顺序排列。每个元素在set中必须是唯一的，因为元素的值定义了其在set中的位置。set通常是用红黑树实现的，所以查找，插入和删除的时间复杂度都是对数复杂度。默认按照升序排序，如果你想创建一个元素按降序排列的std::set，你可以这样做：
 ```cpp
set<int, greater<int>> s;
```


1. `insert()`：插入元素。

2. `erase()`：删除指定的元素或者范围内的元素。

3. `clear()`：清除所有元素。

4. `size()`：返回set中的元素个数。

5. `empty()`：检查set是否为空。

6. `begin()`、`end()`：返回指向set开始和结束位置的迭代器。

7. `find()`：查找指定元素的位置。

8. `count()`：返回指定元素的数量（在set中该函数的返回值要么是0要么是1，因为set中元素唯一）。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
set<int> s;
s.insert(1);  // 插入元素
```

**删**（删除元素）

```cpp
set<int> s = {0, 1, 2, 3, 4};
s.erase(1);  // 删除元素1
s.erase(s.begin(), s.end());  // 删除所有元素，等价于s.clear();
```

**查**（查找元素）

```cpp
set<int> s = {0, 1, 2, 3, 4};
auto it = s.find(1);  // 查找元素1，返回指向元素1的迭代器，如果没有找到则返回s.end()
if (s.count(1) > 0) { // 检查元素1是否存在
    // do something
}
```

**改**（修改元素）

需要注意的是，`set`中的元素是常量，不能直接被修改。如果需要修改set中的元素，一般的做法是删除旧的元素然后插入新的元素。

**遍历**（访问元素）

```cpp
set<int> s = {0, 1, 2, 3, 4};
//使用迭代器遍历
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << endl;
}
```

# unordered_set

让我们讨论`unordered_set`。`unordered_set`是一个关联容器，它包含唯一元素的集合。搜索、插入和删除的平均时间复杂度为常数时间。`unordered_set`使用散列函数来确定元素在容器内部的位置。不像`set`，`unordered_set`内部的元素不会按任何顺序排序，而是组织在存储桶中。

以下是`unordered_set`的一些常用函数：

1. `insert()`：插入元素。

2. `erase()`：删除指定的元素或者范围内的元素。

3. `clear()`：清除所有元素。

4. `size()`：返回集合中的元素个数。

5. `empty()`：检查集合是否为空。

6. `begin()`、`end()`：返回指向集合开始和结束位置的迭代器。

7. `find()`：查找指定元素的位置。

8. `count()`：返回指定元素的数量（在unordered_set中该函数的返回值要么是0要么是1，因为集合中元素唯一）。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
unordered_set<int> s;
s.insert(1);  // 插入元素
```

**删**（删除元素）

```cpp
unordered_set<int> s = {0, 1, 2, 3, 4};
s.erase(1);  // 删除元素1
s.clear();  // 删除所有元素
```

**查**（查找元素）

```cpp
unordered_set<int> s = {0, 1, 2, 3, 4};
auto it = s.find(1);  // 查找元素1，返回指向元素1的迭代器，如果没有找到则返回s.end()
if (s.count(1) > 0) { // 检查元素1是否存在
    // do something
}
```

**改**（修改元素）

需要注意的是，`unordered_set`中的元素是常量，不能直接被修改。如果需要修改set中的元素，一般的做法是删除旧的元素然后插入新的元素。

**遍历**（访问元素）

```cpp
unordered_set<int> s = {0, 1, 2, 3, 4};

// 使用迭代器遍历
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << endl;
}
```

# map

`map`是C++的标准库容器，它存储的是键值对（key-value pair），所有的元素都会根据键（key）进行排序，排序的规则可以在创建`map`对象时指定。`map`内部通常使用红黑树实现，所以它的插入，删除和查找的时间复杂度都是对数复杂度。

以下是`map`的一些常用函数：

1. `insert()`：插入元素，元素是键值对。

2. `erase()`：删除指定的元素或者范围内的元素。

3. `clear()`：清除所有元素。

4. `size()`：返回map中的元素个数。

5. `empty()`：检查map是否为空。

6. `begin()`、`end()`：返回指向map开始和结束位置的迭代器。

7. `find()`：查找指定键的元素。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
map<string, int> m;
m.insert(make_pair("apple", 1));  // 插入元素
m["banana"] = 2;  // 另一种插入元素的方式
```

**删**（删除元素）

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};
m.erase("apple");  // 删除键为"apple"的元素
m.clear();  // 删除所有元素
```

**查**（查找元素）

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};
auto it = m.find("apple");  // 查找键为"apple"的元素，返回一个迭代器，如果没有找到则返回m.end()
if (it != m.end()) {
    // 找到了键为"apple"的元素，it->second是对应的值
}
```

**改**（修改元素）

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};
m["apple"] = 3;  // 修改键为"apple"的元素的值
```

**遍历**（访问元素）

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};
// 使用迭代器遍历
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

在上述代码中，`cout << pair.first << ": " << pair.second << endl;`是对每个元素执行的操作，你可以将其替换为你需要的操作。

# unordered_map

`unordered_map`是C++的标准库容器，它存储的是键值对（key-value pair），所有的元素都存储在一个无序的哈希表中。`unordered_map`的查找，插入，删除的平均时间复杂度都是常数时间，但是在最坏的情况下，这些操作的时间复杂度可以是线性的。

以下是`unordered_map`的一些常用函数：

1. `insert()`：插入元素，元素是键值对。

2. `erase()`：删除指定的元素或者范围内的元素。

3. `clear()`：清除所有元素。

4. `size()`：返回unordered_map中的元素个数。

5. `empty()`：检查unordered_map是否为空。

6. `begin()`、`end()`：返回指向unordered_map开始和结束位置的迭代器。

7. `find()`：查找指定键的元素。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
unordered_map<string, int> m;
m.insert(make_pair("apple", 1));  // 插入元素
m["banana"] = 2;  // 另一种插入元素的方式
```

**删**（删除元素）

```cpp
unordered_map<string, int> m = {{"apple", 1}, {"banana", 2}};
m.erase("apple");  // 删除键为"apple"的元素
m.clear();  // 删除所有元素
```

**查**（查找元素）

```cpp
unordered_map<string, int> m = {{"apple", 1}, {"banana", 2}};
auto it = m.find("apple");  // 查找键为"apple"的元素，返回一个迭代器，如果没有找到则返回m.end()
if (it != m.end()) {
    // 找到了键为"apple"的元素，it->second是对应的值
}
```

**改**（修改元素）

```cpp
unordered_map<string, int> m = {{"apple", 1}, {"banana", 2}};
m["apple"] = 3;  // 修改键为"apple"的元素的值
```

**遍历**（访问元素）

```cpp
unordered_map<string, int> m = {{"apple", 1}, {"banana", 2}};
for (const auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}
// 或者使用迭代器遍历
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

在上述代码中，`cout << pair.first << ": " << pair.second << endl;`是对每个元素执行的操作，你可以将其替换为你需要的操作。

# queue

`queue`是一个容器适配器，用于给容器提供队列（FIFO，先进先出）的特性。具有队列特性的意思是，元素的插入只能在队列的一端（称为队尾），而删除只能在另一端（称为队头）。

以下是`queue`的一些常用函数：

1. `push()`：向队列尾部添加元素。

2. `pop()`：删除队列头部的元素。

3. `front()`：返回队列头部的元素。

4. `back()`：返回队列尾部的元素。

5. `empty()`：检查队列是否为空。

6. `size()`：返回队列中的元素个数。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
queue<int> q;
q.push(1);  // 在队列尾部添加元素
```

**删**（删除元素）

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.pop();  // 删除队列头部的元素
```

**查**（查找元素）

```cpp
queue<int> q;
q.push(1);
q.push(2);
int front = q.front();  // 获取队列头部的元素
int back = q.back();  // 获取队列尾部的元素
```

在队列中没有直接的修改元素的操作，如果你需要修改队头或队尾的元素，可以先使用`front()`或`back()`获取到元素的引用，然后直接修改引用的值。但是，通常我们不会这么做，因为这违反了队列的先进先出的原则。

遍历`queue`并不像其他容器那样常见，因为队列的设计初衷是只能从两端进行操作。然而，如果你真的需要遍历一个队列，可以这么做：

```cpp
queue<int> q;
// 先将元素添加到队列中
q.push(1);
q.push(2);
q.push(3);
// 然后遍历队列
queue<int> qcopy = q;  // 创建一个队列的副本进行遍历
while(!qcopy.empty()){
    cout << qcopy.front() << endl;
    qcopy.pop();
}
```

在这个代码中，我们创建了一个队列的副本进行遍历，这样原始队列的元素不会被删除。注意，在遍历过程中，我们不能修改队列中的元素。

# string

`string` 是C++标准库中的一个类，用于表示和操作字符串。它比C风格的字符串更易于使用和更安全。

以下是 `string` 的一些常用函数：

1. `size()`/`length()`：返回字符串的长度。

2. `empty()`：检查字符串是否为空。

3. `clear()`：清除字符串中的所有字符。

4. `at()`：返回字符串中指定位置的字符。

5. `substr()`：返回字符串的一个子串。

6. `find()`：在字符串中查找子串或字符。

7. `replace()`：替换字符串的一部分为其他字符串。

8. `append()`：在字符串的末尾添加字符或字符串。

9. `insert()`：在字符串的指定位置插入字符或字符串。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
string str = "apple";
str.append(" banana");  // 在字符串的末尾添加字符串
str.insert(5, " and");  // 在指定位置插入字符串
```

**删**（删除元素）

```cpp
string str = "apple and banana";
str.erase(5, 5);  // 删除从位置5开始的5个字符
str.clear();  // 删除所有字符
```

**查**（查找元素）

```cpp
string str = "apple and banana";
size_t pos = str.find("banana");  // 查找"banana"在字符串中的位置
if (pos != string::npos) {
    // 找到了"banana"
}
```

**改**（修改元素）

```cpp
string str = "apple and banana";
str.replace(6, 3, "or");  // 将从位置6开始的3个字符替换为"or"
```

**遍历**（访问元素）

```cpp
string str = "apple";
for (char c : str) {
    cout << c << endl;
}
// 或者使用迭代器遍历
for (auto it = str.begin(); it != str.end(); ++it) {
    cout << *it << endl;
}
```
# stack

`stack` 是一个容器适配器，用于给容器提供栈（FILO，先进后出）的特性。具有栈特性的意思是，元素的插入和删除只能在栈的顶部进行。

以下是`stack`的一些常用函数：

1. `push()`：向栈顶添加元素。

2. `pop()`：删除栈顶的元素。

3. `top()`：返回栈顶的元素。

4. `empty()`：检查栈是否为空。

5. `size()`：返回栈中的元素个数。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
stack<int> s;
s.push(1);  // 在栈顶添加元素
```

**删**（删除元素）

```cpp
stack<int> s;
s.push(1);
s.push(2);
s.pop();  // 删除栈顶的元素
```

**查**（查找元素）

```cpp
stack<int> s;
s.push(1);
s.push(2);
int top = s.top();  // 获取栈顶的元素
```

在栈中没有直接的修改元素的操作，如果你需要修改栈顶的元素，可以先使用`top()`获取到元素的引用，然后直接修改引用的值。但是，通常我们不会这么做，因为这违反了栈的先进后出的原则。

遍历`stack`并不像其他容器那样常见，因为栈的设计初衷是只能从顶部进行操作。然而，如果你真的需要遍历一个栈，可以这么做：

```cpp
stack<int> s;
// 先将元素添加到栈中
s.push(1);
s.push(2);
s.push(3);
// 然后遍历栈
stack<int> scopy = s;  // 创建一个栈的副本进行遍历
while(!scopy.empty()){
    cout << scopy.top() << endl;
    scopy.pop();
}
```

在这个代码中，我们创建了一个栈的副本进行遍历，这样原始栈的元素不会被删除。注意，在遍历过程中，我们不能修改栈中的元素。

# list
`list` 是一个双向链表容器，能够高效地进行插入和删除元素的操作。

以下是 `list` 的一些常用函数：

1. `push_back()`：在列表的末尾添加一个元素。

2. `push_front()`：在列表的开头添加一个元素。

3. `pop_back()`：删除列表的最后一个元素。

4. `pop_front()`：删除列表的第一个元素。

5. `insert()`：在指定位置插入一个元素。

6. `erase()`：删除指定位置的元素。

7. `size()`：返回列表中的元素个数。

8. `empty()`：检查列表是否为空。

9. `remove()`：从列表中移除所有等于给定值的元素。

10. `sort()`：排序列表中的元素。

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
list<int> lst;
lst.push_back(1);  // 在列表的末尾添加一个元素
lst.push_front(2);  // 在列表的开头添加一个元素
lst.insert(lst.begin(), 3);  // 在指定位置插入一个元素
```

**删**（删除元素）

```cpp
list<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.pop_back();  // 删除列表的最后一个元素
lst.pop_front();  // 删除列表的第一个元素
lst.erase(lst.begin());  // 删除指定位置的元素
lst.remove(1);  // 从列表中移除所有等于给定值的元素
```

**查**（查找元素）

在 `list` 中，没有直接获取元素的函数，我们通常需要通过迭代器来访问元素。

```cpp
list<int> lst;
lst.push_back(1);
lst.push_back(2);
for (auto it = lst.begin(); it != lst.end(); ++it) {
    if (*it == 2) {
        // 找到了元素2
    }
}
```

**改**（修改元素）

在 `list` 中，我们可以通过迭代器来修改元素。

```cpp
list<int> lst;
lst.push_back(1);
*lst.begin() = 2;  // 修改第一个元素的值为2
```

**遍历**（访问元素）

```cpp
list<int> lst;
lst.push_back(1);
lst.push_back(2);
for (auto it = lst.begin(); it != lst.end(); ++it) {
    cout << *it << endl;
}
// 或者使用 C++11 的范围基础 for 循环
for (const auto& elem : lst) {
    cout << elem << endl;
}
```

在上述代码中，`cout << *it << endl;` 和 `cout << elem << endl;` 是对每个元素执行的操作，你可以将其替换为你需要的操作。


 # algorithm


 