#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>

float add(float a, float b);

int main()
{
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    GLFWwindow *window;
    
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );

    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();


	std::cout << add(59.60f, 10.9f) << '\n';
	return 0;
}