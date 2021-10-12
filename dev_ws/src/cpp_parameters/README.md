# cpp parameters

## build
```asm
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select cpp_parameters
```

## run

```asm
. install/setup.bash
ros2 run cpp_parameters parameter_node
```

## change param
```asm
ros2 run cpp_parameters parameter_node
ros2 param list
ros2 param set /parameter_node my_parameter earth
```

## launch
```asm
. install/setup.bash
ros2 launch cpp_parameters cpp_parameters_launch.py
# print follow
[parameter_node-1] [INFO] [custom_parameter_node]: Hello earth
```