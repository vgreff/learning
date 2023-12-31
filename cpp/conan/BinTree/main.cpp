#include <iostream>
#include <memory>

class Node
{
public:
  using Ptr = std::unique_ptr<Node>;

  Node(int val, int order) : val_(val), order_(order) {}

  void print(int level = 0)
  {
    std::string space;
    space.insert(0, level * 3, ' ');
    std::cout
        << space
        << "level=" << level << " "
        << "val=" << val_ << ", "
        << "order=" << order_ << ", "
        << "nbSmallerChildren=" << nbSmallerChildren_ << ", "
        << "nbBiggerChildren=" << nbBiggerChildren_ << ", "
        << std::endl;
  }

private:
  int nbSmallerChildren_{0};
  int nbBiggerChildren_{0};
  Ptr left_;
  int val_{0};
  int order_{0};
  Ptr right_;

  friend class BinTree;
};

class BinTree
{
  Node::Ptr root_;
  Node::Ptr notFound_;
  int order_{0};

public:
  void insert(int val) { insert(root_, val); }
  Node::Ptr &index(int pos) { return index(root_, pos, 0); }

  void print() const
  {
    std::cout << "TreeSize=" << size() << "\n";
    print(root_, 0);
  }
  int size() const { return order_; }

private:
  void print(const Node::Ptr &node, int level) const
  {

    if (node)
    {
      {
        node->print(level);
        print(node->left_, level + 1);
        print(node->right_, level + 1);
      }
    }
  }
  int insert(Node::Ptr &node, int val)
  {
    if (node)
    {
      if (node->val_ > val)
      {
        int res = insert(node->left_, val);
        node->nbSmallerChildren_ += res;
        return res;
      }
      else
      {
        int res = insert(node->right_, val);
        node->nbBiggerChildren_ += res;
        return res;
      }
    }
    else
    {
      node = std::make_unique<Node>(val, order_++);
      return 1;
    }
  }

  Node::Ptr &index(Node::Ptr &node, int pos, int offset)
  {
    if (node)
    {
      if ((node->nbSmallerChildren_ + offset) == pos)
      {
        return node;
      }
      else
      {
        if ((node->nbSmallerChildren_ + offset) > pos)
        {
          return index(node->left_, pos, offset);
        }
        else
        {
          return index(node->right_, pos, offset + node->nbSmallerChildren_ + 1);
        }
      }
    }
    return notFound_;
  }
};

int main()
{
  BinTree tree;
  tree.insert(15);
  tree.insert(10);
  tree.insert(5);
  tree.insert(25);
  tree.insert(14);
  tree.insert(13);
  tree.insert(12);
  tree.insert(45);
  tree.insert(35);
  tree.insert(55);

  tree.print();
  
  std::cout << "\n";

  for (int i = 0; i < tree.size(); i++)
  {
    std::cout << i << "   ";
    auto &found = tree.index(i);
    if (found)
    {
      found->print();
    }
    else
    {
      std::cout << "NOT FOUND\n";
    }
  }

  return 0;
}
