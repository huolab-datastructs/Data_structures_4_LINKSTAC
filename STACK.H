#pragma once
//			Alex Schrepfer
//		Modified March 8th, 2001
#include "../../C/UTILITY.H"
#include "NODE.H"
typedef Node_entry Stack_entry;
class Stack {
public:
	//  Standard Stack methods
   Stack();
   bool empty() const;
   Error_code push(const Stack_entry &item);
   Error_code pop();
   Error_code top(Stack_entry &item) const;
	//  Safety features for linked structures
   ~Stack();
   Stack(const Stack &original);
   void operator =(const Stack &original);

protected:
   Node *top_node;
};
