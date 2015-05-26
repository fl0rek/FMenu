#include <iostream>
#include "MenuMultiSelect.h"
#include "MenuNameVisitor.h"
#include "MenuSingleSelect.h"

using namespace std;

int main() {
	MenuMultiSelect m("main");
	MenuNameVisitor v;
	m.push_back(*new MenuSingleSelect("test1"));

	cout << "Hello, World!" << std::endl;
	m.accept(v, false);
	uint i = 0;
	for(auto n : *v.getNames())
		cout << i++ << ":" << n;
	std::string a;
	cin >> a;
	return 0;
}