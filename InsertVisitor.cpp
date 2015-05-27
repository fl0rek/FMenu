#include "InsertVisitor.h"
#include "MenuMultiSelect.h"

#include <iostream>

std::unique_ptr<FVisitor> InsertVisitor::subVisitor() {
	return std::unique_ptr<InsertVisitor>(new InsertVisitor(this->el, this->pos, this));
}

void InsertVisitor::visit(MenuElement* el) {
	std::cout<<"u wot m8" << std::to_string(this->pos)<<std::endl;
	if(!*this->pos)
		return;
	this->currently_visited = el;
	if(!--*this->pos) {
		this->parent->insertElementAt(offset);
	}
	//offset++;
}

void InsertVisitor::insertElementAt(uint offset) {
	(static_cast<MenuMultiSelect*>(this->currently_visited))->insert(this->offset, this->el);
}

