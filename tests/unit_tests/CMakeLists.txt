
FIND_PACKAGE(Boost REQUIRED COMPONENTS
        unit_test_framework)

FILE(GLOB_RECURSE ${PROJECT_NAME}_unit_tests_SRCS
        *.cpp)

FILE(GLOB_RECURSE ${PROJECT_NAME}_unit_tests_HDRS
        *.hpp)

SET(${PROJECT_NAME}_unittest_files
        ${${PROJECT_NAME}_unit_tests_HDRS}
        ${${PROJECT_NAME}_unit_tests_SRCS})

ADD_EXECUTABLE(${PROJECT_NAME}_unit_tests
        ${${PROJECT_NAME}_files} # linking the library would make debugging impossible
        ${${PROJECT_NAME}_unittest_files}
        test_main.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_unit_tests
        ${Boost_LIBRARIES})
