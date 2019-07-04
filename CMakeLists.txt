project(NetAdapter)
cmake_minimum_required(VERSION 3.5) 

set(TARGET "net_adapter")

AUX_SOURCE_DIRECTORY(./NetAdapter DIR_SRCS)

ADD_LIBRARY(${TARGET} ${DIR_SRCS} net_adapter_infos.cpp)

