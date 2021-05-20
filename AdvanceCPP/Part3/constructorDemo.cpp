#include<bits/stdc++.h>
using namespace std;


void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*

NOTES  : ---

1. Constructor is a special type of function which is having same name as that of class.
2. Having multiple constructors is called constructor overloading....
3. Poly-Morphism means one things can have many forms...it can work differently in different situations...like overloading a function...
4. There are 2 types pf polymorphism: --
		a. Compile time Polymorphism...(it's also called as early binding..)...everything happens during compile time..
		b. Run time Polymorphism.....
5. Constructor Overloading is one type of polymorphism..it's a compile time polymorphism...

6. Function Overloading -----
	a. Only functions with differemt parameters can be overloaded.
	b. Functions with different return type and same params can't be overloaded.
*/


class ComplexNumber {
public:
	int real, img;
	int *ptr;

	//default constructor...
	ComplexNumber() {
		this->real = 0;
		this->img = 0;
	}   //random value initialization..


	//default constructor...
	//ComplexNumber() : real(0), img(0) {}  //we can also define default constructors like this...with default values....



	//parameterized constructor...
	ComplexNumber(int real, int img) {
		this->real = real;
		this->img = img;
	}

	//parameterized constructor with deafult values...
	// ComplexNumber(int real = 0, int img = 0) {
	// 	this->real = real;
	// 	this->img = img;
	// }




	//Functions with different return type and same params can't be overloaded...
	//EXAMPLE...
	/*
	int getReal() {
		return this->real;
	}

	void getReal() {
		cout << this->real << endl;
	}
	*/


	void display(float x) {
		cout << x << endl;
	}

	void display(int x) {
		cout << x << endl;
	}


	int show_real();  //declared inside....defined outside the class....


	//our own custom copy constructor..to perform deep copy...
	ComplexNumber(ComplexNumber &s) {
		this->real = s.real;
		this->img = s.img;
		this->ptr = new int;
		*ptr = *(s.ptr);
	}

};


//defining functions for a class...outside the class...but we need to declare this function inside the class..
//  :: scope resolution operator....
int ComplexNumber::show_real() {
	return real;
}


int main(int argc, char const *argv[]) {
	file_i_o();
	//write your code here....

	//ComplexNumber c; // this will work fine if there is no default constructor ....if the class has default constructor then u will haver to put empty paranthesis...OR ELSE...make the default constructor public in the class..
	//ComplexNumber c();  //if the class has default constructor...use paranthesis...


	ComplexNumber c;
	c.display(7);
	c.display(1.1f);
	cout << c.show_real() << endl;

	int x = 10;
	c.ptr = &x;

	//copy constructor is called which initializes an object using other object of the same class......
	//2 types of copies that can be done....1. Shallow copy -> An object is created by simply copying the data of all variables of other object.. 2. Deep copy -> When an object is created by copying the data of all variables of other object...it also allocates similar memory resource for the same..
	//default copy constructor always does shallow copy....
	ComplexNumber m(c);
	cout << m.real << " " << m.img << endl;
	m.real = 100;
	cout << m.real << " " << m.img << endl;
	cout << c.real << " " << c.img << endl;
	cout << c.ptr << " " << m.ptr << endl;
	return 0;
}