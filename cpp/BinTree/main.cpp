#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;


struct Node
{
  Node(int val, int order, int pos) : val_(val), order_(order), pos_(pos) {}

  using Ptr = std::unique_ptr<Node>;
  int nbSmallerChildren_{0};
  int nbBiggerChildren_{0};
  Ptr  left_;
  int   val_{0};
  int   order_{0};
  int   pos_{0};
  Ptr right_;

  void print(int level )
  {
    std::string space;
    space.insert(0, level*3,' ');
    std::cout 
    << space
    << "level=" << level << " "
    << "val=" << val_ << ", "
    << "pos=" << pos_ << ", "
    << "order=" << order_ << ", "
    << "nbSmallerChildren=" << nbSmallerChildren_ << ", "
    << "nbBiggerChildren=" << nbBiggerChildren_ << ", "
    << std::endl;
  }
};


class BinTree
{
  Node::Ptr root_;
  int       order_{0};

public:

  void insert(int val, int pos)  { insert(root_, val, pos);  }
  void print()  { print(root_, 0);  }

private:
  void print(Node::Ptr& node, int level)
  {

    if (node)
    {
      {
        node->print(level);
        print(node->left_, level+1);
        print(node->right_, level+1);
      }
    } 
  }
  int insert(Node::Ptr& node, int val, int pos)
  {
    if (node)
    {
      if (node->val_ > val)
      {
        int res = insert(node->left_, val, pos); // 0
        node->nbSmallerChildren_ = res + 1;
        return node->nbSmallerChildren_+ node->nbBiggerChildren_;
      }
      else
      {
        int res = insert(node->right_, val, pos);// node->nbSmallerChildren_
        node->nbBiggerChildren_ = res + 1;
        return node->nbBiggerChildren_;
      }
    }
    else 
    {
      node = std::make_unique<Node>(val, order_++, pos);
      return 0;
    }
  }
  Node::Ptr& index(Node::Ptr& node,  int pos)
  {
    if (node)
    {
      if (node->nbSmallerChildren_ < pos)
      {
        index(node->left_, pos);
      }
      else
      {
        index(node->right_, pos);
      }
    }
    else 
    {
    }
  }
};


// To execute C++, please define "int main()"
int main() 
{
  BinTree tree;
  tree.insert(15, 5);
  tree.insert(10, 1);
  tree.insert(5, 0);
  // tree.insert(25, 4);
  tree.insert(14,4);
  tree.insert(13,3);
  tree.insert(12,2);

  tree.print();

  return 0;
}


// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab with the + button.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!

// str

