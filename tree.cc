
#include <utility>
#include <iostream>

using namespace std;

template<typename Comparable>
class binary_search_tree
{
public:
  binary_search_tree()
  {
    root = nullptr;
  }

  const Comparable & min( )
  {
      return min(root)->element;
  }

  const Comparable & max( )
  {
      return max(root)->element;
  }
  
  bool contains( const Comparable & x ) 
  {
      return contains (x,root);
  }
  
  bool is_empty( ) 
  {
      is_empty(root);
  }

  void insert( const Comparable & x )
  {
      insert(x, root);
  }

  void print( )
  {
      print(root, cout);
  }

  
private:
  
  struct binary_node
  {
    Comparable element;
    binary_node *left;
    binary_node *right;

    binary_node(const Comparable & an_element, binary_node *l, binary_node *r) :
      element { an_element }, left{ l }, right{ r } { }
    
    binary_node(const Comparable && an_element, binary_node *l, binary_node *r) :
      element { std::move(an_element) }, left{ l }, right{ r } { }
  };

  binary_node *root = nullptr;

  void insert ( const Comparable & x, binary_node * & t )
  {
      if(t==nullptr)
      {
        t = new binary_node{x, nullptr, nullptr};
      }
      else if(x < t->element)
      {
        insert(x, t->left);
      }
      else if(t->element < x)
      {
        insert(x, t->right);
      }
      else
      {
        
      }
  }
  
  binary_node * min(binary_node *t)
  {
      if(t==nullptr)
      {
        return nullptr;
      }
      if(t->left==nullptr)
      {
        return t;
      }
      return min(t->left);
  }

  binary_node * max(binary_node *t)
  {
    if(t!=nullptr)
    {
      while(t->right != nullptr)
      {
        t = t->right;
      }
    }
    return t;
  }

  bool is_empty(binary_node *t)
  {
    if(t==nullptr)
    {
      cout<<"Empty tree"<<endl;
    }
  }

/* 
The values of all the items in its left subtree are smaller than the item in X,
and the values of all the items in its right subtree are larger than the item in X
*/
  bool contains(const Comparable & x, binary_node *t)
  {
      if(t == nullptr)
      {
        return false;   //empty
      }
      else if(x < t->element)   //  where x is the items smaller than left subtree
      {
        return contains(x, t->left);
      }
      else if(t->element < x)   //x is the items larger than the right subtree
      {
        return contains(x, t->right);
      }
      else
        return true;  //match
  }

  void print(binary_node *t, ostream & out )
  {
      if(t!=nullptr)
      {
        print(t->left, out);
        out<<t->element<<endl;
        print(t->right, out);
      }
  }
};

int main()
{
  binary_search_tree<int> bst;
  int x;
  
  while(cin >> x)
    {
      bst.insert(x);
    }
  
  bst.print();
  cout << "Minimal element = " << bst.min() << "\n";
  cout << "Maximal element = " << bst.max() << "\n";
 
}

