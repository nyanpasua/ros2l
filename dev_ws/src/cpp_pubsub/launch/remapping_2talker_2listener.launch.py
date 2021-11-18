import launch
import launch.actions
import launch.substitutions
import launch_ros.actions


def generate_launch_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='cpp_pubsub',
            executable='talker',
            output='screen',
            namespace='ns0',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker0'],
            remappings=[
                ('topic', '/topic0'),
            ]),
        launch_ros.actions.Node(
            package='cpp_pubsub',
            executable='talker',
            output='screen',
            namespace='ns0',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker1'],
            remappings=[
                ('topic', '/topic1'),
            ]),
        launch_ros.actions.Node(
            package='cpp_pubsub',
            executable='listener',
            output='screen',
            namespace='ns1',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener0'],
            remappings=[
                ('topic', '/topic0'),
            ]),
        launch_ros.actions.Node(
            package='cpp_pubsub',
            executable='listener',
            output='screen',
            namespace='ns1',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener1'],
            remappings=[
                ('topic', '/topic1'),
            ]),
    ])
