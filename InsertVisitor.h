#pragma once

#include "FVisitor.h"
#include "MenuElement.h"
#include <memory>
#include <iostream>

class InsertVisitor : public FVisitor {
public:
	InsertVisitor(MenuElement* el, uint pos) :
			el(el), pos(std::make_shared<uint>(pos)) {
		this->parent = this;
		this->offset = pos;
	}
	void visit(MenuElement*) override;
	virtual std::unique_ptr<FVisitor> subVisitor() override;

protected:
	InsertVisitor(MenuElement* el, std::shared_ptr<uint> pos, InsertVisitor* parent) 
		: parent(parent), pos(pos), offset(*pos), el(el) { }

	MenuElement *currently_visited;
	InsertVisitor* parent;
	std::shared_ptr<uint> pos;
	MenuElement *el;
	uint offset;

private:
	virtual void performActionOnElementAt(uint offset);
};
