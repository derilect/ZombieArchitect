#ifndef ShaderProgram_H
#define ShaderProgram_H


#include <iostream>
#include <string>
#include <GL\glew.h>

#include "Math\math.h"
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

namespace ZA_Game
{
	class ShaderProgram
	{
	private:
		GLuint m_shaderProgram;
		std::string m_log;

	private:
		char * loadShaderFile(const char  *_filename);

	public:
		ShaderProgram();
		~ShaderProgram();
		bool initialize(const char *_vertexShader, const char *_fragShader);
		void begin();
		void end();
		std::string log();

		bool setUniform(const char *_name, float _x, float _y, float _z);
		bool setUniform(const char *_name, float _x, float _y);

		bool setUniform(const char *_name, const glm::vec2 &_v);
		/*	
		bool setUniform(const char *_name, const vec3 &_v);
		bool setUniform(const char *_name, const vec4 &_v);
		bool setUniform(const char *_name, const mat4 &_m);
		bool setUniform(const char *_name, const mat3 &_m);
	*/	
		bool setUniform(const char *_name, float _val);
		bool setUniform(const char *_name, int _val);
		bool setUniform(const char *_name, bool _val);

		bool setSampler(const char *_name, int _slot, int _handle);
	};

}


#endif