//
// Created by liyingmin on 2021/11/15.
// Copyright (c) 2021 PhiGent Inc. All rights reserved.
//

#pragma once
#include <cstdint>
#include <ctime>
#include <string>

namespace time_util {

struct TimeUtil {
  static void ms2timespec(struct timespec* ts, uint64_t ms) {
    ts->tv_sec = static_cast<int64_t>(ms / (uint64_t)1000);
    ts->tv_nsec = static_cast<int64_t>((ms % 1000) * (uint64_t)1000000);
  }

  static void us2timespec(struct timespec* ts, uint64_t us) {
    ts->tv_sec = static_cast<int64_t>(us / (uint64_t)1000000);
    ts->tv_nsec = static_cast<int64_t>(us % (uint64_t)1000000 * (uint64_t)1000);
  }

  static void ns2timespec(struct timespec* timespec, uint64_t nsec) {
    timespec->tv_sec = static_cast<int64_t>(nsec / (uint64_t)1000000000);
    timespec->tv_nsec = static_cast<int64_t>(nsec % (uint64_t)1000000000);
  }

  static uint64_t timespec2ms(const timespec& timespec) {
    return timespec.tv_sec * 1000 + (timespec.tv_nsec) / 1000000;
  }

  static uint64_t timespec2ms(const time_t& sec, const int64_t& nsec) {
    return sec * 1000 + nsec / 1000000;
  }

  static uint64_t timespec2us(const timespec& timespec) {
    return timespec.tv_sec * 1000000 + (timespec.tv_nsec) / 1000;
  }

  static uint64_t timespec2us(const time_t& sec, const int64_t& nsec) {
    return sec * 1000000 + nsec / 1000;
  }

  static uint64_t timespec2ns(const timespec& timespec) {
    return timespec.tv_sec * 1000000000 + timespec.tv_nsec;
  }

  static uint64_t timespec2ns(const time_t& sec, const int64_t& nsec) {
    return sec * 1000000000 + nsec;
  }

  static void MonotonicToRealTime(const timespec& monotonic_time,
                                  timespec& real_time) {
    struct timespec real_sample {};
    struct timespec monotonic_sample {};
    clock_gettime(CLOCK_MONOTONIC, &monotonic_sample);
    clock_gettime(CLOCK_REALTIME, &real_sample);

    uint64_t time_diff{};
    time_diff = timespec2ns(real_sample) - timespec2ns(monotonic_sample);
    ns2timespec(&real_time, timespec2ns(monotonic_time) + time_diff);
  }

  static std::string GetLocalTimeFromSec(time_t sec) {
    char buff[80];
    strftime(buff, sizeof buff, "%D %T", localtime(&sec));
    return buff;
  }
};

}  // namespace time_util
