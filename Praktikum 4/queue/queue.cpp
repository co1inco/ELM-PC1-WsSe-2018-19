#include <iostream>

#include "queue.h"

#define QUEUE_LENGTH (15)

using namespace std;

Queue::Queue(){
	currentFirst = 0;
	currentLast = 0;
}

void Queue::increase(int *i){
	if (*i == QUEUE_LENGTH)
		*i = 0;
	else
		*i = *i + 1;
}

int Queue::getCount(){
	if (Queue::isEmty() == false){
		if (currentFirst < currentLast)
			return ((QUEUE_LENGTH - currentLast) + currentFirst);
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

void Queue::printQueue(){
	cout << "---Debug Queue---";
	cout << "Max: Indx: (" << QUEUE_LENGTH << ") " << QUEUE_LENGTH + 1 << "\n";
	cout << "Next  Add: " << currentFirst << "\n";
	cout << "Next  Get: " << currentLast << "\n";
	cout << "ItemCount: " << Queue::getCount() << "\n";
	cout << "---Queue Start---" << "\n";
	
	if (Queue::isEmty() == false){
		int i;
		for (i=0; i<=QUEUE_LENGTH; i++){
			cout << "Index: " << i << " | " << queueList[i] << "\n";
		}
 	} else
		cout << "Emty\n";
}



int main(){
	
	Queue *q = new Queue();	
	
	int i;
	for (i=0; i<=QUEUE_LENGTH; i++){
		q->addItem(i+1);
	}
	
	int tmp;
	q->printQueue();
	cout << q->addItem(30) << "\n";
	cout << "Get " << q->getItem(&tmp) << "\n";
	cout << "Get " << q->getItem(&tmp) << "\n";
	q->printQueue();
	cout << q->addItem(31) << "\n";
	cout << q->addItem(32) << "\n";
	cout << q->addItem(33) << "\n";
	q->printQueue();	
	
}






