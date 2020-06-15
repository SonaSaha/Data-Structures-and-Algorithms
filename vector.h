#pragma once
#include "pch.h"
#include <iostream>
#include <memory>

template <class T>

class vector
{
public:
	typedef T                                             value_type;
	typedef T&                                   reference;
	typedef const T&                             const_reference;
	typedef int                                           size_type;
	typedef std::ptrdiff_t                                difference_type;
	typedef	T*                                            pointer;
	typedef const T*                                      const_pointer;
	typedef T*                                            iterator;
	typedef const T*                                      const_iterator;
	typedef std::reverse_iterator<iterator>               reverse_iterator;
	typedef std::reverse_iterator<const_iterator>         const_reverse_iterator;

public:
	//constructors
	vector() :size_(0), capacity_(1), ptr(new T()) {};
	vector(size_type n);
	explicit vector(size_type count, const T& value);
	/*template< class InputIt >
	vector(iterator first, iterator last) :
		size_(last - first - 1),
		capacity(last - first),
		ptr(new T[capacity])
	{
		pointer ptr1 = ptr;
		iterator cur_first = first;
		while (first != last)
		{
			*ptr1 = *first;  //???
			++first;
			++ptr1;
		}
		ptr1 = nullptr;
	}
	*/
	vector(const vector& other);
	vector(std::initializer_list<T> init);
	~vector()
	{
		delete[] ptr;
		ptr = nullptr;
	}
	void swap(vector& other)
	{
		std::swap(this->size(), other.size());
		std::swap(this->ptr, &other);
	}
	vector& operator=(const vector& other)
	{
		vector temp(other);
		this->swap(temp);
	}
	vector& operator=(std::initializer_list<T> ilist)
	{

		vector temp(ilist);
		*this = temp;
	}
	void assign(size_type count, const T& value);
	///*template< class InputIt >
	void assign(iterator first, iterator last)
	{
		delete[]ptr;
		ptr = nullptr;
		size_ = last - first - 1;
		capacity_ = last - first;
		ptr = new T[capacity_];
		pointer ptr1 = ptr;
		auto cur_first = first;
		while (cur_first != last)
		{
			*ptr1 = *cur_first;  //??
			++cur_first;
			++ptr1;
		}
		ptr1 = nullptr;
	}
	const_reference at(size_type pos) const;
	const_reference operator[](size_type index) const
	{
		return *(ptr + index);
	}
	const_reference front() const;
	const_reference back() const;
	const_pointer data() const noexcept;
	iterator begin()  
	{
		return ptr;
	}
	const_iterator begin() const noexcept
	{
		return ptr;
	}
	const_iterator cbegin()  const noexcept
	{
		return ptr;
	}
	reverse_iterator rbegin() const noexcept
	{
		return reverse_iterator(ptr.begin()).begin();
	}
	const_reverse_iterator crbegin() const  noexcept
	{
		return reverse_iterator(ptr.begin()).cbegin();
	}
	iterator end() const noexcept
	{
		return ptr + size_;
	}
	const_iterator end() 
	{
		return ptr + size_;
	}
	const_iterator cend() const noexcept
	{
		return ptr + size_;
	}
	reverse_iterator rend() noexcept
	{
		return reverse_iterator(ptr.begin()).end();
	}
	const_reverse_iterator rend() const noexcept
	{
		return reverse_iterator(ptr.cbegin()).cend();
	}
	const_reverse_iterator crend() const noexcept
	{
		return reverse_iterator(ptr.cbegin()).cend();
	}
	bool empty() const noexcept
	{
		return size_ == 0;
	}
	size_type size() const { return size_; };
	void reserve(size_type new_cap);
	size_type capacity() const noexcept
	{
		return capacity_ - 1;
	}
	void shrink_to_fit()
	{
		capacity_ = size_ + 1;
	}
	void clear() noexcept
	{
		delete[]ptr;
		size_ = 0;
		ptr = new T(capacity_);
	}
	iterator insert(const_iterator pos, const T& value);
	//iterator erase(const_iterator pos);
	void push_back( const T& value );

private:
	size_type size_;
	size_type capacity_;
	pointer ptr;
};