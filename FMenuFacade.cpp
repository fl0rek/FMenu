#include "FMenuFacade.h"
#include "MenuMultiSelect.h"
#include "MenuSingleSelect.h"
#include "MenuNameVisitor.h"
#include "InsertVisitor.h"

MenuElement* FMenuFacade::MultiMenuElement(std::string name) {
	return new MenuMultiSelect(name);
}

MenuElement* FMenuFacade::SingleMenuElement(std::string name) {
	return new MenuSingleSelect(name);
}

void FMenuFacade::addElement(uint pos, MenuElement *el) {
	InsertVisitor v(el, pos);
	this->root->accept(v);
}

void FMenuFacade::removeElement(uint pos) {
}

std::shared_ptr<FMenuFacade::name_list> FMenuFacade::getMenuNames() {
	MenuNameVisitor v;
	v.visit(this->root.get());
	return v.getNames();
}

void FMenuFacade::selectElement(uint pos) {
}

FMenuFacade::FMenuFacade(std::string name) {
	this->root = std::make_unique<MenuMultiSelect>(name);
}
