#include <iostream>
#include <ranges>
#include <typeinfo>

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  
  auto view = 
    std::views::filter(vec, [](int i) {
      return i % 2 == 1;
    }) | std::views::transform([](int i) {
      return i * i;
    });

  for (auto i : view) {
    std::cout << i << std::endl;
  }
  return 0;
}
