#include <iostream>

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
};

template <class Type>
class AutomaticPointer
{
private:
    Type* ptr;
public:
    AutomaticPointer( Type * ptr )
    {
        this->ptr = ptr;
    }

    Type* operator->( )
    {
        return this->ptr;
    }

    ~AutomaticPointer( )
    {
        if( this->ptr != nullptr )
        {
            delete this->ptr;
            this->ptr = nullptr;
        }
    }
};



int main()
{ 
    //Here object is a smart pointer.
    AutomaticPointer <TArray> obj (new TArray(3) );
    obj->populateArray( );
    obj->printArray( );

  return 0;
}
