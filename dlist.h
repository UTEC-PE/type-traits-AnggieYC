#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++();
        DListIterator<T> operator--(); // No implementaste el iterador, esto no compila
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
			Node <T>* temp = new Node <T>;
			temp->data = data;
			if (head == NULL) { 
				head = tail = temp; 
				temp->prev = temp->next = NULL;
			}
			else {
				temp->next = head;
				head->prev = temp;
				head->temp;
			}
		
        }

        void push_back(T data) {
			Node <T>* temp = new Node <T>;
			temp->data = data;
			if (head == NULL) {
				head = tail = temp;
				temp->prev = temp->next = NULL;
			}
			else {
				tail->next = temp;
				temp->prev = tail;
				temp->next = NULL;
				tail->temp;
			}
        }
             
        void pop_front() {
			if (head != NULL) {
				Node <T>* temp = head;
				head->next;
				delete temp;
			}
			else throw "Lista vac�a";
        }
             
        void pop_back() {
			if (head == NULL) throw "Lista Vac�a";
			else {
				Node <T>* temp = tail;
				temp->prev->next = NULL;
				tail = tail->prev;
				delete temp;
			}
        }
             
        iterator begin() {
			return Iterator<T>(head);
        }
             
        iterator end() {
			return Iterator<T>(tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif