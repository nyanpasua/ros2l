# python srvcli

## create pkg

```asm
ros2 pkg create --build-type ament_python py_srvcli --dependencies rclpy example_interfaces
```

## build
```asm
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select py_srvcli
```

## run
```asm
. install/setup.bash
ros2 run py_srvcli service

. install/setup.bash
ros2 run py_srvcli client 2 3
```