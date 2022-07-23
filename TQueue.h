#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "ExceptionQueueIsFull.h"
#include "ExceptionQueueIsEmpty.h"

using namespace std;

template <class T>
class TQueue
{
private:
    unique_ptr<T[]> head;
    int maxSize;
    int currentSize;

public:

    /*** CONSTRUCTOR & DESTRUCTOR ***/

    TQueue(int maxSize);
    TQueue(TQueue &source);
    TQueue(TQueue &&source) noexcept;
    ~TQueue();

    /*** MUTATORS ***/

    TQueue &operator=(TQueue &source);
    TQueue &operator=(TQueue &&source) noexcept;

    void enqueue(T value);
    T dequeue();

    /*** ACCESSORS ***/

    T front() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    void printQueue() const;
};

/*************************************************************************
* Method TQueue: Class TQueue
*------------------------------------------------------------------------
* This function is the default constructor
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		maxSize: the max size of the array

* POST-CONDITIONS
* 		initialized: maxSize, currentSize, head
*************************************************************************/
template <class T>
TQueue<T>::TQueue(int maxSize) : maxSize(maxSize), currentSize(0), head(make_unique<T[]>(maxSize))
{
}

/*************************************************************************
* Method TQueue: Class TQueue
*------------------------------------------------------------------------
* This function is the copy constructor
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		&source: the object that will be copy

* POST-CONDITIONS
* 		will copy the object passed in into new object
*************************************************************************/
template <class T>
TQueue<T>::TQueue(TQueue &source) : maxSize(source.maxSize), currentSize(source.currentSize), head(make_unique<T[]>(source.maxSize))
{
    for (int i = 0; i < source.currentSize; i++)
    {
        head[i] = source.head[i];
    }
}

/*************************************************************************
* Method TQueue: Class TQueue
*------------------------------------------------------------------------
* This function is the move constructor
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		&source: the object that will be move
*
* POST-CONDITIONS
* 		will move the object passed in into new object
*************************************************************************/
template <class T>
TQueue<T>::TQueue(TQueue &&source) noexcept : maxSize(source.maxSize), currentSize(source.currentSize), head(move(source.head))
{
    source.maxSize = 0;
    source.currentSize = 0;
    source.head = nullptr;
}

/*************************************************************************
* Method ~TQueue: Class TQueue
*------------------------------------------------------------------------
* This function is the destructor
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		none
*
* POST-CONDITIONS
* 		will delete the object
*************************************************************************/
template <class T>
TQueue<T>::~TQueue()
{
}

/*************************************************************************
* Method operator= copy: Class TQueue
*------------------------------------------------------------------------
* This function overload the assignment operator
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		TQueue &source: the object being copy
*
* POST-CONDITIONS
* 		*this: the new object after copy
*************************************************************************/
template <class T>
TQueue<T> &TQueue<T>::operator=(TQueue &source)
{
    if (this != &source)
    {
        maxSize = source.maxSize;
        currentSize = source.currentSize;
        head = make_unique<T[]>(source.maxSize);
        for (int i = 0; i < source.currentSize; i++)
        {
            head[i] = source.head[i];
        }
    }
    return *this;
}

/*************************************************************************
* Method operator= move: Class TQueue
*------------------------------------------------------------------------
* This function overload the assignment operator
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		TQueue &source: the object being move
*
* POST-CONDITIONS
* 		*this: the new object after move
*************************************************************************/
template <class T>
TQueue<T> &TQueue<T>::operator=(TQueue &&source) noexcept
{
    if (this != &source)
    {
        maxSize = source.maxSize;
        currentSize = source.currentSize;
        head = move(source.head);
        source.maxSize = 0;
        source.currentSize = 0;
        source.head = nullptr;
    }
    return *this;
}

/*************************************************************************
* Method enqueue: Class TQueue
*------------------------------------------------------------------------
* This function will add a value to the end of the queue
*------------------------------------------------------------------------
* PRE-CONDITIONS
* 		value: the value to be added
*
* POST-CONDITIONS
* 		will add the value to the end of the queue
*************************************************************************/
template <class T>
void TQueue<T>::enqueue(T value)
{
    if (currentSize == maxSize)
    {
		throw ExceptionQueueIsFull();
    }
    else
    {
        head[currentSize] = value;
        currentSize++;
    }
}

/*************************************************************************
* Method dequeue: Class TQueue
*------------------------------------------------------------------------
* This function will remove a value from the front of the queue
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will remove the value from the front of the queue
*************************************************************************/
template <class T>
T TQueue<T>::dequeue()
{
    if (currentSize == 0)
    {
		throw ExceptionQueueIsEmpty();
    }
    else
    {
        T value = head[0];
        for (int i = 0; i < currentSize - 1; i++)
        {
            head[i] = head[i + 1];
        }
        currentSize--;
        return value;
    }
}


/*************************************************************************
* Method front: Class TQueue
*------------------------------------------------------------------------
* This function will return the value at the front of the queue
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will return the value at the front of the queue
*************************************************************************/
template <class T>
T TQueue<T>::front() const
{
    if (currentSize == 0)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        return head[0];
    }
}

/*************************************************************************
* Method size: Class TQueue
*------------------------------------------------------------------------
* This function will return the current size of the queue
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will return the size of the queue
*************************************************************************/
template <class T>
int TQueue<T>::size() const
{
    return currentSize;
}

/*************************************************************************
* Method isEmpty: Class TQueue
*------------------------------------------------------------------------
* This function will return true if the queue is empty
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will return true if the queue is empty
*************************************************************************/
template <class T>
bool TQueue<T>::isEmpty() const
{
    return currentSize == 0;
}

/*************************************************************************
* Method isFull: Class TQueue
*------------------------------------------------------------------------
* This function will return true if the queue is full
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will return true if the queue is full
*************************************************************************/
template <class T>
bool TQueue<T>::isFull() const
{
    return currentSize == maxSize;
}

/*************************************************************************
* Method printQueue: Class TQueue
*------------------------------------------------------------------------
* This function will print the queue
*------------------------------------------------------------------------
* PRE-CONDITIONS
*       none
*
* POST-CONDITIONS
*       will print the queue
*************************************************************************/
template <class T>
void TQueue<T>::printQueue() const
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << head[i] << " ";
    }
    cout << endl;
}