#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <vector>
#include <algorithm>

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};




template<typename Object>
class MyPriorityQueue
{
private:
	// fill in private member data here
	std::vector<Object> elemArray;

public:

	MyPriorityQueue();

	~MyPriorityQueue();

 	size_t size() const noexcept;

	bool isEmpty() const noexcept;

	void insert(const Object & elem);

	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 

	void extractMin(); 

};

template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue()
{
}

template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue()
{
}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return elemArray.size();
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	return elemArray.size() == 0;
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{

	elemArray.push_back(elem);

	unsigned int currentIndex = elemArray.size() - 1;

	if (currentIndex == 0)
	{
		return;
	}

	// unsigned int parentIndex = (currentIndex - 1) / 2;

	// while (elemArray.at(parentIndex) < elemArray.at(currentIndex))
	// {
	// 	Object currentElem = elem;
	// 	elemArray.at(currentIndex) = elemArray.at(parentIndex);
	// 	elemArray.at(parentIndex) = currentElem;

	// 	currentIndex = parentIndex;
	// 	parentIndex = (currentIndex - 1) / 2;
	// }

	while (currentIndex > 0)
	{
		unsigned int parentIndex = (currentIndex - 1) / 2;
		if (elemArray.at(parentIndex) < elemArray.at(currentIndex))
		{
			return;
		}
		else
		{
			// Object currentElem = elem;
			// elemArray.at(currentIndex) = elemArray.at(parentIndex);
			// elemArray.at(parentIndex) = currentElem;

			std::iter_swap(elemArray.begin() + currentIndex, elemArray.begin() + parentIndex);

			currentIndex = parentIndex;
		}
	}
}

template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	return elemArray.at(0);
}

template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	elemArray.at(0) = elemArray.at(elemArray.size() - 1);
	elemArray.pop_back();

	if (elemArray.size() == 1)
	{
		return;
	}

	unsigned int currentIndex = 0;

	while (currentIndex < elemArray.size())
	{
		unsigned int childIndex = 2 * currentIndex + 1;

		if (childIndex >= elemArray.size())
		{
			return;
		}
		else if (childIndex + 1 >= elemArray.size())
		{
			if (elemArray.at(childIndex) < elemArray.at(currentIndex))
			{
				// Object currentElem = elemArray.at(currentIndex);
				// elemArray.at(currentIndex) = elemArray.at(childIndex);
				// elemArray.at(childIndex) = currentElem;
				std::iter_swap(elemArray.begin() + currentIndex, elemArray.begin() + childIndex);
			}

		}
		else
		{
			// Object currentElem = elemArray.at(currentIndex);

			Object currentElem = elemArray.at(currentIndex);
			unsigned int minIndex = -1;

			if (elemArray.at(childIndex) < elemArray.at(childIndex + 1))
			{
				if (elemArray.at(childIndex) < currentElem)
				{
					minIndex = childIndex;					
				}

			}
			else
			{
				if (elemArray.at(childIndex + 1) < currentElem)
				{
					minIndex = childIndex + 1;
				}
			}
			
			if (minIndex != -1)
			{
				std::iter_swap(elemArray.begin() + currentIndex, elemArray.begin() + minIndex);
			}
		}
		currentIndex = childIndex;

	}	
}


#endif 
