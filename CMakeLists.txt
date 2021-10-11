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

#this goes into the given subdirectory and executes the CMakeLists.txt there
add_subdirectory(Adder)

target_include_directories("${PROJECT_NAME}" PUBLIC Adder)

#tells it were to find the library to link is
target_link_directories("${PROJECT_NAME}" PRIVATE Adder)

#This links a library to the executable
target_link_libraries("${PROJECT_NAME}" adder)