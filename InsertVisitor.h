#include "FVisitor.h"
#include "MenuElement.h"
#include <memory>

class InsertVisitor : public FVisitor {
public:
	InsertVisitor(MenuElement* el, uint pos) :
		el(el), pos(std::make_shared<uint>(pos)) {
			this->parent = this;
		}
	void visit(MenuElement*) override;
	virtual std::unique_ptr<FVisitor> subVisitor() override;
private:
	InsertVisitor(MenuElement* el, std::shared_ptr<uint> pos, InsertVisitor* parent) 
		: parent(parent), pos(pos), offset(*pos), el(el) { }
	void insertElementAt(uint offset);

	MenuElement *currently_visited;
	InsertVisitor* parent;
	std::shared_ptr<uint> pos;
	MenuElement *el;
	uint offset;
};
