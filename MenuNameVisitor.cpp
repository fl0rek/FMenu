//
// Created by florek on 5/10/2015.
//

#include "MenuNameVisitor.h"

void MenuNameVisitor::visit(MenuElement *element) {
	this->names->emplace_back(this->level, element->getName());
	/*
	std::string name = element->getName();
	uint level = this->level;
	auto foo = std::make_pair(level, name);

	this->names->push_back(foo);
	 */
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

std::ostream &operator<<(std::ostream &os, const MenuNameVisitor::name &name) {
	return os << std::string(name.first, '\t') << name.second << std::string("\n");
}
