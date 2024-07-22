#include <iostream>
template<typename T, bool = std::is_arithmetic<T>::value>
class Utils;
template <typename T>
class Utils<T, true>{
	public:
		static T assertNumberIsGreaterThanZero (T n){
			T number = n;
			if( 0 > number ) number *= -1;
			else if ( 0 == number ) number = 1;
			return number;
		}

};
