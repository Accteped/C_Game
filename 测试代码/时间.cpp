#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    time_t now=time(0);
    tm *ltm=localtime(&now);
	
    cout<<ltm->tm_mon<<ltm->tm_mday<<endl<<ltm->tm_yday;
    return 0;
}

