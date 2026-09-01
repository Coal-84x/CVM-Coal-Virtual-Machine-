#pragma once
#include "commands._view.hpp"
#include "ansi_esc.hpp"
#include "buffer.hpp"
#include "threadsvm.hpp"
#include <string_view>

namespace prompt_processor
{
  inline bool is_boot = false;

  inline void intro() noexcept
  {
    ansi_sequence_color::cout(true, 2, "Booting CVM++\n");
    ansi_sequence_color::cout(true, 2, "Under MIT License (M) CVM++. All Rights Reserved.\n\n");
  }

  inline void main_core() noexcept
  {
    is_boot = true;
    intro();

    std::string prompt;

    while (is_boot)
    {
      ansi_sequence_color::cout(true, 2, "CVM++ ->");
      if (!std::getline(std::cin, prompt))
      {
        break;
      }
      if (prompt == default_commands::function_caller.at(0))
      {
        ansi_sequence_color::cout(true, 2, "\nExiting CVM++\n");
        threadwait::randthread_millisec();
        break;
      }
      else
      {
        ansi_sequence_color::cout(true, 3, "unknown buffer.\n");
        prompt.clear();
        continue;
      }
    }
  }
}
