#include <iostream>
#include <iomanip>

class Base
{
	public:
	Base() : a{1}, b{2}, c{3} {}

	void fbase(){
		std::cout << "Base.a:\tpublic\t\tvalue: " << a << std::endl;	// public
		std::cout << "Base.b:\tprotected\tvalue: " << b << std::endl;	// protected
		std::cout << "Base.c:\tprivate\t\tvalue: " << c << std::endl;	// private
	}

	public:
	int a;

	protected:
	int b;
	void protectedF() {}

	private:
	int c;
	void privateF() {}
};

class A : public Base
{
	public:
	void fa()
	{
		std::cout << "A.a:\tpublic\t\tvalue: " << a << std::endl;   // public
		std::cout << "A.b:\tprotected\tvalue: " << b << std::endl;  // protected
		std::cout << "A.c:\tnot accessible" << std::endl;	    // error: not accessible from A
	}

	// a is public
	// b is protected
	// c is not accessible from A

};
class B : protected Base
{
	public:
	void fb()
	{
		std::cout << "B.a:\tprotected\tvalue: " << a << std::endl;	// protected
		std::cout << "B.b:\tprotected\tvalue: " << b << std::endl;	// protected
		std::cout << "B.c:\tnot accessible" << std::endl;		// error: not accessible from B

		std::cout << "B.protectedBaseF():\tok" << std::endl;
		std::cout << "B.privateBaseF():\terror" << std::endl;
		protectedF();
		//privateF();
	}

	// a is protected
	// b is protected
	// c is not accessible from B
};

class C : private Base
{
	public:
	void fc()
	{
		std::cout << "C.a:\tnot accessible" << std::endl;	// private
		std::cout << "C.b:\tnot accessible" << std::endl;	// private
		std::cout << "C.c:\tnot accessible" << std::endl;	// error: not accessible from C
	}

	// a is private
	// b is private
	// c is not accessible from C
};

int main()
{
	Base base;
	A a;
	B b;
	C c;

	std::cout << "##############################################" << std::endl;
	std::cout << "Access inside classes: " << std::endl;
	std::cout << "##############################################" << std::endl;

	base.fbase();

	std::cout << std::endl;
	std::cout << "A : public Base" << std::endl;
	a.fa();

	std::cout << std::endl;
	std::cout << "B : protected Base" << std::endl;
	b.fb();

	std::cout << std::endl;
	std::cout << "C : private Base" << std::endl;
	c.fc();

	std::cout << "##############################################" << std::endl;
	std::cout << "Access member outside classes: " << std::endl;
	std::cout << "##############################################" << std::endl;

	std::cout << "Access base a:\tok" << std::endl;
	std::cout << "Access base.b:\terror" << std::endl;
	std::cout << "Access base.c:\terror" << std::endl;

	base.a++; // ok
	//base.b++; // error
	//base.c++; // error

	std::cout << std::endl << "A : public Base" << std::endl;
	std::cout << "Access a a:\tok" << std::endl;
	std::cout << "Access a.b:\terror" << std::endl;
	std::cout << "Access a.c:\terror" << std::endl;

	a.a++; // ok
	//a.b++; // error
	//a.c++; // error

	std::cout << std::endl << "B : protected Base" << std::endl;
	std::cout << "Access b a:\tnot accessible" << std::endl;
	std::cout << "Access b.b:\tnot accessible" << std::endl;
	std::cout << "Access b.c:\tnot accessible" << std::endl;

	//b.a++; // ok
	//b.b++; // error
	//b.c++; // error

	std::cout << std::endl << "C : private Base" << std::endl;
	std::cout << "Access c a:\terror" << std::endl;
	std::cout << "Access c.b:\terror" << std::endl;
	std::cout << "Access c.c:\terror" << std::endl;

	//c.a++; // ok
	//c.b++; // error
	//c.c++; // error
}
