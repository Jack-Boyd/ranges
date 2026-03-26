#include <iostream>
#include <ranges>
#include <vector>

int main() {
  auto rng = std::views::iota(0, 20);
  std::vector<int> vec(rng.begin(), rng.end());

  auto view = vec | std::views::filter([](int x) { return x % 2 == 1; }) |
              std::views::transform([](int x) { return x * x; }) |
              std::views::take(15) | std::ranges::to<std::vector<int>>();

  for (int v : view) {
    std::cout << v << " ";
  }
  std::cout << "\n";

  return 0;
}
