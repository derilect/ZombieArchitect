#ifndef _MAP_HPP
#define _MAP_HPP

#include <SFML\Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
	unsigned int m_width;
	unsigned int m_height;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

public:
	TileMap();
	~TileMap();

	bool load(unsigned int _width, unsigned int _height, sf::Vector2u m_tileSize, const int *_tiles, const std::string& _tileset);
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

};

#endif