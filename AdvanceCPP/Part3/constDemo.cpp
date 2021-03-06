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


void constInDetail() {
	//trying to modify const type...
	const int MAX_VAL = 1000;
	int const MAX_VAL2 = 100; //both int const and const int are same.....
	//MAX_VAL++;   //will throw error ..
	//MAX_VAL = 15;   //will throw error..

	//trying to modify const type with the help of a pointer...
	//int *ptr = &MAX_VAL;   //will throw an error
	const int *ptr = &MAX_VAL;
	//*ptr = 2      //will throw an error...since it's read only variable...



	//through this also we are unable to change the value of const type...
	//pointers will work as it is...and const will work as it is supposed to work...
	int *p1 = new int;
	*p1 = 2;
	p1 = (int *)&MAX_VAL;  //since MAX_VAL is storing value of type const int...so we need to type cast it to int...
	*p1 = 10;
	cout << MAX_VAL << "  " << *ptr << "  " << *p1 << endl;  //something very weird..
	cout << &MAX_VAL << " " << ptr << "  " <<  p1 << endl;

	//NOTE : --- Through this we can say that ..if bucket is of type const..even pointers will not be able to tweek the value inside the bucket...

	cout << "------------------" << endl;

	//NOTE: -- if the pointer is of const int or int const type...that pointer can be made pointed to some other bucket...but value of the bucket is not changeable...
	const int *a = new int(10);
	// *a = 1000;   //will throw an error...
	int b = 1000;
	a = (int const *)&b;
	cout << *a << endl;

	cout << "********************" << endl;

	//NOTE :---- Here we can see that we can change the value of the bucket...but we can change the bucket to which pointer is pointing...
	int* const z = new int;
	*z = 20;
	int k = 10000;
	//z = &k;   //this will throw an error...
	cout << *z << endl;

	cout << "====================" << endl;

	//NOTE: --- completely blocked...address to which pointer is pointing is not changable...and value also can't be changed...
	const int MAXX = 1000;
	const int* const ex = &MAXX;  //completely blocked...

}

class Test {
public:
	int x = 100;
	static int y;

	//const functions are generally used in the getter methods...
	int getX() const {
		//x = 10;  //since we have written const after function name...value of non-static member variables can't be changed..
		//y =  20;  //but we can assign values to static variable inside const function....will discuss later about it..
		cout << "with const" << endl;
		return x;
	}

	//non const version of getX...//overloading getX...
	int getX() {
		cout << "without const" << endl;
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

};

void func(const int x) {
	//x = 10;  //it will throw an error....//we can't change the value of const int type parameters....
}

void func2(Test &t) {
	cout << t.getX() << endl;
}

void func3(const Test &t) {
	cout << t.getX() << endl;
}


int main(int argc, char const *argv[]) {
	file_i_o();

	//Const In Detail -- Uncomment and run this function///.///
	//constInDetail();

	//const params can't be changed
	//func(54);

	//Class Test...
	Test hello;
	func2(hello);
	func3(hello);


	return 0;
}
