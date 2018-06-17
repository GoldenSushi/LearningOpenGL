#shader vertex
#version 440 core

layout(location = 0) in vec3 positions;
layout(location = 1) in vec2 textCoord;

out vec2 v_textCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
	gl_Position = perspective * view * model * vec4(positions, 1.0f);
	v_textCoord = textCoord;
}

#shader fragment
#version 440 core

in vec2 v_textCoord;
out vec4 texColor;
uniform sampler2D u_texture;
uniform sampler2D u_texture2;
uniform vec4 color;


void main()
{
	texColor = mix(texture(u_texture, v_textCoord) * color, texture(u_texture2, v_textCoord), 0.2);
}