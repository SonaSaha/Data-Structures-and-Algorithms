#include "pch.h"
#include "vector.h"
template <class T>
vector<T>::vector(vector<T>::size_type n) :size_(n), capacity_(n + 1), ptr(new T[n + 1])
{
	pointer ptr1 = ptr;
	for (size_type i = 1; i <= n; ++i)
	{
		*ptr1 = 0;
		++ptr1;
	}
}
template <class T>
vector<T>::vector(size_type count, const T& value) :
	size_(count),
	capacity_(count + 1),
	ptr(new T[capacity_])
{
	pointer ptr1 = ptr;
	for (size_type i = 1; i <= count; ++i)
	{
		*ptr1 = value;
		++ptr1;
	}
	ptr1 = nullptr;
}
template <class T>
vector<T>::vector(const vector& other) :
	size_(other.size()),
	capacity_(other.size() + 1),
	ptr(new T[capacity_])
{
	try
	{
		for (int i = 0; i < size_; ++i)
		{
			*(ptr + i) = other[i];
		}
	}
	catch (std::exception& e)
	{
		std::cout << "std::exception caught " << e.what();
	}
}
template <class T>
vector<T>::vector(std::initializer_list<T> init) :
	size_(init.size()),
	capacity_(init.size() + 1),
	ptr(new T[capacity_])
{
	try
	{
		int i = 0;
		auto init_first = init.begin();
		auto init_last = init.end();
		while (init_first != init_last)
		{
			*(ptr + i) = *init_first;
			++i;
			++init_first;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "std::exception caught " << e.what();
	}
}
template <class T>
void vector<T>::assign(size_type count, const T& value)
{
	delete[]ptr;
	size_ = count;
	capacity_ = count + 1;
	ptr = new T[capacity_];
	pointer ptr1 = ptr;
	for (int i = 0; i < count; ++i)
	{
		*(ptr1 + i) = value;
	}
	ptr1 = nullptr;
}
template <class T>
vector<T>::const_reference vector<T>::at(vector<T>::size_type pos) const
{
	if (pos < 0 || pos >= size_)
	{
		throw std::exception("attempt to access out of range");
	}
	return *(ptr + pos);
}
template <class T>
vector<T>::const_reference vector<T>::front() const
{
	if (size_ == 0)
	{
		throw std::exception("vector is empty");
	}
	return this->cbegin();
}
template <class T>
vector<T>::const_reference vector<T>::back() const
{
	if (size_ == 0)
	{
		throw std::exception("vector is empty");
	}
	auto tmp = this->cend();
	--tmp;
	return *tmp;
}
template <class T>
vector<T>::const_pointer vector<T>::data() const noexcept
{
	if (size_ == 0)
	{
		return this->cend();
	}
	return this->cbegin();
}
template <class T>
void vector<T>::reserve(vector<T>::size_type new_cap)
{
	if (capacity_ < new_cap)
	{
		pointer temp = new T[new_cap];
		for (int i = 0; i < size_; ++i)
		{
			*(temp + i) = *(ptr + i);
		}
		ptr = temp;
		temp = nullptr;
	}
}
template <class T>
vector<T>::iterator vector<T>::insert(vector<T>::const_iterator pos, const T& value)
{
	iterator it = begin();
	int i = 0;
	if (size_ + 1 == capacity_)
	{
		capacity_ = 2 * (size_ + 1) + 1;
		pointer temp = new T[capacity_];
		it = begin();
		while (it != end())
		{
			*(temp + i) = *(ptr + i);
			++i;
			++it;
		}
		ptr = temp;
		temp = nullptr;
	}
	it = end();
	auto it1 = end() - 1;
	while (it1 != pos)
	{
		*it = *it1;
		--it;
		--it1;
	}
	*it = *it1;
	*pos = value;
	return pos;
}
/*
template <class T>
vector<T>::iterator vector<T>::erase(vector<T>::const_iterator pos)
{
	if (pos == end())
	{
		throw std::exception("invalid pos");
	}
	auto it = pos;
	auto it1 = pos + 1;
	while (it1 != end())
	{
		*it = *it1;
	}
	delete it1;

}
*/
template <class T>
void vector<T>::push_back(const T& value)
{
	if (size_ + 1 == capacity_)
	{
		int i = 0;
		capacity_ = 2 * (size_ + 1) + 1;
		pointer temp = new T[capacity_];
		auto it = begin();
		while (it != end())
		{
			*(temp + i) = *(ptr + i);
			++i;
			++it;
		}
		ptr = temp;
		temp = nullptr;
	}
	*(ptr + size_) = value;
}