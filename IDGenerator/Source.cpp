// C++ program to print all 
// possible strings of length k 
#include <iostream> 
#include <string>
using namespace std;


// The main recursive method 
// to print all possible 
// strings of length k 
void printAllKLengthRec( char set[], string prefix,
    int n, int k )
{

    // Base case: k is 0, 
    // print prefix 
    if( k == 0 )
    {
        std::cout << prefix  << endl;
        return;
    }

    // One by one add all characters 
    // from set and recursively 
    // call for k equals to k-1 
    for( int i = 0; i < 1; i++ )
    {
        string newPrefix;

        // Next character of input added 
        newPrefix = prefix + set[i];

        // k is decreased, because 
        // we have added a new character 
        printAllKLengthRec( set, newPrefix, n, k - 1 );
    }

}

void generateSequenceID( char set[], int k, int n )
{
    printAllKLengthRec( set, "", n, k );
}

// Driver Code 
int main( )
{

    cout << "Second Test\n";
    char set2[] = { 'a', 'b', 'c', 'd' };
    int k = 6;
    generateSequenceID( set2, k, 4 );
    generateSequenceID( set2, k, 4 );
    std::getchar( );
}

// This code is contributed 
// by Mohit kumar 
