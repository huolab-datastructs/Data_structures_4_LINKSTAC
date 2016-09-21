//			Alex Schrepfer
//		Modified March 8th, 2001
#include "STACK.H"
class Extended_stack: public Stack {
public:
	
	void Extended_stack::clear();
	bool Extended_stack::full() const;
	int Extended_stack::size() const;
	Error_code Extended_stack::pop_and_top(Stack_entry &item);

};