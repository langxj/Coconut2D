/* Generated by Coconut2D C++ Compiler from file TestInterfaces.jspp */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TestInterfaces.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
void ITest1::foo()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
void ITest2::goo()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
void ITest3::zoo()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::foo()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::goo()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::zoo()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
ClassTestInterfaces::ClassTestInterfaces()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
ClassTestInterfaces::~ClassTestInterfaces()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::interface_test1(ITest1* obj)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::interface_test2(ITest2* obj)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::interface_test3(ITest3* obj)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::interface_class(ClassTestInterfaces* obj)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ClassTestInterfaces::interface_tests()
{
	ITest1* i1 = this;
	ITest2* i2 = this;
	ITest3* i3 = this;
	interface_test1(i1);
	interface_test1(i2);
	interface_test2(i2);
	interface_test3(i3);
	interface_test1(this);
	interface_test2(this);
	interface_test3(this);
}