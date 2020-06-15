#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
//#include <functional>
#include "vector.h"
//#include <vector>
#include <deque>
#include <memory>

int main()
{
	{
		vector<int> v;
		if (v.size() == 0)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector() is bad constructed\n";
		}
	}
	{
		vector<int> v(3);
		if (v[0] == 0 && v[1] == 0)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector(size_type n) is bad constructed\n";
		}
	}
	{
		vector<int> v(3, 5);
		if (v[0] == 5 && v[2] == 5)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector(size_type n,const T& value) is bad constructed\n";
		}
	}

	/*{
		std::deque<int> v(3, 5);
		auto it_first = v.begin();
		auto it_last = v.end();
		vector<int> v1(it_first, it_last);
		std::cout << v1[2];
		if (v1[0] == 5 && v1[2] == 5)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) is bad constructed\n";
		}

	}
	*/
	{
		vector<int> v1(3, 5);
		vector<int> v(v1);
		if (v[0] == 5 && v[2] == 5)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector(size_type n,const T& value) is bad constructed\n";
		}
	}

	{
		vector<int> v({ 1,2,3,5,8 });
		if (v[0] == 1 && v[4] == 8)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "vector(std::initializer_list<T> init,const Allocator& alloc = Allocator()) is bad constructed\n";
		}
	}
	{
		vector<int> v1(3, 2);
		vector<int> v = v1;
		if (v[0] == 2 && v[2] == 2)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "operator= is bad constructed\n";
		}
	}

	{
		vector<int> v = { 1,2,6,5,8 };
		if (v[0] == 1 && v[4] == 8)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "operator=(std::initializer_list<T> ilist) is bad constructed\n";
		}
	}
	{
		vector<int> v(2, 5);
		v.assign(3, 7);
		if (v[0] == 7 && v[2] == 7)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "member function assign is bad constructed";
		}
	}
	/*{
		vector<int> v1(2, 5);
		vector<int> v;
		v.assign(v1.begin(), v1.end());
		if (v[0] == 5 && v[1] == 5)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "member function assign is bad constructed";
		}
	}
	*/
	{
		vector<int> v(2, 5);

		if (v.at(0) == 5 && v.at(1) == 5)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "at is bad constructed";
		}
		try
		{
			std::cout << v.at(3);
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
	{
		vector<int> v;
		try
		{
			std::cout << v.front();
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
	{
		vector<int> v;
		try
		{
			std::cout << v.back();
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
	{
		vector<int> v;
		try
		{
			std::cout << v.data();
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
/*	{
		vector<int> v(3, 2);
		vector<int> v1;
		if (*v.begin() == 2 && *v.cbegin() == 2 && v1.begin() == v1.end())
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "iterators functions is bad constructed";
		}
	}
	*/
}
