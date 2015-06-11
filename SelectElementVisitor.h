//
// Created by florek on 6/10/2015.
//

#ifndef FMENU_SELECTELEMENTVISITOR_H
#define FMENU_SELECTELEMENTVISITOR_H


#include "FVisitor.h"

class SelectElementVisitor : public FVisitor {
public:
	SelectElementVisitor(uint pos) : pos(std::make_shared<uint>(pos)) {};

	virtual void visit(MenuElement *element);

	virtual std::unique_ptr<FVisitor> subVisitor();
private:
	SelectElementVisitor(std::shared_ptr<uint> pos) : pos(pos) {};
	std::shared_ptr<uint> pos;
};


#endif //FMENU_SELECTELEMENTVISITOR_H
