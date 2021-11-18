// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <functional>
#include <memory>

#include "common/time_util.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using time_util::TimeUtil;

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

 private:
  void topic_callback(const std_msgs::msg::String::ConstSharedPtr msg) const {
    builtin_interfaces::msg::Time stamp(now());
    time_t measure_time = stamp.sec;
    auto local_sec_str = TimeUtil::GetLocalTimeFromSec(measure_time);
    RCLCPP_INFO(
        this->get_logger(),
        "I heard: '%s', timestamp: %s.%09ld UTC, epoch: %ld ms",
        msg->data.c_str(), local_sec_str.c_str(), (long)stamp.nanosec,
        TimeUtil::timespec2ms((time_t)stamp.sec, (int64_t)stamp.nanosec));
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
