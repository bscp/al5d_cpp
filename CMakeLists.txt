CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

PROJECT(al5d_cpp
        VERSION 0.0.1
        LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 14)

ADD_COMPILE_OPTIONS(
        -std=c++14 -Wall -Wconversion -Wextra)
        
# USE COMMAND: 'cmake .. -DAL5D_CPP_BUILD_TESTS=ON'
OPTION(AL5D_CPP_BUILD_TESTS "Enable test building" OFF)

# USE COMMAND: 'cmake .. -DAL5D_CPP_BUILD_EXAMPLES=ON'
OPTION(AL5D_CPP_BUILD_EXAMPLES "Enable example building" OFF)

FIND_PACKAGE(Boost REQUIRED COMPONENTS
        thread
        system)

FIND_PACKAGE(yaml-cpp REQUIRED)

INCLUDE_DIRECTORIES(include)

INCLUDE(GNUInstallDirs)

# ----------------------------------------
# LIBRARY TARGET
# ----------------------------------------

FILE(GLOB_RECURSE ${PROJECT_NAME}_HDRS
        include/${PROJECT_NAME}/*.hpp)

FILE(GLOB_RECURSE ${PROJECT_NAME}_TPPS
        include/${PROJECT_NAME}/*.tpp)

FILE(GLOB_RECURSE ${PROJECT_NAME}_SRCS
        src/*.cpp)

SET(${PROJECT_NAME}_files
        ${${PROJECT_NAME}_HDRS}
        ${${PROJECT_NAME}_TPPS}
        ${${PROJECT_NAME}_SRCS})

ADD_LIBRARY(${PROJECT_NAME} SHARED
        ${${PROJECT_NAME}_files})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        ${Boost_LIBRARIES}
        yaml-cpp)

# ----------------------------------------
# LIBRARY TARGET INSTALL
# ----------------------------------------

TARGET_INCLUDE_DIRECTORIES(
        ${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

TARGET_COMPILE_DEFINITIONS(
        ${PROJECT_NAME} PRIVATE -D_EXPORT)

INSTALL(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-config
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

INSTALL(EXPORT ${PROJECT_NAME}-config
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

INSTALL(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# ----------------------------------------
# OTHER TARGETS
# ----------------------------------------

IF(AL5D_CPP_BUILD_TESTS)
        MESSAGE("BUILDING TESTS..............")
        ADD_SUBDIRECTORY(tests)
ENDIF()

IF(AL5D_CPP_BUILD_EXAMPLES)
        MESSAGE("BUILDING EXAMPLES..............")
        ADD_SUBDIRECTORY(examples)
ENDIF()
