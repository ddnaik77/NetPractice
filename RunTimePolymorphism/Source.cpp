#include <iostream>

using namespace std;

class Base
{
public:
    Base( )
    {
        this->num1 = 10;
        this->num2 = 20;
    }

    Base( const int num1, const int num2 )
    {
        this->num1 = num1;
        this->num2 = num2;
    }
    ~Base( )
    {}

    void showRecord( void )const
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }

    void printRecord( void )const
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }
private:
    int num1;
    int num2;
};


class Derived: public Base
{
public:
    Derived( )
    {
        this->num3 = 30;
    }

    Derived( const int num1, const int num2, const int num3 ): Base(num1,num2)
    {
        this->num3 = num3;
    }
    ~Derived( )
    {}

    void displayRecord( void )const
    {
        Base::showRecord( );
        cout << num3 << endl;
    }

    void printRecord( void )const
    {
        Base::printRecord( );
        cout << num3 << endl;
    }

private:
    int num3;
};

void function1( )
{
    Base * ptr = new Base( );

    ptr->showRecord( );
    // Here base class showRecord function will get called.

    ptr->printRecord( );
    // Here base class printRecord function will get called.


    //ptr->displayRecord( );
    // Since displayRecord is not a member of class Base it's a compile time error.
}

void function2( )
{
    Derived * ptr = new Derived( );
    
    ptr->showRecord( );
    // Here base class showRecord function will get called.

    ptr->Base::printRecord( );
    // Here base class printRecord function will get called.

    ptr->printRecord( );
    // Here derived class printRecord function will get called.

    ptr->displayRecord( );
    // Here derived class displayRecord function will get called.

}

void function3( )
{
    Derived derivedInstance ( 500, 600, 700);
    Base baseInstance;

    baseInstance = derivedInstance;
    // Object slicing

    baseInstance.printRecord( );
    // Output:
    // num1 : 500
    // num2 : 600
    // Here base class printRecord function will get called.

    /*
    IQ: Since every derived type object can be considered as object of base class 
    we can assign derived class object to the base class.

    OBJECT SLICING: 
    * It's a process of coping values of base class portion present inside derived class 
    object to the base class object.
    * To avoid object slicing we should make base class as abstract.
    
    UPCASTING:
    * 

    */

}

void function4and5( )
{
    /*
        UPCASTING:
        * It's a process of converting pointer of derived class into
        pointer of base class.
        * It's a process of storing address of derived class object into 
        pointer of base class.
    */

    Derived * ptrDerived = new Derived( 500, 600, 700);

    Base* ptrBase = ( Base* )/*optional*/ ptrDerived;
    // Upcasting
    // OR 
    // Base* ptrBase = new Derived( 500, 600, 700);

    ptrBase->showRecord( );
    // Here base class showRecord function will get called.

    ptrBase->printRecord( );
    // Here base class printRecord function will get called.

}

void function6( )
{
    Derived d1( 500,600,700);
    Derived& d2 = d1;

    d2.showRecord( );
    // Here base class showRecord function will get called.

    d2.printRecord( );
    // Here derived class printRecord function will get called.

    d2.displayRecord( );
    // Here derived class displayRecord function will get called.

}

void function7( )
{
    /*
        UPCASTING: Process of storing reference of derived class object inside
        variable of base class is called upcasting.
    */

    Derived derivedInstance( 500,600,700);
    Base& baseReference = derivedInstance;
    //Base * const baseReference = &derivedInstance;

    baseReference.printRecord( );
    // Here base class printRecord function will get called.

    baseReference.showRecord( );
    // Here base class showRecord function will get called.

}

void function8( )
{
    /*
        DOWNCASTING:
        It is a process of converting pointer of base class into 
        pointer of derived class.
    */

    Base * ptrBase = new Derived( 500,600,700);
    // Upcasting

    Derived* ptrDerived = ( Derived* )/*not optional here*/ptrBase;

    ptrDerived->displayRecord( );
    // Here derived class displayRecord function will get called.

}

void function9( )
{
    Base baseInstance( 500, 600 );
    Derived derivedInstance;

    //derivedInstance = baseInstance;
    // NOT ALLOWED

    derivedInstance.printRecord( );
    // Here derived class printRecord function will get called.

    /*
        Since every base class object can not be considered as object 
        of derived class we cannot assign base class object to
        derived class object.
    */
}

void function10( )
{
    /*
        Derived * ptr = new Base( );    // NOT ALLOWED

        * Since every base class object can not be considered as object 
        of derived class we cannot assign base class pointer to
        derived class pointer.

        * Every derived class object is considered as object of base class.
        we can assign derived class object to base class object.
    
    */
}


int main( )
{
    function1( );
    function2( );
    function3( );
    function4and5( );
    function6( );
    function7( );
    function8( );
    function9( );
    function10( );

    return 0;
}