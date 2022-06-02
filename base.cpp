#include "cl_base.h"
#include <iostream>
#include <cassert>
#include <algorithm>

void cl_base::add_spinogriz(std::unique_ptr <cl_base>&& spinogriz) {

	spinogriz->p_predok = this;
	spinogrizi.push_back(std::move(spinogriz));

}

void cl_base::print_hierarchy(int offset) {
	std::cout << "\n" << std::string(offset * 4, ' ') << this->ob_name;
	if (spinogrizi.size() == 0) {
		return;
	}
	for (const auto& spin : spinogrizi) {
		(spin)->print_hierarchy(++offset);
		--offset;
	}
}

void cl_base::print_sost(int offset) {
	std::cout << "\n" << std::string(offset * 4, ' ') << this->ob_name << this->readiness;
	if (spinogrizi.size() == 0) {
		return;
	}
	for (const auto& spin : spinogrizi) {
		(spin)->print_sost(++offset);
		--offset;
	}
}


cl_base* cl_base::kto_otez() {
	return p_predok;
}
std::unique_ptr<cl_base> cl_base::uproot() {
	assert(p_predok);
	auto& ch = p_predok->spinogrizi;
	std::unique_ptr<cl_base> a = nullptr;
	for (auto& spin : ch) {
		if (this == spin.get()) {
			std::swap(a, spin);
		}
	}
	ch.erase(std::remove(ch.begin(), ch.end(), nullptr), ch.end());
	return a;
}

void cl_base::move_to(cl_base* destination) {
	destination->add_spinogriz(uproot());
}

cl_base* cl_base::search(std::string wanted) {
	if (this->get_name() == wanted) {
		return this;
	}
	for (const auto& spin : spinogrizi) {
		auto res = spin->search(wanted);
		if (res) return res;
	}
	return nullptr;
}



void cl_base::set(int n) {
if ((p_predok==nullptr) or (p_predok->sost != 0)) {
		sost = n;
		if (n != 0) {
			readiness = " is ready";
		} else {
			off();
		}
	}
}

void cl_base::preparing() {
	int s;
	std::string name;
	while(std::cin>>name>>s) {
		this->search(name)->set(s);
	} 
}

void cl_base::off(){
	readiness = " is not ready";
	sost=0;
	for (const auto& spin : spinogrizi){
		spin->off();
	}
}
