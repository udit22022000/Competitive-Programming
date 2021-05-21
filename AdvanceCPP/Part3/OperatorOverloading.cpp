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


class Test {
public:
	int count;
	int arr[100];

	Test() : count(0) {};

	Test(int c) : count(c) {};

	int get_count() const {
		return this->count;
	}

	//overload unary operator... ++ and --

	//case 1 : overload prefix....
	Test operator++() {
		++this->count;
		//return this->count;
		return Test(this->count);  // returning a new object..
	}

	//case 2: overload postfix...
	//just write int inside params to overload postfix...
	Test operator++(int) {
		return Test(this->count++);
	}

	//case 3: overlaod binary operator..(+,-,*,/....)

	Test operator+(Test t) {
		int temp = this->count + t.count;
		return Test(temp);
	}

	//case 4: overload comparison operator...

	bool operator < (Test v) {
		bool b = this->count < v.count;  //v is an object...and ...this is a pointer...
		return b;
	}

	//case 5: overload assignment operator...

	void operator += (Test& v) {
		this->count += v.count;
	}

	//case 6: overload subscript operator...([])
	int& operator [](int n) {  //here we are returning the refrence of the bucket this->arr[n]...
		if (n < 0 or n >= 100) {
			exit(1);
		}
		return this->arr[n];
	}

	//operators that can't be overloaded...
	/*
	1. (.) dot
	2. (?:) ternary
	3. (::) scope resolution
	4. (.*) pointer to member
	5. (sizeof) sizeof operator...
	6. (typeid)

	*/



};

int main(int argc, char const *argv[]) {
	file_i_o();
	//write your code here....


	Test t;
	cout << t.get_count() << endl;
	Test x = ++t;
	cout << x.get_count() << endl;

	Test y = t++;
	cout << y.get_count() << endl;

	cout << x.get_count() << " " << t.get_count() << endl;
	Test z = x + t;   // x asks to add t....//t is passed as an argument to the overloaded + operator....
	cout << z.get_count() << endl;


	bool b = x < t;
	cout << b << endl;


	cout << x.get_count() << " " << t.get_count() << endl;
	x += t;
	cout << x.get_count() << " " << t.get_count() << endl;


	cout << x[10] << endl;
	x[10] = 11;
	cout << x[10] << endl;
	return 0;
}
