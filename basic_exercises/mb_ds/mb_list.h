/**
 * 	@author ambreen2006
 * 	
 * 	Basic linked list exercise that provides interface to add, find and remove a node.
 */

#ifndef BASIC_EXERCICES_MB_DIS_MB_LIST_HPP_
#define BASIC_EXERCICES_MB_DIS_MB_LIST_HPP_

#include <memory>
#include <stddef.h>


using namespace std;

class MBNode
{
public: // member method
  MBNode(int _data)
  : data(_data) 
  , next(nullptr) {};
  
public: // member variables
  int data;
  shared_ptr<MBNode> next;
};

class MBList
{
public:
  MBList();
  virtual ~MBList() {};
  virtual void insert(int _data);
  virtual bool	remove(int _lookup);
  virtual shared_ptr<MBNode> find(int _lookup);
  virtual size_t count() const;
  virtual void print() const;
    
private:
  shared_ptr<MBNode> head;
  size_t  number_of_elements;
};

#endif