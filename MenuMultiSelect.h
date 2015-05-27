//
// Created by florek on 5/10/2015.
//

#ifndef FMENU_MENUMULTISELECT_H
#define FMENU_MENUMULTISELECT_H

#include <vector>
#include "MenuElement.h"


class MenuMultiSelect : public MenuElement {

public:
	void insert(uint pos, MenuElement* e);
	void push_back(MenuElement& e);

	void remove(MenuElement* el);
	void remove(uint pos);

	void accept(FVisitor &visitor, bool skip_hidden = true) override;

	void select() override;

	MenuMultiSelect(const std::string &name) : MenuElement(name) { }

private:
	bool expanded = false;
	std::vector<std::unique_ptr<MenuElement>> subMenu;
};


#endif //FMENU_MENUMULTISELECT_H
