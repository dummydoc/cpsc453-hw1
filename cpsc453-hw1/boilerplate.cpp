// ==========================================================================
// Barebones OpenGL Core Profile Boilerplate
//    using the GLFW windowing system (http://www.glfw.org)
//
// Loosely based on
//  - Chris Wellons' example (https://github.com/skeeto/opengl-demo) and
//  - Camilla Berglund's example (http://www.glfw.org/docs/latest/quick.html)
//
// Author:  Sonny Chan, University of Calgary
// Date:    December 2015
// ==========================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Hexagon.hpp"
#include "Triangle.hpp"

#define GLFW_INCLUDE_GLCOREARB
#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

class Program {
  GLuint vertex_shader;
  GLuint fragment_shader;
public:
  GLuint id;
  Program() {
    vertex_shader=0;
    fragment_shader=0;
    id=0;
  }
  Program(string vertex_path, string fragment_path) {
    init(vertex_path,fragment_path);
  }
  void init(string vertex_path, string fragment_path) {
    id=glCreateProgram();
    vertex_shader=addShader(vertex_path,GL_VERTEX_SHADER);
    fragment_shader=addShader(fragment_path,GL_FRAGMENT_SHADER);
    if(vertex_shader) glAttachShader(id,vertex_shader);
    if(fragment_shader) glAttachShader(id,fragment_shader);

    glLinkProgram(id);
  }
  GLuint addShader(string path, GLuint type) {
    std::ifstream in(path);
    string buffer = [&in]{
      std::ostringstream ss{};
      ss << in.rdbuf();
      return ss.str();
    }();
    const char *buffer_array[]={buffer.c_str()};

    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, buffer_array, 0);
  	glCompileShader(shader);

    // Compile results
    GLint status;
  	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  	if (status == GL_FALSE)
  	{
  		GLint length;
  		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
  		string info(length, ' ');
  		glGetShaderInfoLog(shader, info.length(), &length, &info[0]);
  		cerr << "ERROR compiling shader:" << endl << endl;
  		cerr << info << endl;
  	}
    return shader;
  }
  ~Program() {
    glUseProgram(0);
    glDeleteProgram(id);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
  }
};


class VertexArray {
  std::map<string,GLuint> buffers;
public:
  GLuint id;
  unsigned int count;
  VertexArray(int c) {
    glGenVertexArrays(1, &id);
    count = c;
  }
  void addBuffer(string name, int index, vector<float> buffer) {
    GLuint buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, buffer.size()*sizeof(float), buffer.data(), GL_STATIC_DRAW);
    buffers[name]=buffer_id;

    int components=buffer.size()/count;
    glBindVertexArray(id);
    glVertexAttribPointer(index, components, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(index);

    // unset states
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }
  void updateBuffer(string name, vector<float> buffer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffers[name]);
    glBufferData(GL_ARRAY_BUFFER, buffer.size()*sizeof(float), buffer.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
  ~VertexArray() {
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    for(auto &ent: buffers)
  	  glDeleteBuffers(1, &ent.second);
  }
};

void render(Program &program, VertexArray &va)
{
	// clear screen to a dark grey colour
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(program.id);
	glBindVertexArray(va.id);
	glDrawArrays(GL_TRIANGLES, 0, va.count);

	glBindVertexArray(0);
	glUseProgram(0);

}

int main(int argc, char *argv[])
{
	// initialize the GLFW windowing system
	if (!glfwInit()) {
		cout << "ERROR: GLFW failed to initialize, TERMINATING" << endl;
		return -1;
	}
	glfwSetErrorCallback([](int error, const char* description){
    cout << "GLFW ERROR " << error << ":" << endl;
    cout << description << endl;
  });

  // Use OpenGL 4.1
	GLFWwindow *window = 0;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(512, 512, "CPSC 453 OpenGL Boilerplate", 0, 0);
	if (!window) {
		cout << "Program failed to create GLFW window, TERMINATING" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


  Program p("vertex.glsl","fragment.glsl");
  VertexArray va(3);
  va.addBuffer("v", 0, vector<float>{
    0.5,0.2,
    0.2,0.6,
    0.8,0.6
  });

	// run an event-triggered main loop
	while (!glfwWindowShouldClose(window))
	{
    // render
		render(p,va);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	cout << "The End" << endl;
	return 0;
}
