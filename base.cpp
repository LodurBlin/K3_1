#include "cl_base.h"
#include "node.h"
#include <iostream>

void cl_base::add_spinogriz(std::unique_ptr <cl_base>&& spinogriz) {

	spinogriz->p_predok = this;
	spinogrizi.push_back(std::move(spinogriz));

}

void cl_base::print_hierarchy() const {
	if (spinogrizi.size() == 0) {
		return;
	}
	std::cout << "\n" << this->ob_name;
	for (const auto& spin : spinogrizi) {
		std::cout << " " << (spin)->get_name();
		}
	(spinogrizi.back())->print_hierarchy();

}

void cl_base::detdom(cl_base* new_predok) { //дети старого дерево, удалить нулевые указатели
	if (new_predok) {
		this->p_predok = new_predok;
		for (auto& spin : p_predok->spinogrizi) {
			if (spin.get() == this) {
				new_predok->add_spinogriz(std::move(spin));
			}
		}
	}
	else this->p_predok = 0;
}
cl_base* cl_base::kto_otez() {
	return p_predok;
}
//????????????????????????????????//
cl_base* cl_base::search(std::string wanted) {
	if ((this)->get_name()==wanted){
		return this;
	}
	for (const auto& spin : spinogrizi) {
		spin -> search(wanted);
	}
	return nullptr;
}
