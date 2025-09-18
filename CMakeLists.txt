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
        include/Person.h
        src/Student.cpp
        include/Student.h
        src/StudentBadge.cpp
        include/StudentBadge.h
        src/Teacher.cpp
        include/Teacher.h
        src/SecurityStaff.cpp
        include/SecurityStaff.h
        include/utils.h
        src/utils.cpp
        src/AdministrativeStaff.cpp
        include/AdministrativeStaff.h
        src/TeacherBadge.cpp
        include/TeacherBadge.h
        src/SecurityBadge.cpp
        include/SecurityBadge.h
        src/AdministrativeBadge.cpp
        include/AdministrativeBadge.h
        src/RoomReader.cpp
        include/RoomReader.h
        src/BuildingReader.cpp
        include/BuildingReader.h)


add_custom_target(run_drmemory
        COMMAND "C:/Program Files (x86)/Dr. Memory/bin64/drmemory.exe" -- ${CMAKE_BINARY_DIR}/badge_sim.exe
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        DEPENDS badge_sim
)