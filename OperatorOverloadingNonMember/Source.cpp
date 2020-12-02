#include<iostream>
using namespace std;

class TPoint
{
private:
    int _xPosition;
    int _yPosition;
public:
    TPoint( int xPosition = 0, int yPosition = 0 ):_xPosition( xPosition ),_yPosition(  yPosition  )
    {}

    void printPoint( )
    {
        cout << "( " << _xPosition << ", " << _yPosition << " )" << endl;
    }

    // pt2 = pt1
    // pt2.operator=( pt1 )
    // pt3 = pt2 = pt1
    // pt3.operator=( pt2.operator=( pt1 ) )
    TPoint& operator=( const TPoint& other )
    {
        if( this == &other )
        {
            return *this;
        }
        else
        {
            this->_xPosition = other._xPosition;
            this->_yPosition = other._yPosition;
            return *this;
        }
    }

    // Friend operator function 
    friend TPoint operator+( const TPoint& p1, const TPoint& p2 )
    {
        cout << "operator+" << endl;
        TPoint sum;
        sum._xPosition = p1._xPosition + p2._xPosition;
        sum._yPosition = p1._yPosition + p2._yPosition;
        return sum;
    }

    // operator<< (cout,pt1)
    friend ostream& operator<<(ostream& out, const TPoint& point )
    {
        out << "X: " << point._xPosition << "    y: " << point._yPosition << endl;
        return out;
    }

   
};

//TPoint operator+( const TPoint& p1, const TPoint& p2 )
//{
//    cout << "operator+" << endl;
//    TPoint sum;
//    sum._xPosition = p1._xPosition + p2._xPosition;
//    sum._yPosition = p1._yPosition + p2._yPosition;
//    return sum;
//}

int main( )
{
    TPoint tpoint;
    tpoint.printPoint( );

    TPoint tpoint1( 10);
    tpoint1.printPoint( );

    TPoint tpoint3( 10, 20);
    tpoint3.printPoint( );

    tpoint = tpoint1 + tpoint3;
    tpoint.printPoint( );

    tpoint = tpoint + tpoint1 + tpoint3;
    cout << tpoint;

    tpoint = tpoint3;
    cout << "Assignment operator function "<< endl;
    tpoint.printPoint( );


    int hold;
    cin >> hold;
    return 0;
}

