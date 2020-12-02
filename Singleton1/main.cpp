#include <iostream>

class TSingleton
{

public:
    static TSingleton& getInstance( const int num1, const int num2 )
    {
        // here static is the key
         static TSingleton tSingleton ( num1, num2 );
         return tSingleton;
    }

    void printRecord( )
    {
        std::cout << num1 << "   " << num2 << std::endl;
    }
private:
    TSingleton(const int num1, const int num2 )
    {
        this->num1 = num1;
        this->num2 = num2;
    }

   // ~TSingleton( );

private:
    int num1;
    int num2;
};



int main( )
{
    TSingleton obj1 = TSingleton::getInstance( 100,200);
    obj1.printRecord( );

    TSingleton obj2 = TSingleton::getInstance( 200, 300 );
    obj2.printRecord( );

    return 0;
}
