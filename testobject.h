#ifndef TESTOBJECT_H
#define TESTOBJECT_H


class TestObject
{

    double _prop1;
    double _prop2;
    double _prop3;
    double _prop4;

public:
    TestObject();
    void setProp1(double value);
    void setProp2(double value);
    void setProp3(double value);
    void setProp4(double value);
    double prop1();
    double prop2();
    double prop3();
    double prop4();
};


#endif // TESTOBJECT_H
