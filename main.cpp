#include <assert.h>
#include <iostream>
#include <tuple>
#include <type_traits>

// auto替代能使用class但不能替换只能typename
template <auto n>
auto f() -> std::pair<decltype(n), decltype(n)>
{
  return {n, n};
}

// auto 结构化绑定声明
int main()
{
  // 绑定数组
  {
    int a[2] = {1, 2};
    auto [x, y] = a;     // 复制
    auto& [xr, yr] = a;  // 引用
    xr = yr = 8;
  }

  // 绑定元组
  {
    float x{3.14f};
    char y{'a'};
    int z{2};

    std::tuple<float&, char&&, int> tpl(x, std::move(y), z);
    auto& [a, b, c] = tpl;
    auto [u, v, w] = std::tie(x, y, z);
    // 注意！！对于std::tuple std::tie auto推导都是引用
  }

  // 绑定到数据成员
  {
    struct S {
      int x1 : 2;
      volatile double y1;
    };
    auto [x, y] = S{2, 3.14};
  }

  return 0;
}