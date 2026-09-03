#include "ansi_esc.hpp"
#include "commands_view.hpp"
#include "threadsvm.hpp"
#include <string_view>
#include <array>

namespace display_command
{
  inline void display_commands() noexcept
  {
    for (const std::string_view& each : default_commands::commands)
    {
      threadwait::waithread_millisec(100);
      ansi_sequence_color::cout(true, 2, each);
    }
  }
}