#ifndef CL_APP_H
#define CL_APP_H
#include "cl_base.h"
#include <iostream>
class cl_app : public cl_base //1 класс
{
public:
	cl_app() : cl_base("") {};
	void derevo(); //postr
	void print() { print_hierarchy(0); }; //zapuck
	void pechat() { 
		std::cout << "The tree of objects and their readiness\n";
		print_sost(0); 
	};
};
#endif
