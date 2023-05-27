在C++中，`std::vector`是一个非常常用的动态数组类。下面列出一些常用的函数及其简单的描述，然后列出这些函数在增删改查操作中的应用。

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

以下是这些函数在增删改查操作中的应用：

**增**（添加元素）

```cpp
std::vector<int> vec;
vec.push_back(1);  // 添加一个元素到尾部
vec.insert(vec.begin(), 0);  // 在指定位置插入元素
```

**删**（删除元素）

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
vec.pop_back();  // 删除尾部元素
vec.erase(vec.begin());  // 删除指定位置元素
vec.clear();  // 清空所有元素
```

**改**（修改元素）

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
vec[0] = 5;  // 使用下标修改元素
vec.at(1) = 6;  // 使用at函数修改元素
```

**查**（访问元素）

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
int first_element = vec[0];  // 使用下标访问元素
int second_element = vec.at(1);  // 使用at函数访问元素
```

请注意，`at()`函数和`operator[]`在访问超出范围的元素时，行为不同。`at()`函数将抛出一个`std::out_of_range`异常，而`operator[]`没有定义超出范围的行为，可能会导致未定义的行为。

在C++中，遍历`std::vector`的方式有很多种。以下是其中的几种常见方法：

**1. 使用经典的for循环**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << std::endl;
}
```

**2. 使用范围based的for循环**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (const auto& val : vec) {
    std::cout << val << std::endl;
}
```

**3. 使用迭代器**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
}
```

**4. 使用STL的算法`std::for_each`**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
std::for_each(vec.begin(), vec.end(), [](int val) {
    std::cout << val << std::endl;
});
```

以上代码中，`std::cout << val << std::endl;`是打印每个元素的操作，你可以替换为你自己需要的操作。在C++中，遍历`std::vector`的方式有很多种。以下是其中的几种常见方法：

**1. 使用经典的for循环**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << std::endl;
}
```

**2. 使用范围based的for循环**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (const auto& val : vec) {
    std::cout << val << std::endl;
}
```

**3. 使用迭代器**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
}
```

**4. 使用STL的算法`std::for_each`**

```cpp
std::vector<int> vec = {0, 1, 2, 3, 4};
std::for_each(vec.begin(), vec.end(), [](int val) {
    std::cout << val << std::endl;
});
```

以上代码中，`std::cout << val << std::endl;`是打印每个元素的操作，你可以替换为你自己需要的操作。