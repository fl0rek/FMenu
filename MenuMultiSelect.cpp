//
// Created by florek on 5/10/2015.
//

#include "MenuMultiSelect.h"
#include <algorithm>

void MenuMultiSelect::select() {
	this->expanded = !this->expanded;
}

void MenuMultiSelect::accept(FVisitor &visitor, bool skip_hidden) {
	visitor.visit(this);
	if(this->expanded or !skip_hidden) {
		std::unique_ptr<FVisitor> sv = visitor.subVisitor();
		for (auto &e : this->subMenu) {
			e->accept(*sv.get(), skip_hidden);
		}
	}
}

void MenuMultiSelect::insert(uint pos, MenuElement& e) {
	this->subMenu.insert(this->subMenu.begin()+pos,
						 std::unique_ptr<MenuElement>(&e));
}

void MenuMultiSelect::remove() {
	if(this->parent)
		static_cast<MenuMultiSelect*>(this->parent)->remove(this);
}

void MenuMultiSelect::remove(MenuElement* el) {
	this->subMenu.erase(
			std::remove(this->subMenu.begin(), this->subMenu.end(), *el),
			this->subMenu.end()
	);
}
void MenuMultiSelect::remove(uint pos) {
	this->subMenu.erase(this->subMenu.begin()+pos);
}

void MenuMultiSelect::push_back(MenuElement& e) {
	this->subMenu.push_back(std::unique_ptr<MenuElement>(&e));
}
