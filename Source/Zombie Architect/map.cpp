#include "map.h"

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

bool TileMap::load(unsigned int _width, unsigned int _height, sf::Vector2u m_tileSize, const int *_tiles, const std::string& _tileset)
{
	if(!m_tileset.loadFromFile(_tileset))
		return false;

	m_width = _width;
	m_height = _height;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_width * m_height * 4);

	for(unsigned int y = 0; y < m_width; ++y)
	{
		for(unsigned int x = 0; x < m_height; ++x)
		{
			int tileNumber = _tiles[y + x * _width];

			int tu = tileNumber % (m_tileset.getSize().x / m_tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / m_tileSize.x);

			sf::Vertex *quad = &m_vertices[(y + x * m_width) * 4];

			quad[0].position = sf::Vector2f(y * m_tileSize.x, x * m_tileSize.y);
			quad[1].position = sf::Vector2f((y + 1) * m_tileSize.x, (x * m_tileSize.y));
			quad[2].position = sf::Vector2f((y + 1) * m_tileSize.x, (x + 1) * m_tileSize.y);
			quad[3].position = sf::Vector2f(y * m_tileSize.x, (x + 1) * m_tileSize.y);

			quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
/*
			quad[0].color = sf::Color::Blue;
			quad[1].color = sf::Color::Yellow;
			quad[2].color = sf::Color::Green;
			quad[3].color = sf::Color::Red;
			*/
		}
	}
	return true;
}

void TileMap::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
	_states.transform *= getTransform();
	_states.texture = &m_tileset;
	_target.draw(m_vertices, _states);
}
