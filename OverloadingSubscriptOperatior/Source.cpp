#include<iostream>

using namespace std;


class TArray
{
private:
    int m_size;
    int* m_arr;

public:
    TArray( int size = 0 ) :m_size( size )
    {
        cout << "Constructor" << endl;
        m_arr = new int[size];
    }

    ~TArray( )
    {
        cout << "Destructor" << endl;
        clear( );
    }

    void clear( )
    {
        cout << "Clear..." << endl;
        if( m_arr != 0 )
        {
            delete m_arr;
            m_arr = 0;
            m_size = 0;
        }
    }
    void printArray( )
    {
        cout << "Array of size: " << m_size << "    |";
        for( int i = 0; i < m_size; i++ )
        {
            cout << "  " << m_arr[i] << "  |";
        }
        cout << endl;
    }

    void populateArray( )
    {
        for( int i = 0; i < m_size; i++ )
        {
            cout << "Enter the " << i << " th element: " << endl;
            cin >> m_arr[i];
        }
    }
#if 0
    // Shallow Copy
    TArray& operator=( const TArray& other )
    {
        cout << "Operator= function " << endl;
        this->m_size = other.m_size;
        this->m_arr = other.m_arr;
        return *this;
    }
#endif

    // Deep copy
    TArray& operator=( const TArray& other )
    {
        cout << "Operator= function " << endl;
        if( this == &other )
        {
            return *this;
        }
        else
        {
            this->clear( );
            this->m_size = other.m_size;
            this->m_arr = new int[this->m_size];
            memcpy( this->m_arr, other.m_arr, sizeof( int )* m_size );
            return *this;
        }
    }

    // int value = a[1];
    // int value = a.operator[](1);
    int& operator[]( int index )
    {
        if( index > 0 && index < m_size )
        {
            return m_arr[index];
        }
        else
        {
            int value = 0;
            return value;
            // We should throw exception here.
        }
    }
};

int main( )
{

    TArray a( 3 );
    a.populateArray( );
    a.printArray( );

    int value = a[2];
    cout << "Value at a[2]: " << value << endl;

    int num1;
    cin >> num1;
    return 0;
}
