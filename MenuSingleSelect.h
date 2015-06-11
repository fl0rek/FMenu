//
// Created by florek on 5/10/2015.
//

#ifndef FMENU_MENUSINGLESELECT_H
#define FMENU_MENUSINGLESELECT_H


#include <bits/unique_ptr.h>
#include "MenuElement.h"

class MenuSingleSelect : public MenuElement {

public:
	virtual void select() override;

	virtual void accept(FVisitor &visitor, bool) override;

	virtual void bindAction(std::function<void()> function);

	MenuSingleSelect(std::string name);

private:
	//std::unique_ptr<std::function<void()>> action;
	std::function<void()> action;
};


#endif //FMENU_MENUSINGLESELECT_H
