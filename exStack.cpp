#include   "../../C/UTILITY.H"
#include	"EXSTACK.H"
//			Alex Schrepfer
//		Modified March 8th, 2001

void Extended_stack::clear() {

	//Post: deletes all items in the stack, nothing returned

	while (top_node != NULL) {

		Node *temp_node = top_node;
		top_node = top_node->next;
		delete temp_node;

	}

}

bool Extended_stack::full() const {

	//Post: returns true/false if the stack is full, stack not changed

	Node *test_node = new Node();
	if (test_node == NULL) return true;
	delete test_node;
	return false;

}

int Extended_stack::size() const {

	//Post: returns the number of items in the stack, stack not changed

	Node *new_copy = top_node;
	int count = 0;
	
	while (new_copy != NULL) {
		count++;
		new_copy = new_copy->next;
	}

	return count;
	
}

Error_code Extended_stack::pop_and_top(Stack_entry &item) {

/*   
Post: The top of the Stack is removed.  If the Stack 
is empty the method returns underflow; otherwise it continues to top

Post: The top of the Stack is reported in item. If the Stack 
is empty the method returns underflow; otherwise it returns success.
 */

	//pop
	Node *old_top = top_node;
	if (top_node == NULL) return underflow;
	top_node = old_top->next;
	delete old_top;

	//top
	if (top_node == NULL) return underflow;
	item = top_node->entry;
	return success;

}