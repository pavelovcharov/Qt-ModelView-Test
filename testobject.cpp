#include "testobject.h"

TestObject::TestObject()
{

}

void TestObject::setProp1(double value)
{
    _prop1 = value;
}

void TestObject::setProp2(double value)
{
    _prop2 = value;
}

void TestObject::setProp3(double value)
{
    _prop3 = value;
}

void TestObject::setProp4(double value)
{
    _prop4 = value;
}

double TestObject::prop1()
{
    return _prop1;
}

double TestObject::prop2()
{
    return _prop2;
}

double TestObject::prop3()
{
    return _prop3;
}

double TestObject::prop4()
{
    return _prop4;
}
