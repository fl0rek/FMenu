#include "InsertVisitor.h"
#include "MenuMultiSelect.h"

#include <iostream>

std::unique_ptr<FVisitor> InsertVisitor::subVisitor() {
	return std::unique_ptr<InsertVisitor>(new InsertVisitor(this->el, this->pos, this));
}

void InsertVisitor::visit(MenuElement* el) {
	if(!*this->pos)
		return;
	this->currently_visited = el;
	if(!--*this->pos) {
		this->parent->performActionOnElementAt(offset);
	}
	//offset++;
}

void InsertVisitor::performActionOnElementAt(uint offset) {
	(static_cast<MenuMultiSelect*>(this->currently_visited))->insert(offset-1, this->el);
}

