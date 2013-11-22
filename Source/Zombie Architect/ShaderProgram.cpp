#include <fstream>

#include "ShaderProgram.h"

namespace ZA_Game
{

	ShaderProgram::ShaderProgram()
	{
		m_handle = 0;
		m_linked = false;
		m_log = "";
	}

	bool ShaderProgram::fileExists(const std::string &_filename)
	{
		std::ifstream fileStream;
		fileStream.open(_filename.c_str(), std::ios::in);
		if(!fileStream.is_open())
			return false;

		fileStream.close();
		return true;
	}


}