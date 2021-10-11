# msg/srv

## cmake
```asm
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "srv/AddThreeInts.srv"
 )
```
> 使用 rosidl_generator 产生不同语言的接口

## package.xml
```asm
<build_depend>rosidl_default_generators</build_depend>

<exec_depend>rosidl_default_runtime</exec_depend>

<member_of_group>rosidl_interface_packages</member_of_group>
```

## build
```asm
colcon build --packages-select tutorial_interfaces
```