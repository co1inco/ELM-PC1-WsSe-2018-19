#define QUEUE_LENGTH (15)

class Queue
{

public:
	Queue();

public:
	void increase(int *i);
	int  getCount();
	bool isEmty();
	bool isFull();
	bool addItem(int item);
	bool getItem(int *item);
	void printQueue();

private:
	int queueList[QUEUE_LENGTH+1];
	int currentFirst;
	int currentLast;
		
};


