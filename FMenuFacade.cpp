#include <sstream>
#include "FMenuFacade.h"
#include "MenuMultiSelect.h"
#include "MenuSingleSelect.h"
#include "MenuNameVisitor.h"
#include "InsertVisitor.h"
#include "RemoveVisitor.h"
#include "SelectElementVisitor.h"

MenuElement* FMenuFacade::MultiMenuElement(std::string name) {
	auto multi = new MenuMultiSelect(name);
	auto single = new MenuSingleSelect("-");
	InsertVisitor v(single, 1);
	multi->accept(v);
	return multi;
}

MenuElement* FMenuFacade::SingleMenuElement(std::string name, std::function<void()> function) {
	auto single = new MenuSingleSelect(name);
	single->bindAction(function);
	return single;
}

void FMenuFacade::addElement(uint pos, MenuElement *el) {
	InsertVisitor v(el, pos);
	this->root->accept(v);
}

void FMenuFacade::removeElement(uint pos) {
	RemoveVisitor v(pos);
	this->root->accept(v);
}

std::shared_ptr<FMenuFacade::name_list> FMenuFacade::getMenuNames() {
	MenuNameVisitor v;
	this->root->accept(v);
	return v.getNames();
}

void FMenuFacade::selectElement(uint pos) {
	SelectElementVisitor v(pos);
	this->root->accept(v);
}

FMenuFacade::FMenuFacade(std::string name) {
	this->root = std::make_unique<MenuMultiSelect>(name);
}

std::ostream &operator<<(std::ostream &os, const FMenuFacade::name &name) {
	std::stringstream ss;
	ss << std::string(name.first, ' ') << "-" << name.second << "\n";
	return os << ss.str();
}
