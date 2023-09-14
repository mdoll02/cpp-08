#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main () {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it; }
	std::stack<int> s(mstack);
	std::cout << "Top of s: " << s.top() << std::endl;
	std::cout << "Top of mstack: " << mstack.top() << std::endl;
	s.push(1337);
	std::cout << "Top of s: " << s.top() << std::endl;
	std::cout << "Top of mstack: " << mstack.top() << std::endl;

	MutantStack<std::string> sstack;

	sstack.push("World");
	sstack.push("Hello");
	sstack.push("2");
	sstack.push("1");
	sstack.push("Test");
	std::stack<std::string> copy_stack(sstack);
	std::cout << "Top of sstack: " << sstack.top() << "\nTop of copy_stack: " << copy_stack.top() << std::endl;
	sstack.pop();
	sstack.pop();
	sstack.pop();
	std::cout << "Top of sstack: " << sstack.top() << "\nTop of copy_stack: " << copy_stack.top() << std::endl;
	MutantStack<std::string>::iterator it2 = sstack.begin();
	MutantStack<std::string>::iterator ite2 = sstack.end();
	++it2;
	--it2;
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2; }
	return 0;
}