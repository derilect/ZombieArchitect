#ifndef ShaderProgram_H
#define ShaderProgram_H

#include <iostream>
#include <string>
#include <GL\glew.h>

namespace ZA_Game
{
	class ShaderProgram
	{
	private:
		int m_handle;
		bool m_linked;
		std::string m_log;
		int getUniformLocation(const char *_name);
		bool fileExists(const std::string &_filename);

	public:
	enum SHADERTYPE
	{
		VERTEX, FRAGMENT, GEOMETRY, TESS_CONTROL, TESS_EVALUATION
	};

	ShaderProgram();
	bool compileShaderFromFile(const char *_filename, SHADERTYPE _type);
	bool compileShaderFromString(const char &source, SHADERTYPE _type);
	bool link();
	void use();
	std::string log();
	int getHandle();
	bool isLinked();
	void bindAttribLocation(GLuint _location, const char *_name);
	void bindFragDataLocation(GLuint _location, const char *_name);

	void setUniform(const char *_name, float _x, float _y, float _z);
/*
	void setUniform(const char *_name, const vec3 &_v);
	void setUniform(const char *_name, const vec4 &_v);
	void setUniform(const char *_name, const mat4 &_m);
	void setUniform(const char *_name, const mat3 &_m);
*/
	void setUniform(const char *_name, float _val);
	void setUniform(const char *_name, int _val);
	void setUniform(const char *_name, bool _val);
	void printActiveUniforms();
	void printActiveAttribs();
	};

}


#endif