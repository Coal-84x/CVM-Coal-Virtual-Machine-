#include "ansi_esc.hpp"

namespace output
{
  inline void get_user_buffer(std::string& buffer)
  {
    ansi_sequence_color::cout(true, 0, "\n>>" + buffer + "\n\n");
    buffer.clear();
  }
}