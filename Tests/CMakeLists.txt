# ========================================================================
# Thrive Tests
#
# This file contains the testing executable 
#
# ========================================================================

# Create the test executable
add_executable(ThriveTests
    # Add test files here below
    SceneTests.cpp
)

target_link_libraries(ThriveTests
    PRIVATE
        Engine
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ThriveTests)