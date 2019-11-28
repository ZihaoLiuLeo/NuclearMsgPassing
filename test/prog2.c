#include "syscall.h"
int
main()
{
	int buffer1;
        buffer1 = WaitMsg_POS("../test/prog1\0",1,-1);
        buffer1 = SendAns_POS("../test/prog1\0",2,buffer1);
	Exit(0);
}

