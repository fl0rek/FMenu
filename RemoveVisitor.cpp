//
// Created by florek on 6/10/2015.
//

#include "RemoveVisitor.h"
#include "MenuMultiSelect.h"

void RemoveVisitor::performActionOnElementAt(uint offset) {
	(static_cast<MenuMultiSelect*>(this->currently_visited))->remove(offset-1);
}

std::unique_ptr<FVisitor> RemoveVisitor::subVisitor() {
	return std::unique_ptr<InsertVisitor>(new RemoveVisitor(this->pos, this));
}
