# cpp srvcli

## create pkg

```asm
ros2 pkg create --build-type ament_cmake cpp_srvcli --dependencies rclcpp example_interfaces
```

> --dependencies argument will automatically add the necessary dependency lines to package.xml and CMakeLists.txt. example_interfaces is the package that includes the .srv file you will need to structure your requests and responses:


## build
```asm
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select cpp_srvcli
```

## run
```asm
. install/setup.bash
ros2 run cpp_srvcli server
. install/setup.bash
ros2 run cpp_srvcli client 2 3
```