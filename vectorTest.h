#pragma once
#include <iostream>
#include <memory>
#include <exception>
#include <stdexcept>
#include <algorithm>

template <class T, class Allocator = std::allocator<T>>

class vector
{
public:
	typedef T                                             value_type;
	typedef value_type&                                   reference;
	typedef const value_type&                             const_reference;
	typedef const value_type&                             const_reference;
	//typedef /*implementation-defined*/                  iterator;
	//typedef /*implementation-defined*/                  const_iterator;
	//typedef /*implementation-defined*/                  size_type;
	//typedef /*implementation-defined*/                  difference_type;
	typedef std::size_t                                   size_type;
	typedef std::ptrdiff_t                                difference_type;
	typedef Allocator                                     allocator_type;
	//typedef typename std::allocator_traits<Allocator>::pointer     pointer;
	typedef	T*                                            pointer;
	//typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
	//typedef Allocator::const_pointer                      const_pointer;
	typedef const T*                                      const_pointer;
	typedef T*                                            iterator;
	typedef const T*                                      const_iterator;
	typedef std::reverse_iterator<iterator>               reverse_iterator;
	typedef std::reverse_iterator<const_iterator>         const_reverse_iterator;

public:
	//constructors
	vector() :size_(0), capacity(1), ptr(nullptr)
	{
		allocator_type alloc;
		ptr = alloc.allocate(1);
	}
	//explicit vector(const allocator_type& alloc) :vector() {};//???
	explicit vector(const allocator_type& alloc) noexcept {};//???
	explicit vector(size_type count, const T& value /*, const allocator_type& alloc = allocator_type()*/) :
		size_(count),
		capacity(count + 1)
	{
		allocator_type alloc;
		ptr = alloc.allocate(count + 1);
		pointer ptr1 = ptr;
		for (size_type i = 1; i <= count; ++i)
		{
			alloc.construct(ptr1, value);
			++ptr1;
		}
		ptr1 = nullptr;
	}
	/*
	explicit vector(size_type n) :
		vector(n,value_type()){}

	*/
	explicit vector(size_type count, const Allocator& alloc = Allocator()) :     //???
		vector(count, value_type()) {}
	/*
	template< class InputIt >
	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
		size_(last - first - 1),
		capacity(last - first)
	{
		allocator_type allocator;
		ptr = allocator.allocate(last - first);
		pointer ptr1 = ptr;
		InputIt cur_first = first;
		while (cur_first != last)
		{
			allocator.construct(ptr1, *cur_first);    /////???
			++cur_first;
			++ptr1;
		}
		ptr1 = nullptr;
	}
	*/
	vector(const vector& other, const Allocator& alloc) :
		size_(other.size()),
		capacity(other.size() + 1),
		ptr(alloc.allocate(capacity))
		///std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())???
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
	/*
	vector(vector&& other) noexcept;
	vector(vector&& other, const Allocator& alloc);
	*/
	vector(std::initializer_list<T> init/*,const Allocator& alloc = Allocator()*/) : ///???
		size_(init.size()),
		capacity(init.size() + 1)
	{
		try
		{
			allocator_type allocator;
			ptr = allocator.allocate(capacity);
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
	//****DESTRUCTOR****
	 ~vector()   //constexpr ???
	{
		allocator_type allocator;
		allocator.deallocate(ptr, capacity);
		ptr = nullptr;  //??is this required?
	}
	 //****OPERATOR = ****
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
	 //vector& operator=(vector&& other) noexcept
	/*vector& operator=(std::initializer_list<T> ilist) 
	 {
		 
		 //vector temp(ilist);
		 //*this = temp;
		 
		 auto first = ilist.begin();
		 auto last = ilist.end();
		 int i = 0;
		 while (first != last)
		 {
			 *(ptr + i) = *(first + i);
			 ++i;
		 }
	 }
	*/
	 void assign(size_type count, const T& value)
	 {
		 allocator_type alloc;
		 alloc.deallocate(ptr, capacity);
		 ptr = nullptr;
		 size_ = count;
		 capacity = count + 1;
		 ptr = alloc.allocate(capacity);
		 pointer ptr1 = ptr;
		 for (size_type i = 1; i <= count; ++i)
		 {
			 alloc.construct(ptr1, value);
			 ++ptr1;
		 }
		 ptr1 = nullptr;
	 }
	 template< class InputIt >
	 void assign(InputIt first, InputIt last)
	 {
		 allocator_type alloc;
		 alloc.deallocate(ptr, capacity);
		 ptr = nullptr;
		 size_ = last - first - 1;
		 capacity = last - first;
		 ptr = alloc.allocate(capacity);
		 pointer ptr1 = ptr;
		 auto cur_first = first;
		 while(cur_first!=last)
		 {
			 alloc.construct(ptr1, *cur_first);
			 ++cur_first;
			 ++ptr1;
		 }
		 ptr1 = nullptr;
	 }
	//****ITERATORS****
	iterator begin()  const
	{
		return ptr;
	}
	iterator end() 
	{
		return ptr + size_;
	}

	//****CAPACITY****
	bool empty() const noexcept
	{
		return size_ == 0;
	}
	size_type size() const { return size_; };
	//size_type size() const noexcept { return size; };
	reference operator[](size_type index)
	{
		if (index >= capacity)
		{
			throw std::invalid_argument("index must be between 0 and size - 1");
		}
		return *(ptr + index);
	}

private:
	size_type size_;
	size_type capacity;
	pointer ptr;
};