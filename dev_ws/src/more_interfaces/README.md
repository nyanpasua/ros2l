# Expanding ROS 2 interfaces

## create

```asm
ros2 pkg create --build-type ament_cmake more_interfaces
```

## build

```asm
colcon build --packages-up-to more_interfaces
```

> --packages-up-to [PKG_NAME [PKG_NAME ...]]
Only process a subset of packages and their recursive dependencies

## run

```asm
. install/local_setup.bash
ros2 run more_interfaces publish_address_book
```

## use predefine interface

```asm
# in my msg, would use rosidl_tutorials_msgs/Contact
rosidl_tutorials_msgs/Contact[] address_book
# package.xml:
<build_depend>rosidl_tutorials_msgs</build_depend>
<exec_depend>rosidl_tutorials_msgs</exec_depend>
# cmake
find_package(rosidl_tutorials_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES rosidl_tutorials_msgs
)
# source
#include "rosidl_tutorials_msgs/msg/contact.hpp"
```

