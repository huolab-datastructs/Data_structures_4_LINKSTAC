#include   "../../C/UTILITY.H"
#include   "STACK.H"
//			Alex Schrepfer
//		Modified March 8th, 2001

bool Stack::empty() const
/*
Post: Return true if the Stack is empty,
otherwise return false.
 */
{
   return top_node == NULL;
}

Stack::Stack()
/*
Post: The Stack is initialized to be empty.
 */
{
   top_node = NULL;
}

Error_code Stack::push(const Stack_entry &item)
/*
Post: Stack_entry item is added to the top of
the Stack; returns success or returns a code
of overflow if dynamic memory is exhausted.
 */

{
   Node *new_top = new Node(item, top_node);
   if (new_top == NULL) return overflow;
   top_node = new_top;
   return success;
}

Error_code Stack::top(Stack_entry &item) const
/*
Post: The top of the Stack is reported in item. If the Stack
is empty the method returns underflow; otherwise it returns success.
 */

{
   if (top_node == NULL) return underflow;
   item = top_node->entry;
   return success;
}

Error_code Stack::pop()
/*
Post: The top of the Stack is removed.  If the Stack
is empty the method returns underflow; otherwise it returns success.
 */

{
   Node *old_top = top_node;
   if (top_node == NULL) return underflow;
   top_node = old_top->next;
   delete old_top;
   return success;
}


Stack::Stack(const Stack &original) //  copy constructor
/*
Post: The Stack is initialized as a copy of Stack original.
 */
{
   Node *new_copy, *original_node = original.top_node;
   if (original_node == NULL) top_node = NULL;
   else {								 //  Duplicate the linked nodes.
		top_node = new_copy = new Node(original_node->entry);
		while (original_node->next != NULL) {
		   original_node = original_node->next;
		   new_copy->next = new Node(original_node->entry);
		   new_copy = new_copy->next;
		}
   }
}

void Stack::operator = (const Stack &original) //  Overload assignment
/*
Post: The Stack is reset as a copy of Stack original.
 */
{
   Node *new_top, *new_copy, *original_node = original.top_node;
   if (original_node == NULL) new_top = NULL;
   else {								 //  Duplicate the linked nodes
		new_copy = new_top = new Node(original_node->entry);
		while (original_node->next != NULL) {
		   original_node = original_node->next;
		   new_copy->next = new Node(original_node->entry);
		   new_copy = new_copy->next;
		}
   }
   while (!empty())				   //  Clean out old Stack entries
		pop();
   top_node = new_top;				     //  and replace them with new entries.
}

Stack::~Stack() //  Destructor
/*
Post: The Stack is cleared.
 */
{
   while (!empty())
		pop();
}
