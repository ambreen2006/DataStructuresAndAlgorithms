#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mb_list.h>

using namespace std;


MATCHER_P(IsNodeFound,exp1, "")
{
  return (arg != nullptr && arg->data == exp1);
}

TEST(DS_BasicLinkedListTests, AddNodeTest)
{
  MBList 	llist;
  int 		num_nodes = 0;
  
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
  
  MBNode *node = llist.find(15);

  EXPECT_THAT(node, IsNodeFound(15));
  
//  node = llist.find(12);
//  ASSERT_THAT(node, nullptr);
  

}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}