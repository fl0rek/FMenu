//
// Created by florek on 5/10/2015.
//

#ifndef FMENU_MENUNAMEVISITOR_H
#define FMENU_MENUNAMEVISITOR_H


#include <vector>
#include <memory>
#include "FVisitor.h"

class MenuNameVisitor : public FVisitor {
public:
	typedef  std::vector<std::pair<uint, std::string>> name_list;
	typedef std::pair<uint, std::string> name;

	virtual void visit(MenuElement *element) override;

	virtual std::unique_ptr<FVisitor> subVisitor() override;

	std::shared_ptr<name_list> getNames();

	MenuNameVisitor();
private:
	MenuNameVisitor(std::shared_ptr<name_list> parent_names, uint level);
	std::shared_ptr<name_list> names;
	uint level = 0;
};

std::ostream& operator<<(std::ostream& out, const MenuNameVisitor::name&);

#endif //FMENU_MENUNAMEVISITOR_H
