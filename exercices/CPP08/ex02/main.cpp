#include "MutantStack.hpp"

int main() {
	std::cout << "===== Subject test =====" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "stack: " << mstack << std::endl << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	std::cout << "stack: " << mstack << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	std::cout << "============= new  MutantStack =============" << std::endl;
	std::cout << mstack << std::endl << std::endl;

	std::cout << "============== Iterating test ==============" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "========== Reverse iteration test ==========" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "=========== Const iteration test ===========" << std::endl;
	const MutantStack<int> constMstack = mstack;
	for (MutantStack<int>::const_iterator it = constMstack.begin(); it != constMstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "======= Const reverse iteration test =======" << std::endl;
	for (MutantStack<int>::const_reverse_iterator it = constMstack.rbegin(); it != constMstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "========== Copy & assignment test ==========" << std::endl;
	MutantStack<int>	copyStack(mstack);
	MutantStack<int>	assignStack;

	assignStack = mstack;
	std::cout << "CopyStack size: " << copyStack.size() << std::endl;
	std::cout << copyStack << std::endl << std::endl;

	std::cout << "AssignStack size: " << assignStack.size() << std::endl;
	std::cout << assignStack << std::endl << std::endl;

	std::cout << "========== std::string  type test ==========" << std::endl << std::endl;
	MutantStack<std::string>	sstack;

	sstack.push("This");
	sstack.push("is");
	sstack.push("42");
	for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	MutantStack<std::string>	copyStringStack(sstack);
	MutantStack<std::string>	assignStringStack;

	assignStringStack = sstack;
	std::cout << "CopyStack size: " << copyStringStack.size() << std::endl;
	std::cout << copyStringStack << std::endl << std::endl;

	std::cout << "AssignStack size: " << assignStringStack.size() << std::endl;
	std::cout << assignStringStack << std::endl << std::endl;
}

// #include <list>

// int main()
// {
// 	std::list<int> mstack;   // std::list instead of MutantStack

// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl; // 17

// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl; // 1

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }