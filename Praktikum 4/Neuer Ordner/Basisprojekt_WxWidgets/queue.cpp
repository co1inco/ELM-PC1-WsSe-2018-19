#include <iostream>

#include "queue.h"

//#define QUEUE_LENGTH (15)

using namespace std;

Queue::Queue(){
	currentFirst = 0;
	currentLast = 0;
	
	emty = true;
	size = 0;
}
Queue::Queue(const Queue& a){
	currentLast = a.currentLast;
	currentFirst = a.currentFirst;
	
	int i;
	for (i=0; i<=QUEUE_LENGTH; i++){
		queueList[i] = a.queueList[i];
	}
}

Queue::~Queue(){
	
}

void Queue::increase(int *i){
	if (*i == QUEUE_LENGTH)
		*i = 0;
	else
		*i = *i + 1;
	
	emty = Queue::isEmty();
	size = Queue::getCount();
}

int Queue::getCount(){
	if (Queue::isEmty() == false){
		if (currentFirst < currentLast)
			return ((QUEUE_LENGTH - currentLast) + currentFirst + 1);
		else
			return (currentFirst - currentLast);
	} else 
		return 0;
}

bool Queue::isEmty(){
	if (currentFirst == currentLast)
		return true;
	return false;
}

bool Queue::isFull(){
	if (currentFirst+1 == currentLast)
		return true;
	else if  ((currentFirst == QUEUE_LENGTH) && currentLast == 0)
		return true;
	return false;
}

bool Queue::addItem(int item){
	if (Queue::isFull() == false){
		queueList[currentFirst] = item;
		Queue::increase(&currentFirst);
		return true;
	}
	return false;
}

bool Queue::getItem(int *item){
	if (Queue::isEmty() == false){
		*item = queueList[currentLast];
		queueList[currentLast] = -1;
		Queue::increase(&currentLast);
		return true;
	}
	return false;
}

void Queue::printQueueDebug(){
	cout << "---Debug Queue---" << "\n";
	cout << "Max: Indx: (" << QUEUE_LENGTH << ") " << QUEUE_LENGTH + 1 << "\n";
	cout << "Next  Add: " << currentFirst << "(First)\n";
	cout << "Next  Get: " << currentLast << "(Last)\n";
	cout << "ItemCount: " << Queue::getCount() << "\n";
	cout << "ItemSum  : " << Queue::getSum() << "\n";
	cout << "---Queue Start---" << "\n";
	
	// indication for currentFirst / currentLast
	
	if (Queue::isEmty() == false){
		int i;
		for (i=0; i<=QUEUE_LENGTH; i++){
			cout << "Index: " << i << " | " << queueList[i] << "\n";
		}
 	} else
		cout << "Emty\n";
	cout << "---Queue End---" << "\n";
}

void Queue::clear(){
	int i;
	for (i=0; i<=QUEUE_LENGTH; i++){
		queueList[i] = -1;
	}
	currentFirst = 0;
	currentLast = 0;
}

void Queue::printQueue(){
	int q[QUEUE_LENGTH];
	int size = Queue::getQueue(q);
	int i;
	for (i=0; i<size; i++){
		cout << "Index: " << i << " | " << q[i] << "\n";
	}
}

int Queue::getQueue(int *array){
	if (Queue::isEmty() == false){
		int i = currentLast;
		int j = 0;
		if (currentFirst<currentLast){
			for (; (i<=QUEUE_LENGTH); i++){
				array[j] = queueList[i];
				j++;
			}
			for (i=0; i<currentFirst; i++){
				array[j] = queueList[i];
				j++;
			}
		} else {
			for (; (i<currentFirst); i++){
				array[j] = queueList[i];
				j++;
			}
		}
	}
	return Queue::getCount();
}

int Queue::getQueueClear(int *array){
	int tmp = Queue::getQueue(array);
	Queue::clear();
	return tmp;
}

int Queue::getSum()
{
	int sum = 0;
	if (Queue::isEmty() == false){
		int i;
		int array[QUEUE_LENGTH];
		int size = Queue::getQueue(array);
		for (i=0; i<size; i++){
			sum = sum + array[i];
		}
	}
	return sum;
}

std::ostream& operator<< (std::ostream &os, const Queue &queue)
{  
	if (queue.emty == false){
		int i = queue.currentLast;
		if (queue.currentFirst<queue.currentLast){
			for (; (i<=QUEUE_LENGTH); i++){
				os << queue.queueList[i] << "\n";
			}
			for (i=0; i<queue.currentFirst; i++){
				os << queue.queueList[i] << "\n";
			}
		} else {
			for (; (i<queue.currentFirst); i++){
				os << queue.queueList[i] << "\n";
			}
		}
	}

    return os;  
}  






