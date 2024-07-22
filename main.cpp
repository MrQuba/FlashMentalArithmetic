#include <iostream> 
#include <string>
#include <random>
#include <SFML/Graphics.hpp>
#include "src/Input.hpp"
#include "src/NumberContainer.hpp"
#include "src/Utils.hpp"
#include "src/Event.hpp"
#include "src/WindowUtils.hpp"
int main(){
	// initializing variables while making sure that they are greater than zero	
	const int amountOfNumbersToShow = Utils<int>::assertNumberIsGreaterThanZero(
			stoi(
				Input::get("How many numbers you want to be shown? ")
			)
		);
	const sf::Time secondsToDisplayEachNumber = sf::seconds(
				Utils<float>::assertNumberIsGreaterThanZero(
					stof(
						Input::get("How long you want number to be shown? (in seconds): ")
					)
				)
			); 
	const int minNumber = stoi(Input::get("What is smallest number you want to see? "));
	const int maxNumber = stoi(Input::get("What is biggest number you want to see? "));
	
	NumberContainer* numbers = new NumberContainer();
	// generating random numbers in user specified range and making sure that there won't be same number twice in the row
	// as it would be hard to see difference in display
	// it is not perfect solution though, especially when same number repeats at last elements
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(minNumber, maxNumber);
	for(int i = amountOfNumbersToShow; i > 0; i--) numbers->add(distr(gen));
	numbers->arrange();
	numbers->display();
	sf::Font font;
	sf::Clock clock;
	if(!font.loadFromFile("FreeSansBold.otf")) {  
		std::cout << "Error loading font!" << std::endl;
		return -1;
	}
	sf::Text number;
	number.setFont(font);
	number.setCharacterSize(75);
	number.setFillColor(sf::Color::White);
	number.setOutlineColor(sf::Color::Red);
	number.setString("Press [SPACE] to begin...");
	bool isSpacePressed = false;
	bool hasFirstNumberBeenInitialized = false;
	WindowUtils windowUtils;
	while(windowUtils.window.isOpen()){
		Event::eventLoop(windowUtils.window);
		// waiting for user to start
		if(!isSpacePressed){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) isSpacePressed = true;
			windowUtils.drawText(number);
			continue;
		}
		if(!hasFirstNumberBeenInitialized){
			numbers->numIterator = numbers->nums.begin();
			number.setString(numbers->numToString());
			numbers->numIterator++;
			clock.restart();
			hasFirstNumberBeenInitialized = true;
		}

		if(clock.getElapsedTime().asSeconds() >= secondsToDisplayEachNumber.asSeconds()) {
		  number.setString(numbers->numToString());
		  numbers->numIterator++;
		  if(numbers->numIterator > numbers->nums.end()) windowUtils.window.close();
		  clock.restart();
		}

		windowUtils.drawText(number);
}

	int userAnswer = stoi(Input::get("Input your answer: "));

	if(userAnswer == numbers->sum) std::cout << "Congratulations! Your answer is correct" << std::endl;
	else std::cout << "Wrong answer! Corret answer is: " << numbers->sum << std::endl;


	delete numbers;
	return 0;
}
