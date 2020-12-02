#include<iostream>

using namespace std;

class A
{
public:
    A( )
    {
        this->num1 = 10;
    }

    A( int num1)
    {
        this->num1 = num1;
    }

    ~A( )
    {

    }

    void printRecord( )const
    {
        cout << num1 << endl;
    }

private:
    int num1;
};

class B: virtual public A
{
public:
    B( void)
    {
        this->num2 = 20;
    }

    B( const int num1, const int num2): A(num1)
    {
        this->num2 = num2;
    }

    ~B( )
    {

    }

    void printRecord( )const
    {
        A::printRecord( );
        this->showRecord( );
    }

protected:
    void showRecord( ) const
    {
        cout << num2 << endl;
    }
private:
    int num2;
};


class C : virtual public A
{
public:
    C( void )
    {
        this->num3 = 30;
    }

    C( const int num1 ,const int num3 ):A(num1)
    {
        this->num3 = num3;
    }

    ~C( )
    {

    }

    void printRecord( )const
    {
        A::printRecord( );
        this->showRecord( );
    }

protected:
    void showRecord( ) const
    {
        cout << num3 << endl;
    }
private:
    int num3;
};


class D: public B, public C
{
public:
    D( )
    {
        this->num4 = 40;
    }

    D( const int num1, const int num2, const int num3, const int num4):A(num1), B(num1, num2), C(num1, num3)
    {
        this->num4 = num4;
    }

    ~D( )
    {}

    void printRecord( )const
    {
        A::printRecord( );
        B::showRecord( );
        C::showRecord( );
        this->showRecord( );
    }

protected:
    void showRecord( ) const
    {
        cout << num4 << endl;
    }
private:
    int num4;
};

int main()
{
    D obj( 100,200,300,400 );
    obj.printRecord( );

    return 0;
}
