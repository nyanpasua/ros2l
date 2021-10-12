# python parameters

## create pkg
```asm
ros2 pkg create --build-type ament_python python_parameters --dependencies rclpy
```

## build
```asm
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select python_parameters
```

## run
```asm
. install/setup.bash
ros2 run python_parameters param_talker
```
## change
```asm
ros2 param list
ros2 param set /minimal_param_node my_parameter earth
```

## launch
```asm
. install/setup.bash
ros2 launch python_parameters python_parameters_launch.py
```