#ifndef _BST_H
#define _BST_H

#include <string>
#include <queue>
#include <vector>
#include "dll.h"

typedef Dll<Play*> R;

template <typename T>
class BST {
  public:
    BST () {}
    BST (const BST &og) {}
    ~BST () {}

    /*
    Function: find_min()
    calls the internal private function
    find_min(Node *t)
    */
    const T & find_min () const {
      return find_min(root);
    }

    /*
    Function: find_max()
    calls the internal private function
    find_max(Node *t)
    */
    const T & find_max () const {
      return find_max(root);
    }

    /*
    Function: contains()
    This function returns true if x is
    found in the tree. calls the internal
    private contains function
    */
    bool contains (const T &x) const {
      return contains(x, root);
    }

    bool is_empty () const {}

    void print (Dll<Play*> &x) const {
      print(x, root);
    }


    void clear () {}

    /*
    Function: insert()
    Insert x into the tree. Duplicate elements will
    be ignored instead of copied.
    */
    void insert (const T &x) {
      insert(x, root);
    }

    /*
    Function: remove()
    Remove x from the tree. If x is not found then
    the function exits without doing anything
    */
    void remove (const T &x) {
      remove(x, root);
    }

    /*
    Function: get_n_relevant()
    Traverse through the tree and get the relevant plays
    */
    void get_relevant (R & _list, vector<string> cmd) {

      queue<Node*> q;

      if (root) {
          q.push(root);
      }
      while (!q.empty()) {
        const Node * const temp_node = q.front();
        q.pop();
        (temp_node->element)->setRelevance(cmd.at(2),
                                           cmd.at(3),
                                           cmd.at(4),
                                           cmd.at(5),
                                           cmd.at(6),
                                           cmd.at(7)
                                          );

        bool similar = (temp_node->element)->summary(cmd.at(3),
                                                     cmd.at(5),
                                                     cmd.at(6),
                                                     cmd.at(7)
                                                    );

        if (similar)
          _list.push_back(temp_node->element);

        if (temp_node->left) {
            q.push(temp_node->left);
        }
        if (temp_node->right) {
            q.push(temp_node->right);
        }
      }
    }

    void summary (vector<string> cmd, double &count,
                      double &dpr, double &dpl, double &dpm,
                      double &spr, double &spl, double &spm, 
                      double & rr, double &rl, double &rm, 
                      double &fg, double &pnt) {
      queue<Node*> q;

      if (root)
          q.push(root);

      while (!q.empty()) {
        const Node * const temp_node = q.front();
        q.pop();

        if ((temp_node->element)->_valid()) {
        bool similar = (temp_node->element)->summary(cmd.at(1),
                                       cmd.at(2),
                                       cmd.at(3),
                                       cmd.at(4)
                                        );
          if (similar) {
            count++;

            string type = (temp_node->element)->getType();
            if (type == "dpr") dpr++;
            if (type == "dpl") dpl++;
            if (type == "dpm") dpm++;
            if (type == "spr") spr++;
            if (type == "spl") spl++;
            if (type == "spm") spm++;
            if (type == "rr") rr++;
            if (type == "rl") rl++;
            if (type == "rm") rm++;
            if (type == "fg") fg++;
            if (type == "pnt") pnt++;
          }
        }

        if (temp_node->left)
            q.push(temp_node->left);

        if (temp_node->right)
            q.push(temp_node->right);
      }
    }

    void reorganize () {
      queue<Node*> q;

      if (root)
          q.push(root);

      while (!q.empty()) {
        Node * temp_node = q.front();
        q.pop();

        if ((temp_node->element)->getHits() >= 3)
          move_to_root(temp_node, root);

        if (temp_node->left)
          q.push(temp_node->left);

        if (temp_node->right)
          q.push(temp_node->right);
      }
    }


    const BST & operator= (const BST &og) {}


  private:
    struct Node {
      T element;
      Node *left;
      Node *right;

      Node (const T &og, Node *lt, Node *rt)
        : element(og), left(lt), right(rt) {}
    };

    Node *root;

    /*
    Function: insert() --internal
    x is the element to insert into the tree.
    t is the root of the subtree.
    */
    void insert (const T &x, Node *&t) const {
      if (t == NULL)
        t = new Node(x, NULL, NULL);

      else if (x < t->element)
        insert(x, t->left);

      else if (t->element < x)
        insert(x, t->right);

      else
        ; // Dont do anything...
    }

    /*
    Function: remove() --internal
    x is the element to be deleted
    t is the root of the subtree.
    */
    void remove (const T &x, Node *&t) const {
      if (t == NULL)
        return;

      if (x < t->element)
        remove(x, t->left);

      else if (t->element < x)
        remove(x, t->right);

      else if (t->left != NULL && t->right != NULL) {
        t->element = find_min(t->right)->element;
        remove(t->element, t->right);
      }

      else {
        Node *old = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete old;
      }

    }

    /*
    Function: find_min() --internal
    Returns the node containing the smallest
    element in the tree.
    t should be the root
    */
    Node * find_min (Node *t) const {
      if (t == NULL)
        return NULL;

      if (t->left == NULL)
        return t;

      return find_min(t->left);
    }

    /*
    Function: find_min() --internal
    Returns the node containing the smallest
    element in the tree.
    t should be the root
    */
    Node * find_max (Node *t) const {
      if (t != NULL)
        while (t->right != NULL)
          t = t->right;

      return t;
    }

    /*
    Function: contains() --internal
    x is the item to search for
    t is the root node of the subtree 
    that is being searched
    */
    bool contains (const T &x, Node *t) const {
      if (t == NULL)
        return false;

      else if (x < t->element)
        return contains(x, t->left);

      else if (t->element < x)
        return contains(x, t->right);

      else
        return true;
    }

    void clear (Node *t) {}

    void print (Dll<Play*> &x, Node *t) const {
      queue<Node*> q;
      Node * temp_node = t;
      x.clear();

      while (temp_node) {

          x.push_back(temp_node->element);

          if (temp_node->left) {
              q.push(temp_node->left);
          }
          if (temp_node->right) {
              q.push(temp_node->right);
          }
          if (!q.empty()) {
            temp_node = q.front();
            q.pop();
          }
          else
            temp_node = NULL;
      }
    }

    void move_to_root (Node *&x, Node *&t) {
      if (t == NULL)
        return;

      else if (x->element < t->element) {
        move_to_root(x, t->left);
        rotate_right(x);
      }

      else if (t->element < x->element) {
        move_to_root(x, t->right);
        rotate_left(x);
      }

      else
        ;
    }

    void rotate_right (Node *&x) {
      Node *pivot = x->left;
      cout << "the seg fault is right here" << endl;
      x->left = pivot->right;
      pivot->right = x;
      x = pivot;
    }

    void rotate_left (Node *&x) {
      Node *pivot = x->right;
      cout << "the seg fault is right here" << endl;
      x->right = pivot->right;
      pivot->right = x;
      x = pivot;
    }

    Node * clone(Node *t) const {}
};

#endif