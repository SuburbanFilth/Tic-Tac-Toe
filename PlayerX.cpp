#include <SFML/Graphics.hpp>
#include "PlayerX.hpp"
#include <iostream>
#include <typeinfo>

PlayerX::PlayerX(std::string filename){
    if (!m_texture.loadFromFile(filename)) {
        std::cout << "Error when loading the texture";
    }
    for (int i = 0; i < 3;i++) {
        for (int j=0 ; j < 3 ; j++) {
            sf::Sprite sprite;
            sprite.setTexture(m_texture);
            sprite.setPosition(sf::Vector2f((i % 3)*275, (j % 3)*275));
            m_spriteStruct[i][j] = std::make_pair(sprite,false);
        }
    }

}

PlayerX::~PlayerX() {

}

void PlayerX::Render(sf::RenderWindow& l_window){
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            if (m_spriteStruct[i][j].second) {
                l_window.draw(m_spriteStruct[i][j].first);
            }
        }
    }
}

bool PlayerX::Update(sf::Vector2i l_position, PlayerX& otherPlayer) {
    int column;
    int row;
    column = (int) l_position.x/250;
    row = (int) l_position.y/250;
    if (!m_spriteStruct[column][row].second and otherPlayer.CanIDraw(column,row)) {
        m_spriteStruct[column][row].second = true;
        return true;
    }
    return false;
}

bool PlayerX::CanIDraw(int row, int col) {
    return !m_spriteStruct[row][col].second;
}