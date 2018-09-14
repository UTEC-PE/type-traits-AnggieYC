#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    protected:
        Node<T>* current;
      
    public:
		Iterator() : current(nullptr) { current = NULL; };
		Iterator(Node<T>* current) : current(current) { this->current = current; };
             
		Iterator<T> operator=(Iterator<T> other) {
			current = other.current;
			return *current; // Aquí se retorna *this, esto va a dar error
		};
		bool operator!=(Iterator<T> other) {
			return(current != other.current);
		};
		T operator*() { return current->data; };
};  

#endif