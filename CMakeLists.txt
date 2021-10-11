#Set this to whatever version you are using
cmake_minimum_required(VERSION "3.21.3")

project("Adder")

#the PROJECT_NAME variable is automatically set equal to what is inside the parenthesis above
#to reference the data PROJECT_NAME holds (in this case a string called "HelloWorld")
#we must "dereference" it like so:
#     "$(PROJECT_NAME)"
#use of double quotes around string variables (like the one above) is best practice
#takes 2 parameters, first will be the name of the executable target
#second is the source code necessary to build the executable

add_executable("${PROJECT_NAME}" "main.cpp")






#This links a library to the executable
#the glfw library linked is called "libglfw3.a",
#but you leave out "lib" and the line ending
#....usually, in this case there is a #define in the libraries cmake
target_link_libraries("${PROJECT_NAME}" adder glfw)

#When you clone the project, it is not automatically going to grab the submodules.
#You can write this git command to do this:
#	git submodule update --init --recursive
#or you can do this in the cmake file:
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()







#this goes into the given subdirectory and executes the CMakeLists.txt there
add_subdirectory(Adder)

add_subdirectory(external/glfw)

target_include_directories("${PROJECT_NAME}" 
	PUBLIC Adder 
	PUBLIC external/glfw/include
)

#tells it were to find the library to link is
#it is gonna look in the build directory
target_link_directories("${PROJECT_NAME}" 
	PRIVATE Adder
	PRIVATE external/glfw/src
)

