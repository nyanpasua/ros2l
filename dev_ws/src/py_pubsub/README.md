# minimal Pub/Sub


## 依赖检查
```asm
# from workspace root path
rosdep install -i --from-path src --rosdistro galactic -y
```

## build

```asm
# from workspace root path
colcon build --packages-select py_pubsub
```

## run
```asm
# 新开一个terminal
. install/setup.bash
ros2 run py_pubsub talker

# 再新开一个terminal
. install/setup.bash
ros2 run py_pubsub listener
```



