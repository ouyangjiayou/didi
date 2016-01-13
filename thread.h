#ifndef _THREAD_H
#define _THREAD_H

#include <vector>
#include <string>
#include <pthread.h>

using namespace std;

class CTask{
protected:
       string m_strTaskName;
       void* m_ptrData;
public:
       CTask(){}
       CTask(string taskName)
       {
       	m_strTaskName = taskName;
       	m_ptrData  = NULL;
       }	
       virtual int Run() =0;
       void SetData(void* data);

public:
	virtual ~CTask(){}
};

class CThreadPool{

private:
	static vector<CTask*>m_vecTaskList;
	static bool shutdown;
	int m_iThreadNum;
	pthread_t *pthread_id;

	static pthread_mutex_t m_pthreadMutex;
	static pthread_cond_t m_pthreadCond;

protected:
	static void* ThreadFunc(void* threadData);
              static int MOveToIdle(pthread_t tid);
              static int MOveTobusy(pthread_t tid);

              int Create();

public:
              CThreadPool(int threadNUm = 10);
              int AddTask(CTask*task);
              int StopAll();
              int getTasksize();       
};

#endif

