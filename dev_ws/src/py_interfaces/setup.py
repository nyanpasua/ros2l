from setuptools import setup

package_name = 'py_interfaces'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='docker',
    maintainer_email='yingmin.li@phigent.ai',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = py_interfaces.publisher_member_function:main',
            # publisher_member_function is the python file name
            'listener = py_interfaces.subscriber_member_function:main',
            # subscriber_member_function is the python file name
            'service = py_interfaces.service_member_function:main',
            'client = py_interfaces.client_member_function:main',
        ],
    },
)
