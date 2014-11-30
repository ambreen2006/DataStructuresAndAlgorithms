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
  if(this->head == nullptr && this-> number_of_elements == 0)
  {
      this->head =  make_shared<MBNode>(MBNode(_data));
      this->number_of_elements++;
      return;
  }

  // traverse to the end of the list
  auto node = this->head;
  
  while(node->next != nullptr)
  {
    node = node->next;
  }
  
  node->next = make_shared<MBNode>(MBNode(_data));
  cout << "Added node " << node->next->data << endl;
  this->number_of_elements++;
  
}

MBNode* MBList::find(int _lookup)
{
  auto node = this->head;
  
  cout << "finding node " << endl;
  while(node->next != nullptr)
  {
    node = node->next;
    if(node->data == _lookup)
    {
      return node.get();
    }

    node = node->next;
  } 
  
 return nullptr;  
}


size_t MBList::count() const
{
  return number_of_elements;
}
