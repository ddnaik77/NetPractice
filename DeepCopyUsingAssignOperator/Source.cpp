#include<iostream>

using namespace std;

void arrayDemo( )
{/*
    // if value of row in unknown
    int row;
    cin >> row;

    int ( *arr )[3] = new int[row][3];

    for( size_t i = 0; i < row; i++ )
    {
        for( size_t j = 0; j < 3; j++ )
        {
            arr[i][j] = i + j;
            cout << arr[i][j] << "    ";
        }
        cout << endl;
    }

    // If we don't know both row and column
    int rows;
    int columns;
    int ** arr1 = new int*[rows];
    for( size_t i = 0; i < columns; i++ )
    {
        arr1[i] = new int[columns];
    }
    */
}

class TArray
{
private:
    int m_size;
    int* m_arr;

public:
    TArray(int size = 0):m_size(size)
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
        cout << "Array of size: "<<  m_size <<"    |";
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

int main( )
{

    int size = 0;
    cout << "Enter the size of array:" << endl;
    cin >> size;

    TArray arr1( size );
    arr1.populateArray( );
    arr1.printArray( );

    TArray arr2;
    arr2 = arr1;
    arr2.printArray( );

    TArray* arr3 = new TArray( );
    arr3 = &arr2;
    arr3->printArray( );

    return 0;
}
