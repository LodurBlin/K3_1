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

cl_base* cl_base::kto_otez() {
	return p_predok;
}
std::unique_ptr<cl_base> cl_base::uproot(){
  assert(p_predok);
  auto& ch = p_predok->children;
  std::unique_ptr<cl_base> a = nullptr;
  for (auto& spin : ch){
    if( this==spin.get()){
      std::swap(a, spin);
    }
  }
  
  ch.erase(std::remove(ch.begin(), ch.end(),  0), ch.end());
  return a;
}


void cl_base::move_to(cl_base* destination) {
  destination->add_spinogriz(uproot());
}


