#include "syscall.h"

int
main()
{
	int buffer;
	buffer = SendMsg_POS("../test/prog2\0",1,-1);
	buffer = WaitAns_POS("../test/prog2\0",2,buffer);
	Exit(0);
}

