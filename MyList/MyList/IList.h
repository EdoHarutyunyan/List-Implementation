#pragma once

template<class T>
class IList
{

public:
	virtual  ~IList() = default;

	virtual void clear() = 0;

	virtual bool empty() const = 0;

	virtual size_t size() const = 0;

	virtual void erase(const size_t& pos) = 0;

	virtual void insert(const T& data, const size_t pos) = 0;

};
