#pragma once
#include<string>
#include<iostream>
#include "ansi_esc.hpp"
#include "buffer.hpp"

namespace comments
{
  inline bool is_comment = false;
  inline void get_user_comments(std::string& input_buffers)
  {
    ansi_sequence_color::cout(true, 2, "CVM++ -> your comments(*) ->");
    std::getline(std::cin, input_buffers);
    check_buffer::check_size(input_buffers, 8049, 0);
    is_comment = true;
  }
}