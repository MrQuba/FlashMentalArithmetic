#include <SFML/Graphics.hpp>

class Event {
	public:
		static void eventLoop(sf::RenderWindow& window){
			sf::Event event;
			while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed) window.close();
				else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
			}

		}

};
