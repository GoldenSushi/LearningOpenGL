#shader vertex
#version 440 core

layout(location = 0) in vec3 vertices;


void main()
{
	gl_Position = vec4(vertices, 1.0);
}

#shader fragment
#version 440 core

out vec4 texColor;


void main()
{
	texColor = vec4(0.0, 0.0, 0.0, 1.0);
}