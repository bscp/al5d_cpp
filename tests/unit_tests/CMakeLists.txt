FIND_PACKAGE(GTest REQUIRED)

INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

FILE(GLOB_RECURSE ${PROJECT_NAME}_unit_test_SRCS
        *.cpp)

FILE(GLOB_RECURSE ${PROJECT_NAME}_unit_test_HDRS
        *.hpp)

SET(${PROJECT_NAME}_unittest_files
        ${${PROJECT_NAME}_unit_test_HDRS}
        ${${PROJECT_NAME}_unit_test_SRCS}
        test_main.cpp)  # TODO : remove

# Comment this section to enable debugging

ADD_EXECUTABLE(${PROJECT_NAME}_unit_test
        ${${PROJECT_NAME}_unittest_files})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_unit_test
        ${PROJECT_NAME}
        ${GTEST_LIBRARIES})

# Uncomment the following section for debugging

# ADD_EXECUTABLE(${PROJECT_NAME}_unit_test
#        ${${PROJECT_NAME}_files}
#        ${${PROJECT_NAME}_unittest_files})
#
# TARGET_LINK_LIBRARIES(${PROJECT_NAME}_unit_test
#        ${GTEST_LIBRARIES})
