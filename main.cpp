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
	for(FMenuFacade::name n : *menu.getMenuNames())
		cout << i++ << ":" << n << std::endl;

	std::cout << "fuck off m8 done" << std::endl;
	cin >> i;
	return 0;
}
