# 二进制取幂快速幂

## 模版

```cpp
long long quick_pow(int base, int index)
{
    long long answer = 1;
    while (index > 0) {
        if (index & 1 == 1)
            answer *= base;
        base *= base;
        index >>= 1;
    }
    return answer;
}
```

## 复杂度

$ O(\log{n}) $。

## 原理提示

考虑指数为二进制时的求幂方法。