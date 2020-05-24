
SET(EXAMPLE_NAME controlled_al5d)

FILE(GLOB_RECURSE ${PROJECT_NAME}_${EXAMPLE_NAME}_SRCS
        *.cpp)

ADD_EXECUTABLE(${PROJECT_NAME}_${EXAMPLE_NAME}_app
        # ${${PROJECT_NAME}_HDRS} # uncomment for debugging
        # ${${PROJECT_NAME}_TPPS} # uncomment for debugging
        # ${${PROJECT_NAME}_SRCS} # uncomment for debugging
        ${${PROJECT_NAME}_${EXAMPLE_NAME}_SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_${EXAMPLE_NAME}_app
        ${PROJECT_NAME})
