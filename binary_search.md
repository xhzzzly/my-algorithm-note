# 二分模版



**注意**：以下代码适用范围均为左闭右开（下标从0开始）



#### 找后继（找目标，或第一个大于目标的数，或多个目标中的第一个位置）

```cpp
size_t bs(int a[], size_t n, const int &val)
{
    size_t left = 0, right = n;
    while (left < right) {
        size_t mid = (left + right) >> 1;
        if (mid < n && a[mid] >= val) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```



#### 找后继（找大于目标的第一个数）

```cpp
size_t bs(int a[], size_t n, const int &val)
{
    size_t left = 0, right = n;
    while (left < right) {
        size_t mid = (left + right) >> 1;
        if (mid < n && a[mid] > val) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```



#### 找前驱（找目标，或第一个小于目标的数，或多个目标中的最后一个位置）

```cpp
size_t bs(int a[], size_t n, const int &val)
{
    size_t left = 0, right = n;
    while (left < right) {
        size_t mid = (left + right + 1) >> 1;
        if (mid < n && a[mid] <= val) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```



#### 找前驱（找第一个小于目标的数）

```cpp
size_t bs(int a[], size_t n, const int &val)
{
    size_t left = 0, right = n;
    while (left < right) {
        size_t mid = (left + right + 1) >> 1;
        if (mid < n && a[mid] < val) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

