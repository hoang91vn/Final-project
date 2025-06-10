file(GLOB TEST_SOURCES *.cpp)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE EconomicForecasting GTest::gtest GTest::gtest_main)
add_test(NAME alltests COMMAND tests)
