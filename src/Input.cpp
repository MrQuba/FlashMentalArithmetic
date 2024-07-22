#include "Input.hpp"

std::string Input::get(std::string textToShow){

	std::string input;
	std::cout << textToShow;
	std::cin >> input;
	return input;
}
