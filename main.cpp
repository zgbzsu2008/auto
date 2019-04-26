#include <assert.h>
#include <iostream>
#include <tuple>
#include <type_traits>

// auto�����ʹ��class�������滻ֻ��typename
template <auto n>
auto f() -> std::pair<decltype(n), decltype(n)>
{
  return {n, n};
}

// auto �ṹ��������
int main()
{
  // ������
  {
    int a[2] = {1, 2};
    auto [x, y] = a;     // ����
    auto& [xr, yr] = a;  // ����
    xr = yr = 8;
  }

  // ��Ԫ��
  {
    float x{3.14f};
    char y{'a'};
    int z{2};

    std::tuple<float&, char&&, int> tpl(x, std::move(y), z);
    auto& [a, b, c] = tpl;
    auto [u, v, w] = std::tie(x, y, z);
    // ע�⣡������std::tuple std::tie auto�Ƶ���������
  }

  // �󶨵����ݳ�Ա
  {
    struct S {
      int x1 : 2;
      volatile double y1;
    };
    auto [x, y] = S{2, 3.14};
  }

  return 0;
}