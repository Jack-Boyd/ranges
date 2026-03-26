#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

auto printSubrange = [](std::ranges::viewable_range auto &&r) {
  std::cout << '[';
  for (int pos{}; auto elem : r)
    std::cout << (pos++ ? " " : "") << elem;
  std::cout << "] ";
};

auto printView = [](std::string_view label, auto width,
                    std::ranges::viewable_range auto &&r) {
  std::cout << label << width << ": ";
  std::ranges::for_each(r, printSubrange);
  std::cout << "\n";
};

int main() {
  const auto v = std::views::iota(0, 10) | std::ranges::to<std::vector<int>>();

  for (const auto width : std::views::iota(1U, 2U + v.size()))
    printView("chuck(", std::to_string(width) + ")",
              v | std::views::chunk(width));

  for (const auto width : std::views::iota(1U, 1U + v.size()))
    printView("W = ", width, v | std::views::slide(width));
}
