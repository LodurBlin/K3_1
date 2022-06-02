#ifndef CL_APP_H
#define CL_APP_H
#include "cl_base.h"
#include <iostream>
class cl_app : public cl_base //1 класс
{
public:
	cl_app() : cl_base("") {};
	void derevo(); //postr
	void print() {  //zapuck
		std::cout << "Object tree";
		print_hierarchy(0);
		std::cout << "\nThe tree of objects and their readiness";
		print_sost(0);
	};
};
#endif
