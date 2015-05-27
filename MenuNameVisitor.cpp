//
// Created by florek on 5/10/2015.
//

#include <sstream>
#include "MenuNameVisitor.h"

void MenuNameVisitor::visit(MenuElement *element) {
	this->names->emplace_back(this->level, element->getName());
}

std::unique_ptr<FVisitor> MenuNameVisitor::subVisitor() {
	return std::unique_ptr<MenuNameVisitor>(new MenuNameVisitor(this->names, this->level+1));
}

MenuNameVisitor::MenuNameVisitor(std::shared_ptr<MenuNameVisitor::name_list> parent_names, uint level) :
	names(parent_names), level(level) {
}

std::shared_ptr<MenuNameVisitor::name_list> MenuNameVisitor::getNames() {
	return names;
}

MenuNameVisitor::MenuNameVisitor() {
	this->names = std::make_shared<name_list>();
}

