#pragma once
#include <string_view>
#include <array>

namespace default_commands 
{
  constexpr inline std::array<std::string_view, 3> function_caller = 
  {
    "exit;",
    "comments;",
    "write;"
  };
}
