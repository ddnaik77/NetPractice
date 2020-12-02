// OperatorOverloading.cpp : Defines the entry point for the console application.
//
#include<iostream>

using namespace std;

class Tcomplex
{
private:
    int _real;
    int _imag;
public:

   Tcomplex( const int real = 0, const int imag = 0 )
    { 
        this->_real = real;
        this->_imag = imag;
    }


    /*
    Tcomplex( ) : _real( 0 ), _imag( 0 )
    {  }
    */

    void printRecord( void ) const
    {
        cout << _real << "    " << _imag << endl;
    }

    // Operator overloads

    Tcomplex operator++( )
    {
        Tcomplex temp;
        temp._real = ++this->_real;
        temp._imag = ++this->_imag;
        return temp;
    }

    Tcomplex operator++( int )
    {
        Tcomplex temp;
        temp._real = this->_real++;
        temp._imag = this->_imag++;
        return temp;
    }

    void* operator new( size_t size )
    {
        // here size is 8. i.e. size of object.
        void* ptr = malloc( size );
        return ptr;
        //if(ptr == nullptr)
        // throw bad_alloc
    }

    void operator delete( void * ptr )
    {
        free( ptr );
    }
};

int main()
{
    Tcomplex* c1 = new Tcomplex( 2);
    // Tcoplex *c1 = (Tcomplex*) Tcomplex::operator new (sizeof(Tcomplex) * size);

    delete c1;

    // Global or non overloaded new operator
    Tcomplex *ptr = ::new Tcomplex( );


    /*
    // c2 = ++c1;
    Tcomplex c1(10,20 );
    c1.printRecord( );

    Tcomplex c2;
    c2.printRecord( );

    c2 = ++c1;
    // c2 = c1.operator++();
    c2.printRecord( );

    c2 = c1++;
    // c2 = c1.operator++( 0);
    c2.printRecord( );
    */
    /*
    int num1 = 10;
    int num2 = ++num1;

    cout << num1 <<endl;
    cout << num2 << endl;
    // 11, 11
    */

    /*
    int num1 = 10;
    int num2 = num1++;

    cout << num1 << endl;
    cout << num2 <<endl;
    // 10, 11

    */
    int num1;
    cin >> num1;
    return 0;
}

