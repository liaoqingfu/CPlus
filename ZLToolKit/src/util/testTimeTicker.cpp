#include <iostream>
#include <unistd.h>

#include "TimeTicker.hpp"
using namespace std;
using namespace ZL::Util;


void run(int i)  
{  printf("test run i  = %d\n", i);
} 

int main(void)
{
	//������־ϵͳ
	Logger::Instance().add(std::make_shared<ConsoleChannel>("stdout", LTrace));
	Logger::Instance().setWriter(std::make_shared<AsyncLogWriter>());
	Ticker *timeTicker =  new Ticker(3000);//��ʱ��

	DebugL << "start async task"<< endl;
	timeTicker->resetTime();//��ʼ��ʱ

	sleep(2);
	
	//��ʱӦ�������˼��̵�ʱ�䣬��û��������ǰ���̣߳�timeTicker.elapsedTime()�Ľ��Ӧ�ýӽ�0����
	DebugL << "async task time1:" <<  timeTicker->elapsedTime() << "ms" << endl;
	sleep(1);
	
	//��ʱӦ�������˼��̵�ʱ�䣬��û��������ǰ���̣߳�timeTicker.elapsedTime()�Ľ��Ӧ�ýӽ�0����
	DebugL << "async task time2:" <<  timeTicker->elapsedTime() << "ms" << endl;
	
	delete timeTicker;

	SmoothTicker smoothTicker;
	DebugL << "start smoothTicker task"<< endl;
	sleep(1);
	DebugL << "async smoothTicker time1:" <<  smoothTicker.elapsedTime() << "ms" << endl;
	sleep(3);
	DebugL << "async smoothTicker time2:" <<  smoothTicker.elapsedTime() << "ms" << endl;
	sleep(2);
	DebugL << "async smoothTicker time3:" <<  smoothTicker.elapsedTime() << "ms" << endl;
	Logger::Destory();
	return 0;
}
