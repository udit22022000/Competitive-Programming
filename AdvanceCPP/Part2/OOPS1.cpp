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


class Product {   //this is a blueprint

public:   //as we write this...everything below it  becomes public
	string name;  //data members
	int cost;
	int discount;

	Product() {

	}

	Product(string n, int c) {
		name = n;
		cost = c;
	}


	Product(string name, int c, int d) {
		this->name = name;
		this->cost = c;
		discount = d;
	}

	//member functions
	void display() {

		cout << name << "  " << cost << endl;
	}

	input getCost() {
		return cost;
	}



private:
	void display2() {
		display();
	}
};

struct Player {
private:
	int x, y;
};


int main(int argc, char const *argv[]) {
	file_i_o();
	//write your code here....


	Product shirt;     //this calls the default constructor...don't use paranthesis while calling the default constructor..
	shirt.name = "blue men";
	cout << shirt.name << endl;

	Product iphone("IphoneXR", 100000);
	cout << iphone.name << endl;

	//here we are using different constructors for both/...but sizes are same..
	cout << sizeof(iphone) << " " << sizeof(shirt) << endl;


	//using objects through pointers...
	Product *p = &iphone;
	cout << p -> name << endl;
	cout << p->getCost() << endl;   //accessing properties using pointers...
	cout << (*p).getCost() << endl;  //accessing using object


	//structs
	struct Player p1;
	//p1.x = 10; //will throw and error/...unable to modify private members..



	return 0;
}
