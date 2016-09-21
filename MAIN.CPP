//			Alex Schrepfer
//		Modified March 8th, 2001

// This program loads extended_extended and tests many of the
// functions from them. The data from the test is either outputted
// to a file or to the screen for the user to see instantly..

#include <cstdlib>
#include "NODE.H"
#include "STACK.H"
#include "EXSTACK.H"


//  test push and pop functions
void main()
{
   char c;
   Extended_stack data;

	char file;
	cout << "Do you want this outputted to file [y/n]? ";
	cin >> file;

	//outputs to file
	if ((file == 'Y') || (file == 'y')) {


		ofstream fout("output.txt");
		if (fout.fail()) {
			cout << "Failed to create: 'output.txt'";
			exit(1);

		}

		//initialize c to a value
		c = '0';
		  data.top(c);
		fout << "Try top on empty stack, expecting garbage ie. 0: " << c << endl;
		fout << "Push a, b, and c" << endl;
		data.push('a');
		data.push('b');
		data.push('c');
		data.top(c);
		fout << "Top, expecting c: " << c << endl;
		data.pop();
		data.top(c);
		fout << "Pop, Top expecting b: " << c << endl;
		data.pop();
		data.top(c);
		fout << "Pop, Top expecting a: " << c << endl;
		data.pop();

		//initialize c to a value
		c = '0';
		data.top(c);
		fout << "Tried pop on empty stack, expecting garbage ie. 0: " << c << endl;

		fout << endl << "Push x, y, and z" << endl;
		data.push('x');
		data.push('y');
		data.push('z');

		fout << "Size, expecting 3: " << data.size() << endl;
		fout << "Full, expecting false (0): " << data.full() << endl;

		data.pop_and_top(c);
		fout << "Pop_and_top, expecting y: " << c << endl;

		data.clear();
		//initialize c to a value
		c = '0';
		data.top(c);
		fout << "Clear & Empty, expecting true (1): " << data.empty() << endl;

		//initialize c to a value
		c = '0';
		data.pop_and_top(c);
		fout << "Tried to Pop_and_top on empty stack, expecting garbage ie. 0: " << c << endl;

		cout << "Done! File 'output.txt' created!" << endl;
	}

	//outputs to screen
	else {

		//initialize c to a value
		c = '0';
		data.top(c);
		cout << "Try top on empty stack, expecting garbage ie. 0: " << c << endl;
		cout << "Push a, b, and c" << endl;
		data.push('a');
		data.push('b');
		data.push('c');
		data.top(c);
		cout << "Top, expecting c: " << c << endl;
		data.pop();
		data.top(c);
		cout << "Pop, Top expecting b: " << c << endl;
		data.pop();
		data.top(c);
		cout << "Pop, Top expecting a: " << c << endl;
		data.pop();

		//initialize c to a value
		c = '0';
		data.top(c);
		cout << "Tried pop on empty stack, expecting garbage ie. 0: " << c << endl;

		cout << endl << "Push x, y, and z" << endl;
		data.push('x');
		data.push('y');
		data.push('z');

		cout << "Size, expecting 3: " << data.size() << endl;
		cout << "Full, expecting false (0): " << data.full() << endl;

		data.pop_and_top(c);
		cout << "Pop_and_top, expecting y: " << c << endl;

		data.clear();
		//initialize c to a value
		c = '0';
		data.top(c);
		cout << "Clear & Empty, expecting true (1): " << data.empty() << endl;

		//initialize c to a value
		c = '0';
		data.pop_and_top(c);
		cout << "Tried to Pop_and_top on empty stack, expecting garbage ie. 0: " << c << endl;
	}

}
