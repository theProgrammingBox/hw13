/*************************************************************************
 * AUTHOR     	  : Justin Gea
 * Assignment #12 : Templates (Queues)
 * CLASS      	  : CS 1C
 * SECTION    	  : MTWTTH 03:00pm - 05:35pm
 * DUE DATE   	  : 07/22/2022
 *************************************************************************/

#include "TQueue.h"

/**********************************************************
 *
 * Templates (Queues)
 *_________________________________________________________
 * This program will demonstrate the use of templates
 * through the use of a dynamic queue. It will
 * also demonstrate the class methods.
 *_________________________________________________________
 * INPUT:
 *    	none
 *
 * OUTPUT:
 *   	The program will output the dynamic queue
 ***********************************************************/

int main()
{
	TQueue<int> myQueue(1);

	cout << "Adding 1 to the queue of size 1" << endl;
	try
	{
		myQueue.enqueue(1);
	}
	catch (ExceptionQueueIsFull e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	cout << "Adding 2 to the queue of size 1" << endl;
	try
	{
		myQueue.enqueue(2);
	}
	catch (ExceptionQueueIsFull e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	cout << "Dequeuing the queue of size 1" << endl;
	try
	{
		myQueue.dequeue();
	}
	catch (ExceptionQueueIsEmpty e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	cout << "Dequeuing the queue of size 1" << endl;
	try
	{
		myQueue.dequeue();
	}
	catch (ExceptionQueueIsEmpty e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	assert(myQueue.isEmpty() == false);
	assert(myQueue.isEmpty() == true);

    return 0;
}