FIND_PACKAGE(GTest REQUIRED)

INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

FILE(GLOB_RECURSE ${PROJECT_NAME}_test_SRCS
        *.cpp)

FILE(GLOB_RECURSE ${PROJECT_NAME}_test_HDRS
        *.hpp)

SET(${PROJECT_NAME}_test_files
        ${${PROJECT_NAME}_test_HDRS}
        ${${PROJECT_NAME}_test_SRCS}
        test_main.cpp)

# The following section needs to be commented to debug within the library
ADD_EXECUTABLE(${PROJECT_NAME}_test
        ${${PROJECT_NAME}_test_files})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_test
        ${PROJECT_NAME}
        ${GTEST_LIBRARIES} pthread)

# The following section can be uncommented to debug within the library
# ADD_EXECUTABLE(${PROJECT_NAME}_test
#        ${${PROJECT_NAME}_files}
#        ${${PROJECT_NAME}_test_files})
#
# TARGET_LINK_LIBRARIES(${PROJECT_NAME}_test
#        ${GTEST_LIBRARIES})
