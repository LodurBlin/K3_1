#include "cl_app.h"
#include "node.h"
#include <iostream>
using namespace std;

void cl_app::derevo() {
	string root_name;
	cin >> root_name;
	set_name(root_name);
	cl_base* cur_predok = this;
	do {
		string predok, spinogriz;
		cin >> predok;
		cin >> spinogriz;
		if (predok == "endtree") {
			break;//prinimaem sost
		}
		if (predok != cur_predok->get_name()) {
			cur_predok = (cur_predok)->spinogrizi.back().get();
		}
		(cur_predok)->add_spinogriz(std::unique_ptr<cl_base>(new node(spinogriz)));
	} while (true);
	cout << root_name;
}
