#shader vertex
#version 330 core

layout(location = 0) in vec4 triangle_2;
layout(location = 0) in vec4 triangle_1;

void main()
{
	gl_Position = triangle_2;
	gl_Position = triangle_1;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(0.0, 1.0, 1.0, 1.0);
}