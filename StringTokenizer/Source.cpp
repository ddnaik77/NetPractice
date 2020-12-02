#include <string>
#include <vector>
#include <iostream>


std::vector<std::string> tokenizeString( const std::string& input, const std::string& delims )
{
    std::vector<std::string> vectorTokens;
    std::string::size_type beg_index;
    std::string::size_type end_index;

    beg_index = input.find_first_not_of( delims );

    while( beg_index != std::string::npos )
    {
        end_index = input.find_first_of( delims, beg_index );
        if( end_index == std::string::npos )
        {
            end_index = input.length( );
        }
        std::string token = input.substr( beg_index, end_index - beg_index );
        vectorTokens.push_back( token );
        beg_index = input.find_first_not_of( delims, end_index );
    }
    return vectorTokens;
}

int main( )
{
    // IRDI
    std::string inputString = "SPLM-03#01-864807#001";
    std::string delimeter = "#";
    std::string namespaceValue;
    std::string type;
    std::string id;
    std::string revision;

    std::vector<std::string> tokens = tokenizeString( inputString, delimeter );
    if( tokens.size() == 3 )
    {
        namespaceValue = tokens[0];

        // Get ID from the next token
        delimeter = "-";
        std::vector<std::string> tokensForId = tokenizeString( tokens[1], delimeter );
        type = tokens[1].substr(0,2 );//tokensForId[0];
        id = tokens[1].substr( 3, tokens[1].length() );

        revision = tokens[2];

        std::cout << "inputString: "<< inputString << std::endl;
        std::cout << "namespaceValue: "<< namespaceValue << std::endl;
        std::cout << "type: "<< type << std::endl;
        std::cout << "id: " << id << std::endl;
        std::cout << "revision: " << revision << std::endl;

    }
    else
    {
        // IRDI format is incorrect.
        throw;
    }

    std::getchar( );
    return 0;
}