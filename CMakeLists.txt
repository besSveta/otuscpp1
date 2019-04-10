cmake_minimum_required(VERSION 3.2)

project(cmake VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(buildNumber.h.in ${PROJECT_SOURCE_DIR}/buildNumber.h)

add_executable(helloworld main.cpp)

add_executable(test_build test_build.cpp)

set_target_properties(helloworld test_build PROPERTIES
	CXXSTANDARD 17
	CSS_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_build PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)


target_link_libraries(test_build
	${Boost_LIBRARIES}
)
	
install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT bessveta@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_build)
