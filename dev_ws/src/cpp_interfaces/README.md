# cpp srvcli

## create pkg

```asm
ros2 pkg create --build-type ament_cmake cpp_interfaces --dependencies rclcpp tutorial_interfaces
```

## build

```asm
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select cpp_interfaces
```

## run

```asm
. install/setup.bash
ros2 run cpp_interfaces server
. install/setup.bash
ros2 run cpp_interfaces client 2 3
```