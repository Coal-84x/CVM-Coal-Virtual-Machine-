#pragma once
#include <string>
#include "ansi_esc.hpp"

namespace check_buffer
{
  inline void check_size(std::string& buffer, size_t max, const size_t min) noexcept
  {
    if (buffer.length() > max || buffer.length() < min)
    {
      ansi_sequence_color::cout(false, 3, "max buffer || tiny buffer");
      buffer.clear();
    }
  }
}