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


struct Player {
	int x;
	int y;
	void display() {
		cout << "Hello " << x << " and " << y << endl;
	}
	~Player() {
		cout << "Player Destructor" << endl;
	}

};


int main(int argc, char const *argv[]) {
	file_i_o();

	//unique pointer
	//it gets created inside heap...
	//as soon as the scope ends..this unique pointer gets destroyed..
	//we can create scopes anywhere like this...
	//unique pointers cannot be reassigned anywhere...it can't be shared...

	{
		unique_ptr<Player> ptr1 = make_unique<Player>();
		ptr1->x = 10;
		ptr1->y = 20;
		ptr1->display();
		//unique_ptr<Player> ptr2 = ptr1; //this line will throw an error...since unique pointers can't be shared....
	}

	//Shared pointer....here we can share the object...
	{
		cout << "SHARED POINTER" << endl;
		shared_ptr<Player> ptr1 = make_shared<Player>();
		shared_ptr<Player> ptr3 = ptr1;
		cout << "Reference Count " << ptr1.use_count() << endl;
	}

	//weak pointer..
	//it doesn't maintains a refrence count...
	// it can be created only by using a shared pointer or another weak pointer....
	//using weak pinter we can't access the properties of an object...
	{
		cout << "WEAK POINTER" << endl;
		shared_ptr<Player> ptr1 = make_shared<Player>();
		weak_ptr<Player> ptw(ptr1);
		cout << ptw.use_count() << endl;
		//cout << ptw->x << endl; //will throw an error
		cout << ptw.expired() << endl;
	}



	//using smart pointers in our code...

	{
		cout << "Use in Real Life" << endl;
		unique_ptr<int> p1 = make_unique<int>(10);
		cout << *p1 << endl;

	}

	return 0;
}
