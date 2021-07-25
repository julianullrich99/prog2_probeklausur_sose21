#include <iostream>
#include "cvektor.h"

int main() {

	CVektor vec = CVektor(10, 2);

	float val = vec[2];
	std::cout << "initial: " << val << std::endl;
	vec.display();

	vec[2] = 3;
	std::cout << "after change: " << vec[2] << std::endl;
	vec.display();


	CVektor vec2 = CVektor(vec);
	std::cout << "after copy: " << vec2[2] << std::endl;
	vec2.display();

	CVektor vec3 = CVektor(10,3);
	std::cout << "after create new: " << vec3[2] << std::endl;
	vec3.display();
	vec3 = vec2 + vec2 + vec2;

	std::cout << "after copy2: " << vec3[2] << std::endl;
	vec3.display();

	CVektor vec4 = vec + vec2;
	std::cout << "after concat:" << std::endl;
	vec4.display();

	vec4 += vec;
	std::cout << "after inline concat:" << std::endl;
	vec4.display();

	
	return 0;
}