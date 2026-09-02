#pragma once
#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>

namespace ansi_sequence_color
{
  static constexpr std::array<std::string_view, 7> thincolor =
      {
          "\033[0m",
          "\033[31m",
          "\033[32m",
          "\033[33m",
          "\033[34m",
          "\033[35m",
          "\033[36m"};
  static constexpr std::array<std::string_view, 7> boldcolor =
      {
          "\033[1;37m",
          "\033[1;31m",
          "\033[1;32m",
          "\033[1;33m",
          "\033[1;34m",
          "\033[1;35m",
          "\033[1;36m"};

  inline void cout(bool is_bold, short int num_index, const std::string_view stringbuffer) noexcept
  {
    const size_t safe_index = static_cast<size_t>(std::clamp<short int>(num_index, 0, 7));

    const auto& color_table = is_bold ? boldcolor : thincolor;

    std::cout << color_table[safe_index] << stringbuffer << thincolor[0];
  }
}
