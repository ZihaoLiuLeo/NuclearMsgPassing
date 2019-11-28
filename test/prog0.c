#include "syscall.h"
int
main()
{
        int buffer,badbuffer;
        buffer = WaitMsg_POS("../test/prog9\0",25,-1);
        buffer = WaitMsg_POS("../test/prog9\0",26,buffer);
        buffer = WaitMsg_POS("../test/prog9\0",27,buffer);
	//wait for incorrect buffer assignment
	badbuffer = 1;
        badbuffer = WaitMsg_POS("../test/prog9\0",27,badbuffer);

	
        buffer = SendAns_POS("../test/prog9\0",30,buffer);
        buffer = SendAns_POS("../test/prog9\0",31,buffer);
        buffer = SendAns_POS("../test/prog9\0",32,buffer);

        badbuffer = SendAns_POS("../test/prog9\0",33,buffer);
        Exit(0);
}
