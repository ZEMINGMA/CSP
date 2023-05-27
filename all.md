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
for (const auto& pair : m) {
    cout << pair.first << ": " << pair.second << endl;
}
// 或者使用迭代器遍历
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

在上述代码中，`cout << pair.first << ": " << pair.second << endl;`是对每个元素执行的操作，你可以将其替换为你需要的操作。