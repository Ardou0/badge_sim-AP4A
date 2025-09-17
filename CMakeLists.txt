cmake_minimum_required(VERSION 4.0)
project(badge_sim)

set(CMAKE_CXX_STANDARD 17)

add_executable(badge_sim main.cpp
        src/Server.cpp
        include/Server.h
        src/Badge.cpp
        include/Badge.h
        src/BadgeReader.cpp
        include/BadgeReader.h
        src/Scheduler.cpp
        include/Scheduler.h
        src/Person.cpp
        include/Person.h)
