SET(EXAMPLE_NAME controlled_al5d)

FILE(GLOB_RECURSE ${EXAMPLE_NAME}_SRCS
        *.cpp)

ADD_EXECUTABLE(${EXAMPLE_NAME}_app
        # ${${PROJECT_NAME}_HDRS} # uncomment for debugging
        # ${${PROJECT_NAME}_TPPS} # uncomment for debugging
        # ${${PROJECT_NAME}_SRCS} # uncomment for debugging
        ${${EXAMPLE_NAME}_SRCS})

TARGET_LINK_LIBRARIES(${EXAMPLE_NAME}_app
        ${PROJECT_NAME})
