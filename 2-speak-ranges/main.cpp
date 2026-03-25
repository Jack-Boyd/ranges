#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Person 
{
  int age;
  std::string name;
};

int main() 
{
  std::vector<Person> people {
    {29, "Jack"},
    {32, "Elise"},
    {66, "Jennifer"},
    {69, "Paul"},
    {30, "Hannah"},
    {31, "Dennis"},
    {4, "Veronica"},
    {1, "Helena"},
  };

  if (auto it = std::ranges::find(people, std::string("Hannah"), &Person::name); it != people.end()) {
    std::cout << std::format(
        "Person:\n"
        "  Name: {}\n"
        "  Age: {}\n",
        it->name, it->age);
  }

  auto isEvenAge = [](const Person& p) { return p.age % 2 == 0; };

  if (auto it = std::ranges::find_if(people, isEvenAge); it != people.end()) {
    std::cout << std::format(
        "Person:\n"
        "  Name: {}\n"
        "  Age: {}\n",
        it->name, it->age);
  }

  auto ageDivisibleBy = [](int d) {
    return [d](int age) { return p.age % d == 0; };
  };

  auto nameLongerThan = [](size_t n) {
    return [n](const& std::string name ) { return name.size() > n; };
  };

  if (std::ranges::any_of(people, ageDivisibleBy(5), &Person::age)) {
    std::cout << "There is a person with an age divisible by 5\n";
  }
  if (std::ranges::none_of(people, ageDivisibleBy(7), &Person::age)) {
    std::cout << "There is not a person with an age divisible by 7\n";
  }
  if (std::ranges::all_of(people, nameLongerThan(3), &Person::name)) {
    std::cout << "Everyones name is longer than 3 characters\n";
  }


  return 0;
}
