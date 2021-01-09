#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
template<typename T>
class Vector {
public:
	/* constructor */
	Vector(size_t _cap = _DEFAULT_CAP, T val = T()) {
		_arr = new T[_cap];
		_size = _cap;
		_capacity = _cap;
		for (size_t i = 0; i < _size; i++) {
			_arr[i] = val;
		}
	}
	Vector(const Vector& rhs) {
		_arr = new T[rhs._capacity];
		_size = rhs._size;
		_capacity = rhs._capacity;
		for (size_t i = 0; i < _size; i++) {
			_arr[i] = rhs._arr[i];
		}
	}
	/* destructor */
	~Vector() { if (_arr != nullptr) delete[] _arr; }
	/* methods */
	void push_back(const T& val) {
		if (_size >= _capacity) {
			_capacity *= 2;
			T* _temp = new T[_capacity];
			for (size_t i = 0; i < _capacity; i++) {
				_temp[i] = _arr[i];
			}
			delete[] _arr;
			_arr = _temp;
		}
		_arr[_size++] = val;
	}
	void pop_back() {
		assert(_size != 0);
		_size--;
	}
	void resize(size_t n, T val = T()) {
		T* _temp = new T[n];
		_size = min(_size, n);
		_capacity = n;
		for (size_t i = 0; i < _size; i++) {
			_temp[i] = _arr[i];
		}
		for (size_t i = _size; i < _capacity; i++) {
			_temp[i] = val;
		}
		delete[] _arr;
		_arr = _temp;
		_size = n;
	}
	void clear() {
		if (_arr != nullptr) delete[] _arr;
		_arr = new T[_DEFAULT_CAP];
		_size = 0;
		_capacity = _DEFAULT_CAP;
	}
	size_t size() { return _size; }
	bool empty() { return _size == 0; }
	/* iterator(..ish) */
	inline T* begin() const { return _arr; }
	inline T* end() const { return _arr + _size; }
	inline T& front() { assert(_size); return _arr[0]; }
	inline T& back() { assert(_size); return _arr[_size - 1]; }
	/* operator */
	inline T& operator[](size_t idx) { assert(idx < _size); return _arr[idx]; };
	Vector& operator=(const Vector& rhs) {
		if (_arr != nullptr) delete[] _arr;
		_arr = new T[rhs._capacity];
		_size = rhs._size;
		_capacity = rhs._capacity;
		for (size_t i = 0; i < _size; i++) {
			_arr[i] = rhs._arr[i];
		}
		return *this;
	}
private:
	T* _arr;
	size_t _size;
	size_t _capacity;
	static const size_t _DEFAULT_CAP = 64;
};
int main() {
	fastio;
	Vector<int> v(5, 1);
	Vector<int> w = v;
	Vector<int> u;
	u = v;
	for (auto v : { v, w, u }) {
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' '; cout << '\n';
	}
}