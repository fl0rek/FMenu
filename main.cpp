#include <iostream>
#include "FMenuFacade.h"

using namespace std;

int main() {
	FMenuFacade menu("main");
	uint i = 0;
	for(auto n : *menu.getMenuNames())
		cout << i++ << ":" << n;
	menu.addElement(1, FMenuFacade::MultiMenuElement("test1"));
	//menu.addElement(1, FMenuFacade::MultiMenuElement("test1"));
	std::cout << "done" << std::endl;
	i = 0;
	for(auto n : *menu.getMenuNames())
		cout << i++ << ":" << n;
	return 0;
}
