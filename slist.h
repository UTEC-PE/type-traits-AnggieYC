#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++();
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
			pointer = &head;
			if (head) {
				while ((*pointer)&& cmp(search,(*pointer)->data)){
					pointer = &((*pointer)->next);
				}
			}
			return((*pointer)->data == search);
        }
             
		bool insert(T data) {
			Node<T> **position;
			Node<T> *node = new Node<T>(data);
			if (head == NULL) {
				head = node;
				head->next = NULL;
				return true;
			}
			if (find(data, position) == false) {
				node->next = *position;
				*position = node;
				return true;
			}
			return false;

		}

             
        bool remove(T item) {
			Node<T> **position;
			if (find(item, position)) {
				Node<T> *temp = *position;
				*position = (*position)->next;
				delete temp;
				return true;
			}
			return false;
			
        }  
             
        iterator begin() {
			return iterator(head);
        }
             
        iterator end() {
            // TODO
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif