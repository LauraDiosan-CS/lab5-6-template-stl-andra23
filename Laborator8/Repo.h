#pragma once
#include<map>
template < class T>
class Repo {
protected:
	const char* fis;
	map<int, T> elem = {};
	int key = 0;
public:
	Repo<T>();
	virtual ~Repo<T>();
	virtual void addElem(T);
	virtual void delElem(int i);
	virtual void updateElem(int i, const T nou);
	int getSize();
	map<int, T> getAll();
	void clearMap();
	T find(int i);

};
template<class T>Repo<T>::Repo() {
}
template<class T>Repo<T>::~Repo() {
}
template<class T>void Repo<T>::addElem(T e) {

	elem.insert(pair<int, T>(key++, e));
}

template<class T>void Repo<T>::delElem(int i) {

	auto itr = elem.find(i);
	elem.erase(itr);
}
template< class T>void Repo<T>::updateElem(int i, const T nou) {

	elem[i] = nou;
}

template<class T>int Repo<T>::getSize() {

	return elem.size();

}
template<class T>map<int, T> Repo<T>::getAll() {

	return elem;
}
template<class T>void Repo<T>::clearMap() {

	elem.clear();
}
template<class T>T Repo<T>::find(int i)
{
	return elem[i];
}






