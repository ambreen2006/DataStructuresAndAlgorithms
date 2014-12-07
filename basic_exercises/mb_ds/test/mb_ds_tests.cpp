#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mb_list.h>

using namespace std;


MATCHER_P(IsNodeFound,exp1, "")
{
  return (arg != nullptr && arg->data == exp1);
}

MATCHER_P3(IsNodeRemoved, node, count,result, "")
{
    // arg would be the llist, count will be the expected size of the list after remove().
    // node would be the returned value from find. result is the result from remove().
    return (arg.count() == count && node.expired() && result == true);
}

TEST(DS_BasicLinkedListTests, AddNodeTest)
{
  MBList 	llist;
  int 		num_nodes = 0;
  
  // let's insert some prime numbers
  llist.insert(7); // first node
  num_nodes++;
  
  llist.insert(11); // second node
  num_nodes++;
  
  llist.insert(13); // second node
  num_nodes++;
  
  ASSERT_THAT(num_nodes,llist.count()); 
}


TEST(DS_BasicLinkedListTests, findNodeTest)
{
  MBList 	llist;
  
  llist.insert(10); // first node 
  llist.insert(15); // second node
  
  shared_ptr<MBNode> node = llist.find(15);

  EXPECT_THAT(node, IsNodeFound(15));
}

TEST(DS_BasicLinkedListTests, removeNodeTest)
{
  MBList	llist;
  bool		result = false;

  // let's insert some perfect squares
  llist.insert(121);
  llist.insert(144);
  llist.insert(169);
  
  //llist.print();
  result = llist.remove(144);

  weak_ptr<MBNode> node(llist.find(144));
  
  ASSERT_THAT(llist,IsNodeRemoved(node,2,result));  
}

TEST(DS_BasicLinkedListTests, findInEmptyList)
{
  MBList llist;
  auto node = llist.find(7);
  ASSERT_THAT(node, nullptr);
}

TEST(DS_BasicLinkedListTests, findNonExistingNodeTest)
{
  MBList llist;
  
  llist.insert(1);
  llist.insert(1);
  llist.insert(2);
  llist.insert(3);
  llist.insert(5);
  llist.insert(8);
  llist.insert(13);
  llist.insert(21);
  llist.insert(34);
  
  //llist.print();
  auto node = llist.find(55);
  ASSERT_THAT(node,nullptr);
  
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}