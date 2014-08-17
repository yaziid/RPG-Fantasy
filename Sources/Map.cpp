#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <cctype>
#include <iostream>

#include "Map.hpp"

void Map::load(std::string filename, sf::RenderTarget& target)
{
    m_tilewidth = 16;
    m_tileheight = 16;

    std::ifstream openfile(filename);
    sf::Vector2i mape[200][200];
    sf::Vector2i loadCounter = sf::Vector2i(0, 0);
    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        mTileTexture.loadFromFile(tileLocation);
        mTiles.setTexture(mTileTexture);
        while(!openfile.eof())
        {
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
                mape[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            else
                mape[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');

            if(openfile.peek() == '\n')
            {
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else
                loadCounter.x++;
        }
        loadCounter.y++;
    }

    for(int i = 0; i < loadCounter.x; i++)
    {
        for(int j = 0; j < loadCounter.y; j++)
        {
            if(mape[i][j].x != -1 && mape[i][j].y != -1)
            {
                mTiles.setPosition(i * m_tilewidth, j * m_tileheight);
                mTiles.setTextureRect(sf::IntRect(mape[i][j].x * m_tilewidth, mape[i][j].y * m_tileheight, m_tilewidth, m_tileheight));
                target.draw(mTiles);
            }
        }
    }
}

