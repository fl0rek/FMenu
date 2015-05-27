#include "MenuElement.h"
#include "MenuMultiSelect.h"
#include "MenuNameVisitor.h"

#include <memory>
#include <string>

class FMenuFacade {
public:
	typedef MenuNameVisitor::name_list name_list;

	FMenuFacade(std::string name);
	void addElement(uint pos, MenuElement *el);
	void removeElement(uint pos);
	std::shared_ptr<name_list> getMenuNames();
	void selectElement(uint pos);

	static MenuElement* MultiMenuElement(std::string name);
	static MenuElement* SingleMenuElement(std::string name);
private:
	std::unique_ptr<MenuMultiSelect> root;
};
