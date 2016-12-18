#include <iostream>

using namespace std;

class B1
{
public:
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf() { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
	void pvf() { cout << "D1::pvf()\n"; }
};

class D2 : public D1
{
public:
	void pvf() { cout << "D2::pvf()\n"; }
};

class B2
{
public:
	virtual void pvf() =0;
};

class D21 : public B2
{
public:
	D21(string str)
		: str(str) {};
	void pvf() { cout << "D21::pvf(): " << str << "\n"; };
private:
	string str;
};

class D22 : public B2
{
public:
	D22(int val)
		: val(val) {};
	void pvf() { cout << "D22::pvf(): " << val << "\n"; };
private:
	int val;
};

void printPVF(B2& b2)
{
	b2.pvf();
}

int main()
{
	// B1 b1;
	D1 d1;
	B1& b1r = d1;
	D2 d2;
	D21 d21("STR");
	D22 d22(666);
	
	//b1.vf();
	//b1.f();
	/*d1.vf();
	d1.f();
	b1r.vf();
	b1r.f();
	d2.f();
	d2.vf();
	d2.pvf();
	*/
	d21.pvf();
	d22.pvf();
	printPVF(d21);
	printPVF(d22);

	return 0;
}
