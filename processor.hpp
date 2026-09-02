#pragma once
#include <string_view>
#include "commands._view.hpp"
#include "ansi_esc.hpp"
#include "buffer.hpp"
#include "threadsvm.hpp"
#include "comment_lines.hpp"
#include "output_write.hpp"
#include <string_view>

namespace prompt_processor
{
  const std::string cli_name = "CVM++";
  const std::string license = "Under MIT License (M) CVM++, we're not responsible for any internal damages. All Rights Reserved.";
  const std::string input_name = "CVM++ ->";
  inline bool is_boot = false;
  inline void intro() noexcept
  {
    ansi_sequence_color::cout(true, 2, "Booting " + cli_name + '\n');
    ansi_sequence_color::cout(true, 2, license + "\n\n");
  }

  inline void main_core() noexcept
  {
    is_boot = true;
    intro();

    std::string prompt;

    std::string get_user_comments;

    std::string get_user_write;
    while (is_boot)
    {
      if (!comments::is_comment || get_user_comments.empty())
      {
        ansi_sequence_color::cout(true, 2, input_name);
      }
      else
      {
        ansi_sequence_color::cout(true, 5, "\n-- " + get_user_comments + "\n");
        ansi_sequence_color::cout(true, 2, input_name);
      }
      if (!std::getline(std::cin, prompt))
      {
        prompt.clear();
        get_user_comments.clear();
        break;
      }
      ///
      if (prompt == default_commands::function_caller.at(0))
      {
        get_user_comments.clear();
        ansi_sequence_color::cout(true, 2, "\nExiting " + cli_name);
        threadwait::randthread_millisec();
        break;
      }
      ///
      else if (prompt == default_commands::function_caller.at(1))
      {
        if (!get_user_comments.empty())
        {
          get_user_comments.clear();
          comments::get_user_comments(get_user_comments);
        }
        else
        {
          comments::get_user_comments(get_user_comments);
        }
      }
      ///
      else if (prompt == default_commands::function_caller.at(2))
      {
        ansi_sequence_color::cout(true, 2, input_name + "write(*)-> ");
        std::getline(std::cin, get_user_write);

        output::get_user_buffer(get_user_write);
      }
      ///
      else
      {
        ansi_sequence_color::cout(true, 3, "unknown buffer.\n");
        prompt.clear();
        continue;
      }
    }
  }
}
