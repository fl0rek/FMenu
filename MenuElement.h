//
// Created by florek on 5/10/2015.
//

#ifndef FMENU_MENUELEMENT_H
#define FMENU_MENUELEMENT_H


#include <string>
#include <functional>
#include "FVisitor.h"

class FVisitor;

class MenuElement {
public:
	virtual std::string getName() const;
	virtual void select() = 0;
	virtual void accept(FVisitor &, bool skip_hidden = true) = 0;

	MenuElement(std::string name) :
			name(name) {}
	virtual void remove() = 0;

protected:
	MenuElement* parent = nullptr;

private:
	std::string name;
};


#endif //FMENU_MENUELEMENT_H
