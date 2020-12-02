#include<iostream>

using namespace std;

class Tcomplex
{
private:
    int _real;
    int _imag;
public:
    Tcomplex( const int real = 0, const int imag = 0 ) 
    {  }

    Tcomplex(  ) : _real( 0 ), _imag( 0 )
    {  }

    void printRecord( void ) const
    {
        cout << _real << "    " << _imag << endl;
    }
};

int main( void )
{
    // Tcomplex c1;  // Class Tcomplex has more than one default constructors
    // c1.printRecord( ); 

    Tcomplex c2( 100 );
    c2.printRecord(  ); // 100, 0

    Tcomplex c3( 500, 600 );
    c3.printRecord(  ); // 500, 600

    int wait;
    cin >> wait;

    return 0;
}
