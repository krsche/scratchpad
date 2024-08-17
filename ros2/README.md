# ROS2 Scratchpad

- [ROS Distributions (Versions)](https://docs.ros.org/en/humble/Releases.html)
- [Install Guide (Humble)](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)
- [Major Differences to ROS1](https://roboticsbackend.com/ros1-vs-ros2-practical-overview/)

- [Launch File in Python](https://roboticsbackend.com/ros2-launch-file-example/)
- [ROS2 Python Dependencies](https://docs.ros.org/en/rolling/How-To-Guides/Using-Python-Packages.html)

## Getting Started

See the docs for more info: [Creating Your First ROS2 Package](https://docs.ros.org/en/humble/Tutorials/Creating-Your-First-ROS2-Package.html)

```bash
# Create workspace
mkdir -p workspace/src

# Checkout sample files (if you want)
cd workspace/src
git clone https://github.com/ros/ros_tutorials.git -b humble-devel

# Install deps (in addition to ros-humble-desktop)
sudo apt install python3-colcon-common-extensions # colcon
sudo apt install python3-rosdep # rosdep

# rosdep
sudo rosdep init
rosdep update

cd .. # make sure to be in folder 'workspace' not 'workspace/src'
rosdep install -i --from-path src

# build
colcon build

# custom packages
cd src
ros2 pkg create --build-type ament_cmake --node-name hello-world  hello-world-cpp
ros2 pkg create --build-type ament_pytohn --node-name hello_world  hello_world_python # hyphens not allowed (pep-8)
cd ..
colcon build --packages-select hello-world-cpp
colcon build --packages-select hello-world-python
```
