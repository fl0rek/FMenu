//
// Created by florek on 6/10/2015.
//

#ifndef FMENU_REMOVEVISITOR_H
#define FMENU_REMOVEVISITOR_H


#include "InsertVisitor.h"

class RemoveVisitor : public InsertVisitor {

public:
	RemoveVisitor(uint pos) : InsertVisitor(nullptr, pos) { }
private:
	RemoveVisitor(std::shared_ptr<uint> pos, InsertVisitor* parent)
	: InsertVisitor(nullptr, pos, parent) { }
	//: parent(parent), pos(pos), offset(*pos), el(el) { }


	virtual void performActionOnElementAt(uint offset) override;

	virtual std::unique_ptr<FVisitor> subVisitor() override;
};


#endif //FMENU_REMOVEVISITOR_H
