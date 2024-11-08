#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Button {
public:
    Button(const std::string& text, float x, float y) {
        button.setSize(sf::Vector2f(200, 50));
        button.setPosition(x, y);
        button.setFillColor(sf::Color::Blue);

        font.loadFromFile("Arial.ttf"); // Tải font
        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(20);
        label.setFillColor(sf::Color::White);
        label.setPosition(x + 10, y + 10);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(label);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

private:
    sf::RectangleShape button;
    sf::Text label;
    sf::Font font;
};
#pragma once
