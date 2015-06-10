#pragma once

template<typename T>
class DynArray
{
public:

	DynArray()
	{
	}

	explicit DynArray(size_t sz)
	{
	}

	~DynArray()
	{
	}
private:
	T **p;
	size_t n;
};

