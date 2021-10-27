include(CPM.cmake)
set(ARCH_PLAT_VENDOR x86_64-ubuntu-linux-gcc9.3.0)
CPMAddPackage(
  NAME glog
  URL http://mirrors.phigent.io/nfs/pkgs/glog_0.5.0/${ARCH_PLAT_VENDOR}/glog_0.5.0.tar
)
include_directories(${glog_SOURCE_DIR}/include)
link_directories(${glog_SOURCE_DIR}/lib)

CPMAddPackage(
        NAME gflags
        URL http://mirrors.phigent.io/nfs/pkgs/gflags_2.2.2/${ARCH_PLAT_VENDOR}/gflags_2.2.2.tar
)
include_directories(${gflags_SOURCE_DIR}/include)
link_directories(${gflags_SOURCE_DIR}/lib)

CPMAddPackage(
        NAME opencv
        URL http://mirrors.phigent.io/nfs/pkgs/openCV_3.4.7/${ARCH_PLAT_VENDOR}/opencv_3.4.7_world.tar
)
include_directories(${opencv_SOURCE_DIR}/include)
link_directories(${opencv_SOURCE_DIR}/lib)
