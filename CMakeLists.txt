cmake_minimum_required(VERSION 3.1)
project(matchers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

option(MATCHERS_BUILD_TESTS "Build the Matchers tests" ON)
option(MATCHERS_RUN_TESTS "Run the Matchers tests" ON)


include_directories("${PROJECT_SOURCE_DIR}")

if(MATCHERS_BUILD_TESTS)
	file(GLOB spec_sources specs/*.cpp)
	add_executable(specs ${spec_sources})
	if(MATCHERS_RUN_TESTS)
		add_custom_command(TARGET specs POST_BUILD
		                   COMMAND specs
		                   WORKING_DIRECTORY bin)
	endif()
endif()
