/**
 *	Linked list exercise
 */

#include "mb_list.h"

#include<iostream>

using namespace std;


MBList::MBList()
{
  this->head = nullptr;
  this->number_of_elements = 0;
}

void MBList::insert(int _data)
{
  
  // check if there is no head present and the count is 0. 
  if( !(this->head) && this->number_of_elements == 0)
  {
      this->head =  make_shared<MBNode>(MBNode(_data));
      this->number_of_elements++;
      return;
  }

  // traverse to the end of the list
  auto node = this->head;
  
  while(node->next)
  { 
    node = node->next;
  }
  
  node->next = make_shared<MBNode>(MBNode(_data));
  this->number_of_elements++;
  
}

shared_ptr<MBNode> MBList::find(int _lookup)
{
  auto node = this->head;
  while(node)
  {
    if(node->data == _lookup)
    {
      return node;
    }

    node = node->next;
  } 
   return nullptr;  
}

bool MBList::remove(int _lookup)
{
  auto node = this->head;
  shared_ptr<MBNode> parent = nullptr;

  while(node->next)
  {
    if(node->data == _lookup)
    {
      // if the node was in somewhere in between the list.
      if(parent)
      {
	  parent->next = node->next;
      }
      else // The node was the head
      {
	  this->head = node->next;
      }
      
      node.reset();
      this->number_of_elements--;
      return true;
    }
    
    parent = node;
    node = node->next;
  }

  return false;
}


size_t MBList::count() const
{
  return number_of_elements;
}

void MBList::print() const
{
  auto node = this->head;	
  
  std::cout << endl;
  while(node)
  {
    std::cout << " " << node->data;
    node = node->next;
  }
  std::cout << endl;
}
