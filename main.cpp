#include "thread.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


class CMyTask: public CTask{
 public:
 	CMyTask(){}

 	inline int Run()
 	{
 		printf("%s\n",(char*)this->m_ptrData);
 		sleep(10);
 		return 0;
 	}
};


int main()
{
	CMyTask taskobj;
	char szTmp[]="this is the first thread running";
	taskobj.SetData((void*)szTmp);
	CThreadPool threadPool(10);

	for(int i=0;i<20;i++)
	{
		cout<<"---------------------------pppppppp"<<endl;
		threadPool.AddTask(&taskobj);

	}

	while(1)
	{
		printf("thread are still %d task need to handle\n",threadPool.getTasksize());
		if(threadPool.getTasksize() ==0)
		{
			if(threadPool.StopAll() == -1)
			{
				printf("Now i will exit from main\n");
				exit(0);
			}
		}
		sleep(2);
	}
	return 0;
}
