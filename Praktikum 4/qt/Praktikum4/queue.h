
#define QUEUE_LENGTH (50) //>20 can result in problems. Try compile it as release

#include <iostream>

class Queue
{

public:
	Queue();
	~Queue();

public:
	void increase(int *i);
	int  getCount();
	bool isEmty();
	bool isFull();
	bool addItem(int item);
	bool getItem(int *item);
	int getSum();
	
	int  getQueue(int *array);
	int  getQueueClear(int *array);
	void printQueue();

	void printQueueDebug();
	void clear();
	
	friend std::ostream& operator<< (std::ostream &os, const Queue &queue);  
	
/*
	bool qu_in(int item);
	bool qu_out(int * item);
	bool is_qu_emty();
	void loesche_qu();
	int gib_anz();
	int gib_sum();
*/

private:
    int *queueList = new int[QUEUE_LENGTH+1];
	int currentFirst;
	int currentLast;
	
	bool emty;
	int size;
		
};




