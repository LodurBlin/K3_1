#include "cl_app.h"
#include "nodes.h"
#include "cl_base.cpp"
#include <iostream>
using namespace std;

void cl_app::derevo() {
	string root_name;
	cin >> root_name;
	set_name(root_name);
	cl_base* cur_predok = this;
	cl_base* root = this;
	do {
		string predok, spinogriz;
		int clas;
		cin >> predok;
		if (predok == "endtree") {
			root->preparing();
			break;//prinimaem sost
		}
		cin >> spinogriz >> clas;
		if (predok != cur_predok->get_name()) {
			cur_predok = (root)->search(predok);
		}
		switch (clas) { //создаем объект нужного класса и запихиваем в дерево
		case 2:
			(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _2(spinogriz)));
				break;
		case 3:
			(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _3(spinogriz)));
				break;
		case 4:
			(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _4(spinogriz)));
				break;
		case 5:
			(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _5(spinogriz)));
				break;
		case 6:
			(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new _6(spinogriz)));
				break;
		default:
			cout << "фсё";
				break;
		}
	} while (true);
	cout << root_name;
};

