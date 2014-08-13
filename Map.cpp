#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <cctype>

#include "Map.hpp"

void Map::load(std::string filename, sf::RenderWindow& window)
{
    std::fstream openfile(filename);

    sf::Vector2i map[100][100];
    sf::Vector2i loadCounter = sf::Vector2i(0, 0);

    if(openfile)
    {
        std::string tileLocation;
        openfile << tileLocation;
        mTileTexture.loadFromFile(tileLocation);
        mTiles.setTexture(mTileTexture);
        while(!openfile.eof())
        {
            std::string str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            else
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');

            if(openfile.peek() == '/n')
            {
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else
                loadCounter.x++;
        }
        loadCounter.y++;
    }

    for(int i(0); i < loadCounter.x; ++i)
    {
        for(int j(0); j < loadCounter.y; ++j)
        {
            if(map[i][j].x != -1 && map[i][j].y != -1)
            {
                mTiles.setPosition(i * mTileTexture.getSize().x, j * mTileTexture.getSize().y);
                mTiles.setTextureRect(sf::IntRect(map[i][j].x * mTileTexture.getSize().x, map[i][j].y * mTileTexture.getSize().y, mTileTexture.getSize().x, mTileTexture.getSize().y));
                window.draw(mTiles);
            }
        }
    }
}

