#include <fstream>
#include <assert.h>
#include "ShaderProgram.h"

namespace ZA_Game
{
	// Function: Constructor
	ShaderProgram::ShaderProgram()
	{
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_shaderProgram);
	}

	// Function: loadShaderFile - loads text from file into buffer and returns buffer
	char * ShaderProgram::loadShaderFile(const char *_filename)
	{
		FILE *fp;
		// Open file
		if(!(fp=fopen(_filename,"rb")))
		{
			return NULL;
		}

		// Find end of file, report back size and create buffer
		fseek(fp,0,SEEK_END);
		unsigned int size = ftell(fp);
		rewind(fp);
		char *buffer = new char[size + 1];

		// Test if buffer was created.
		if(buffer == NULL)
		{
			m_log = "Error creating buffer for shader source.\n";
			return NULL;
		}

		// Read in entire file into buffer
		int result = fread(buffer,sizeof(char),size, fp);
		if(result != size)
		{
			m_log = "Error reading data into buffer for shader source.\n";
			return NULL;
		}

		// Add null to end of line.
		buffer[size + 1] = '\0';
		fclose(fp);
		return buffer;
	}

	// function: Initialize the shaders
	bool ShaderProgram::initialize(const char *_vertexShader, const char *_fragShader)
	{
		if(_vertexShader == NULL)
			return false;

		if(_fragShader == NULL)
			return false;

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		const char *vertexBuffer = loadShaderFile(_vertexShader);
		if(vertexBuffer == NULL)
			return false;

		const char *fragBuffer = loadShaderFile(_fragShader);
		if(fragBuffer == NULL)
			return false;

		GLint result = GL_FALSE;

		glShaderSource(vertexShader, 1, &vertexBuffer, NULL);
		glCompileShader(vertexShader);
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE)
			return NULL;

		glShaderSource(fragShader, 1, &fragBuffer, NULL);
		glCompileShader(fragShader);
		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE)
			return NULL;

		m_shaderProgram = glCreateProgram();
		glAttachShader(m_shaderProgram, vertexShader);
		glAttachShader(m_shaderProgram, fragShader);
		glLinkProgram(m_shaderProgram);

		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &result);
		
		if(result == GL_FALSE)
			return NULL;

		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);
	}

	void ShaderProgram::begin()
	{
		assert(m_shaderProgram);
		glUseProgram(m_shaderProgram);
	}

	void ShaderProgram::end()
	{
		glUseProgram(NULL);
	}


	// Functions to set uniform variables overloaded methods.
	bool ShaderProgram::setUniform(const char *_name, float _val)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform1f(location, _val);
			return true;
		}

		return false;
	}

	bool ShaderProgram::setUniform(const char *_name, int _val)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform1i(location, _val);
			return true;
		}

		return false;
	}

	bool ShaderProgram::setUniform(const char *_name, bool _val)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform1i(location, _val);
			return true;
		}

		return false;
	}

	bool ShaderProgram::setUniform(const char *_name, float _x, float _y, float _z)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform3f(location, _x, _y, _z);
			return true;
		}

		return false;
	}

	bool ShaderProgram::setUniform(const char *_name, float _x, float _y)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform2f(location, _x, _y);
			return true;
		}

		return false;
	}

	bool ShaderProgram::setUniform(const char *_name, const glm::vec2 &_val)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glUniform2fv(m_shaderProgram, 1, glm::value_ptr(_val));
			return true;
		}

		return false;
	}

	bool ShaderProgram::setSampler(const char *_name, int _slot, int _handle)
	{
		if(_name == NULL)
			return false;

		GLint location = glGetUniformLocation(m_shaderProgram, _name);

		if(location >= 0)
		{
			glActiveTexture(GL_TEXTURE0 + _slot);
			glBindTexture(GL_TEXTURE_2D, _handle);

			glUniform1i(location, _slot);
			return true;
		}

		return false;
	}

}