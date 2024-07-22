#include <SFML/Graphics.hpp>
#pragma once

class WindowUtils{
	public:
		WindowUtils() :window(sf::VideoMode::getDesktopMode(), "Flash Mental Arithmetic", sf::Style::Default) {}
		 void drawText(sf::Text text){
			window.clear();
			window.draw(text);
			window.display();
		}
		sf::RenderWindow window;	
	



};
