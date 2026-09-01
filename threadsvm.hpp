#pragma once
#include <chrono>
#include <thread>
#include <random>

static int randomizedint(int maxnum, int minnum) noexcept
{
  std::random_device rd;
  std::mt19937_64 gen(rd());

  std::uniform_int_distribution<int> dist(maxnum, minnum);
  int get_num = dist(gen);
  return get_num;
}

namespace threadwait
{
  /// @brief yield thread
  /// @param num 1000 = 1sec
  inline void waithread_millisec(int num) noexcept
  {
    const int get_wait = num;
    std::this_thread::sleep_for(std::chrono::milliseconds(get_wait));
  }

  inline void randthread_millisec() noexcept
  {
    waithread_millisec(randomizedint(600, 3000));
  }
}