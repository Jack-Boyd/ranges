#include <iostream>
#include <ranges>
#include <vector>

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  
  auto view = vec | 
    std::views::filter([](int x) {
      return x % 2 == 1;
    }) | 
    std::views::transform([](int x) {
      return x * x;
    }) | 
    std::views::take(15) | 
    std::ranges::to<std::vector<int>>();

  for (int v : view) {
    std::cout << v << " ";
  }
  std::cout << "\n";

  return 0;
}
