#ifndef _DLL_H
#define _DLL_H

using namespace std;

template <typename T>
class Dll {
  private:
    struct Node {
      T _data;
      Node *prev;
      Node *next;

      Node (const T &d = T(), Node *p = NULL, Node *n = NULL)
        : _data (d), prev (p), next (n) { }
    };

  public:
    class const_iterator {
      public:
        const_iterator () : current (NULL) {}
        
        const T & operator* () const {
          return retrieve();
        }

        const_iterator & operator++ () {
          current = current->next;
          return *this;
        }

        const_iterator operator++ (int) {
          const_iterator old = *this;
          ++(*this);
          return old;
        }

        bool operator== (const const_iterator & rhs) const {
          return current == rhs.current;
        }

        bool operator!= (const const_iterator & rhs) const {
          return !(*this == rhs);
        }

        void _hit () {
          current->_data->__hit__();
        }

      protected:
        Node *current;

        T & retrieve () const {
          return current->_data;
        }

        const_iterator (Node *p) : current (p) {}

        friend class Dll<T>;
    };

    class iterator : public const_iterator {
      public:
        iterator () {}

        T & operator* () {
          return const_iterator::retrieve();
        }

        const T & operator* () const {
          return const_iterator::operator*();
        }

        iterator & operator++ () {
          const_iterator::current = const_iterator::current->next;
          return *this;
        }

        iterator operator++ (int) {
          iterator old = *this;
          ++(*this);
          return old;
        }

        void hit () {
          const_iterator::_hit();
        }

      protected:
        iterator (Node *p) : const_iterator(p) {}

        friend class Dll<T>;
    };

  public:
    Dll () {
      init();
    }

    ~Dll () {
      clear();
      delete head;
      delete tail;
    }

    Dll (const Dll & rhs) {
      init();
      *this = rhs;
    }

    const Dll & operator= (const Dll & rhs) {
      if (this == & rhs)
        return *this;

      clear();
      for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
        push_back(*itr);

      return *this;
    }

    iterator begin () {
      return iterator(head->next);
    }

    const_iterator begin () const {
      return const_iterator(head->next);
    }

    iterator end () {
      return iterator(tail);
    }

    const_iterator end () const {
      return const_iterator(tail);
    }

    int size () const {
      return theSize;
    }

    bool empty () {
      return size() == 0;
    }

    void clear () {
      while (!empty()) {
        pop_front();
      }
    }

    T & front () {
      return *begin();
    }

    const T & front () const {
      return *begin();
    }

    T & back () {
      return *--end();
    }

    const T & back () const {
      return *--end();
    }

    void push_front (const T & x) {
      insert(begin(), x);
    }

    void push_back (const T & x) {
      insert(end(), x);
    }

    void pop_front () {
      erase(begin());
    }

    void pop_back () {
      erase(--end());
    }

    void move_to_front (iterator itr) {
      iterator itr_head = head;

      insert(itr_head, itr.current->_data);

      erase(itr);
    }

    void sort () {
      Node *ptr, *dummy = new Node();

      if (head == NULL) return;
      if (head->next == NULL) return;

      int swapped = 1;
      while (swapped) {
        swapped = 0;

        ptr = head->next;

        while (ptr->next->next != NULL) {
          int shit1 = ptr->_data->getRelevance();
          int shit2 = ptr->next->_data->getRelevance();

          if (shit1 < shit2) {
            swapped = 1;

            dummy->_data = ptr->_data;
            ptr->_data = ptr->next->_data;
            ptr->next->_data = dummy->_data;
          }

          ptr = ptr->next;
        }
      }
    }

    iterator insert (iterator itr, const T & x) {
      Node *p = itr.current;
      theSize++;
      return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
    }

    iterator erase (iterator itr) {
      Node *p = itr.current;
      iterator retVal (p->next);
      p->prev->next = p->next;
      p->next->prev = p->prev;
      delete p;
      theSize--;

      return retVal;
    }

    iterator erase (iterator start, iterator end) {
      for (iterator itr = start; itr != end; )
        itr = erase(itr);

      return end;
    }

  private:
    int theSize;
    Node *head;
    Node *tail;
    
    void init() {
      theSize = 0;
      head = new Node;
      tail = new Node;
      head->next = tail;
      tail->prev = head;
    }
};

#endif
