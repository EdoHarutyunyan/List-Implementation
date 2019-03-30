#pragma once
#include "IList.h"
#include <cassert>

namespace list
{

template<class T>
class List : public IList<T>
{
public:
	List();
	~List() override;

	struct Node
	{
		Node(const T& data = T(), Node* pNext = nullptr)
			: m_data(data)
			, m_pNext(pNext)
		{
		}

		T m_data;
		Node* m_pNext;
	};

	void clear() override;
	bool empty() const override;
	size_t size() const override;
	void erase(const size_t& pos) override;
	void insert(const T& data, const size_t pos) override;

private:
	Node* m_head;
	size_t m_size;
};

template<class T>
List<T>::List()
	: m_head(nullptr)
	, m_size(0)
{
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
bool List<T>::empty() const
{
	return (m_size == 0);
}

template<class T>
size_t List<T>::size() const
{
	return m_size;
}

template<class T>
void List<T>::insert(const T & data, const size_t pos)
{
	assert(pos > 0);

	Node* newNode = nullptr;
	Node* current = m_head;

	if (pos > m_size + 1)
	{
		throw("Invalid size.");
	}
	if (pos == 1)
	{
		m_head = new Node(data, m_head);
		++m_size;
		return;
	}

	for (size_t i = 1; i < pos - 1; ++i)
	{
		current = current->m_pNext;
	}

	newNode = new Node(data, current->m_pNext);
	current->m_pNext = newNode;

	++m_size;
}

template<class T>
void List<T>::erase(const size_t & pos)
{
	assert(pos > 0);

	Node* nodeToDelete = nullptr;
	Node* current = m_head;

	if (pos > m_size)
	{
		throw("You want to remove something outside of list range.");
	}
	if (pos == 1)
	{
		delete m_head;
		m_head = nullptr;
		--m_size;
		return;
	}

	for (size_t i = 1; i < pos - 1; ++i)
	{
		current = current->m_pNext;
	}

	nodeToDelete = current->m_pNext;
	current->m_pNext = nodeToDelete->m_pNext;

	delete nodeToDelete;
	nodeToDelete = nullptr;

	--m_size;
}

template<class T>
void List<T>::clear()
{
	Node* current = m_head;
	Node* nodeToDelete = nullptr;

	for (size_t i = 1; i < size() + 1; ++i)
	{
		nodeToDelete = current;
		current = current->m_pNext;

		delete nodeToDelete;
		nodeToDelete = nullptr;
	}

	nodeToDelete = nullptr;
	m_head = nullptr;
	m_size = 0;
}

}//namespace list
