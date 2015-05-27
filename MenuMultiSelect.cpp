//
// Created by florek on 5/10/2015.
//

#include "MenuMultiSelect.h"
#include <algorithm>
#include <iostream>

void MenuMultiSelect::select() {
	this->expanded = !this->expanded;
}

void MenuMultiSelect::accept(FVisitor &visitor, bool skip_hidden) {
	std::cout << "wat"<<std::endl;
	visitor.visit(this);
	if(this->expanded or !skip_hidden) {
		std::unique_ptr<FVisitor> sv = visitor.subVisitor();
		for (auto &e : this->subMenu) {
			e->accept(*sv.get(), skip_hidden);
		}
	}
}

void MenuMultiSelect::insert(uint pos, MenuElement* e) {
	std::cout<<"fwat" << std::to_string(pos) <<&e <<std::endl;
	this->subMenu.insert(this->subMenu.begin()+pos+1,
			std::move(std::unique_ptr<MenuElement>(e)));
}

void MenuMultiSelect::remove(MenuElement* el) {
	//erase-remove idiom
	this->subMenu.erase(
			std::remove_if(this->subMenu.begin(), this->subMenu.end(), 
				[el](std::unique_ptr<MenuElement>& rhs) {
					return rhs.get() == el;
				}),
			this->subMenu.end()
	);
}
void MenuMultiSelect::remove(uint pos) {
	this->subMenu.erase(this->subMenu.begin()+pos);
}

void MenuMultiSelect::push_back(MenuElement& e) {
	this->subMenu.push_back(std::unique_ptr<MenuElement>(&e));
}
