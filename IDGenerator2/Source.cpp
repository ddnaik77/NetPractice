// C++ program to print all 
// possible strings of length k 
#include <iostream> 
#include <string>
#include <vector>
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
        std::cout << prefix << endl;
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

std::string generateNextSequenceID( const std::string set, std::string& latestSequence, int k)
{
    if( latestSequence.empty( ) || latestSequence.length() != 6 )
    {
        latestSequence = "";
    }
    else if( k != 0)
    {
        char currentChar = latestSequence.at(k-1);
        if( currentChar != 0 && currentChar != '0' )
        {
            //Happy case
            //Find next char in sequence list
            int index = set.find(currentChar);
            latestSequence[k - 1] = set[index + 1];
        }
        else
        {
            // last char is '0'
            // Change it to start and reduce index value
            latestSequence[k - 1] = set[0];
            k--;
            generateNextSequenceID( set, latestSequence, k);
        }
    }
    return latestSequence;
}

// Driver Code 
int main( )
{

    cout << "Second Test\n";
    std::string set2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
    int k = 6;
    std::string start = "999999";
    for( size_t i = 0; i < 10; i++ )
    {
        start = generateNextSequenceID( set2, start, k);
        cout << start << endl;
    }
    

    std::getchar( );
}

