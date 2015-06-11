//
// Created by florek on 6/10/2015.
//

#include "SelectElementVisitor.h"

void SelectElementVisitor::visit(MenuElement *element) {
	if(!*this->pos)
		return;
	if(!--*this->pos) {
		element->select();
	}

}

std::unique_ptr<FVisitor> SelectElementVisitor::subVisitor() {
	return std::unique_ptr<SelectElementVisitor>(new SelectElementVisitor(this->pos));
}
