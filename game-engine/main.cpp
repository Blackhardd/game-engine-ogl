#include<iostream>
#include"GL\glew.h"
#include"display.h"
#include"shader.h"
#include"mesh.h"
#include"texture.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Viewport 1");

	Shader shader("./res/basicShader");
	Texture texture("./res/texture.jpg");

	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(1.0, 0.0)),  };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 01.0f);

		texture.Bind(0);
		shader.Bind();
		mesh.Draw();

		display.Update();
	}

	return 0;
}