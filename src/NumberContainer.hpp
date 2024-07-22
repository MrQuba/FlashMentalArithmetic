#include <vector>
#include <iostream>
#include <string>
class NumberContainer{
	typedef std::vector<int> vector;
	public:
		void add(int num){
			sum += num;
	 		nums.push_back(num);
		}
		~NumberContainer(){}
		int sum = 0;
		void display(){
			std::cout << "{ ";
			for(auto& n : nums) std::cout << " " << n << " ";
			std::cout << " }" << std::endl;
		}
		void arrange(){
			for(vector::iterator it = nums.begin(); it <= nums.end() - 1; it+= 2){
				if(*it == *(it + 1)) {
					int copy;
					for(vector::iterator it2 = it; it2 <= nums.end() - 1; it2 += 2){
						if(*(it + 1) != *it2 && *(it + 1) != *(it2 + 1)){
							copy = *it2;
							*it2 = *(it + 1);
							*(it + 1) = copy;
							break;
						}
					}
				}
			}
		}
		std::string numToString(){
			auto n = *numIterator;
			std::string num = std::to_string(n);
			return num;
		}
		vector nums;
		typename vector::iterator numIterator = nums.begin();

};

