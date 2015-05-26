//
// Created by florek on 5/10/2015.
//

#ifndef FMENU_FVISITOR_H
#define FMENU_FVISITOR_H


#include "MenuElement.h"
#include <memory>

class MenuElement;

class FVisitor {
public:
	virtual void visit(MenuElement *) = 0;
	virtual std::unique_ptr<FVisitor> subVisitor() = 0;
};


#endif //FMENU_FVISITOR_H
