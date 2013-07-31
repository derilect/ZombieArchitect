#pragma once

#if defined(_DEBUG) || defined(DEBUG)
	#pragma comment(lib, "sfml-window-s-d.lib")
	#pragma comment(lib, "sfml-system-s-d.lib")
	#pragma comment(lib, "sfml-graphics-s-d.lib")

#else
	#pragma comment(lib, "sfml-window-s.lib")
	#pragma comment(lib, "sfml-system-s.lib")
	#pragma comment(lib, "sfml-graphics-s.lib")

#endif

#pragma warning (disable : 4099)

#ifndef SFML_STATIC
#define SFML_STATIC
#endif
 
#include <SFML\Graphics.hpp>
