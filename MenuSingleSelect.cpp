//
// Created by florek on 5/10/2015.
//

#include "MenuSingleSelect.h"

void MenuSingleSelect::select() {
	this->action();
}

void MenuSingleSelect::accept(FVisitor &visitor, bool) {
	visitor.visit(this);
}

void MenuSingleSelect::bindAction(std::function<void()> function) {
	this->action = function;
}

MenuSingleSelect::MenuSingleSelect(std::string name) : MenuElement(name) {

}
