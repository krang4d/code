#pragma once

template<typename T>
class DynArray
{
public:
	class IndexOutOfRange
	{};
	size_t Size()const
	{ return n; }

	T & operator[](size_t i);
	void Add(const T &t);
	void Add(const T *t)
	{
		Add(*t);
	}

	DynArray():p(0), sz(0), n(0)
	{}

	explicit DynArray(size_t s)
		:p(new T[s]), sz(s), n(0)
	{}

	~DynArray()
	{
		delete[] p;
	}
private:
	T *p;
	size_t sz, n;
};

template<typename T>
T & DynArray<T>::operator[](size_t i)
{
	if (0 <= i && i < n) return p[i];
	throw IndexOutOfRange();
}

template<typename T>
void DynArray<T>::Add(const T &t)
{
	if (n == sz)
	{
		size_t s = sz ? 2 * sz : 1;
		//if (!s) s = 1;
		T *pp = new T[s];
		if (p)
		{
			for (size_t i = 0; i < n; ++i) pp[i] = p[i];
			delete[] p;
		}
		p = pp; sz = s;
	}
	p[n++] = t;
}
