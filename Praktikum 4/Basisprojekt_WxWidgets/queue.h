#define QUEUE_LENGTH (15)

#include <iostream>

class Queue
{

public:
	Queue();
	Queue(const Queue& a);
	~Queue();
/*
	int queueList[QUEUE_LENGTH+1];
	int currentFirst;
	int currentLast;
*/	
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
	

	void qu_in(int item){
		addItem(item);
	}
	int qu_out(){
		int x = 0;
		getItem(&x);
		return x;
	}
	bool is_qu_emty(){
		return isEmty(); 
	}
	void loesche_qu(){
		clear();
	}
	int gib_anz(){
		return getCount();
	}
	int gib_sum(){
		return getSum();
	}


private:
	int queueList[QUEUE_LENGTH+1];
	int currentFirst;
	int currentLast;
	
	bool emty;
	int size;
		
};




