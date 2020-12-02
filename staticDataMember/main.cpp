#include <iostream>

class TInstanceCount
{
public:
    TInstanceCount( );
    ~TInstanceCount( );
    static int getInstanceCount( );
private:
    static int s_instatnceCount;
};

TInstanceCount::TInstanceCount( )
{
    ++TInstanceCount::s_instatnceCount;
}

TInstanceCount::~TInstanceCount( )
{
}

int TInstanceCount::getInstanceCount( )
{
    return TInstanceCount::s_instatnceCount;
}

int TInstanceCount::s_instatnceCount = 0;

int main( )
{
    TInstanceCount obj1, obj2, obj3;
    std::cout << TInstanceCount::getInstanceCount( ); // 3
    return 0;
}

