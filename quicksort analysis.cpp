#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
int count6=0;
int count7=0;
int count8=0;
struct Node
{
     int data;
     struct Node *link;
};
struct Node *head=NULL;
 #define stack_size 5000;
void print_data(struct Node *temp)
{
 while(temp!=NULL)
    {
       printf("%d",temp->data);
       printf("->");
       printf(" ");
       temp=temp->link;
    }
     printf("NULL");
     printf("\n");
}
struct Node*p1(struct Node* first,struct Node* last)
{

struct Node *pindex=first;
struct Node *ptr=first;
while(ptr!=NULL and ptr!=last)
{
   if(ptr->data<last->data)
    {
            pindex=first;

            swap(ptr->data,pindex->data);

first = first->link;
        }
         ptr=ptr->link;
}
        swap(first->data,last->data);
        return pindex;
}
 struct Node *p2(struct Node *head, struct Node *end, struct Node **new_head, struct Node **new_end)
{
    struct Node *pivot = end, *prev = NULL, *curr = head, *tail = pivot;
    while (curr != pivot)
{
        if (curr->data < pivot->data) {
            if ((*new_head) == NULL) (*new_head) = curr;
            prev = curr;
            curr = curr->link;
        }
        else {
            if (prev) prev->link = curr->link;
            struct Node *tmp = curr->link;
            curr->link = NULL;
            tail->link = curr;
            tail = curr;
            curr = tmp;
        }
    }
    if ((*new_head) == NULL) (*new_head) = pivot;
    (*new_end) = tail;
    return pivot;
}
 struct Node *quick_sort_list(struct Node *head, struct Node *end,int count)
{
    if (!head || head == end)
return head;
 if(count==2)
   count2++;
 else if(count==4)
       count4++;
 else if(count==6)
      count6++;
    else
      count8++;
    struct Node *new_head = NULL, *new_end = NULL;
    struct Node *pivot = p2(head, end, &new_head, &new_end);
    if (new_head != pivot)
 {
        struct Node *tmp = new_head;
        while (tmp->link != pivot)
        tmp = tmp->link;
        tmp->link = NULL;
        new_head = quick_sort_list(new_head,tmp,count);
        tmp = new_head;
        while (tmp->link)
          tmp = tmp->link;
        tmp->link = pivot;
    }
 pivot->link = quick_sort_list(pivot->link,new_end,count);
    return new_head;
}
void quick_sort(struct Node* first,struct Node* last,int count)
{
if (first == last)
{
return;
}
 switch(count)
     {
       case 1:count1++;
break;

       case 3:count3++;
 break;

       case 5:count5++;
break;

       case 7:count7++;
break;
     }

 struct Node* pivot = p1(first, last);

if (pivot != NULL && pivot->link != NULL) {

quick_sort(pivot->link, last,count);
}
if (pivot != NULL && first != pivot) {
quick_sort(first, pivot,count);
}
}
 struct Node* add_Node(struct Node* ptr,int data)
{
  struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=data;
   temp->link=NULL;
   if(!head)
   {
     head=temp;
     return head;
   }
    ptr->link=temp;
    return temp;
}
int main()
{
   struct Node *ptr=NULL;
   int data,data1;
    switch(1)
    {
     case 1:
             data1=data=rand();
            for(int i=0;i<150000;i++)
                            ptr=add_Node(ptr,data++);
            for(int i=0;i<50000;i++)
             {
                data=rand();
                ptr=add_Node(ptr,data);
             }
             quick_sort(head,ptr,1);
             head=NULL;
     case 2:
             for(int i=0;i<150000;i++)
                ptr=add_Node(ptr,data1++);
            for(int i=0;i<50000;i++)
             {
                data1=rand();
                ptr=add_Node(ptr,data1);
             }
             quick_sort_list(head,ptr,2);
                          head=NULL;
    case 3:
             data=rand();
         for(int i=0;i<300000;i++)
    	     ptr=add_Node(ptr,data++);
    for(int i=0;i<100000;i++)
      {
             data=rand();
          }  ptr=add_Node(ptr,data);
             quick_sort(head,ptr,3);
             head=NULL;
   case 4:
             data=rand();
         for(int i=0;i<300000;i++)
      ptr=add_Node(ptr,data++);
    for(int i=0;i<100000;i++)
      {
             data=rand();
          }  ptr=add_Node(ptr,data);
             quick_sort_list(head,ptr,4);
             head=NULL;
     case 5:
            data=rand();
       for(int i=0;i<600000;i++)
    	 ptr=add_Node(ptr,data++);
             quick_sort(head,ptr,5);
             head=NULL;
             break;
    case 6:
  for(int i=0;i<600000;i++)
  {
         data=rand();
 ptr=add_Node(ptr,data);
  }
             quick_sort_list(head,ptr,6);
             head=NULL;
             break;
    case 7:
  for(int i=0;i<600000;i++)
  {
         data=rand();
 ptr=add_Node(ptr,data);
  }
             quick_sort_list(head,ptr,7);
             head=NULL;
             break;
    case 8:
  for(int i=0;i<600000;i++)
  {
         data=rand();
 ptr=add_Node(ptr,data);
  }
             quick_sort_list(head,ptr,8);
            head=NULL;
             break;
}
  printf("\nPerforming quick sort for 2 lakh inputs 150000 are already sorted and 50000 random:\n");
  printf("\n1.No of recursive calls by Normal Quick sort is: %d\n",count1);
  printf("2.No of recursive calls by Tail optimization Quick sort is: %d\n",count2);
  printf("\nPerforming quick sort for 4 lakh inputs 3 lakhs are already sorted and 1lakh random:\n");
  printf("\n3.No of recursive calls by Normal Quick sort is: %d\n",count3);
printf("4.No of recursive calls by Tail optimization Quick sort is: %d\n",count4);
  printf("\nPerforming quick sort for 6 lakh inputs all are randomly generated:\n");
  printf("\n5.No of recursive calls by Normal Quick sort is: %d\n",count5);
  printf("6.No of recursive calls by Tail optimization Quick sort is: %d\n",count6);
  printf("\nPerforming quick sort for 6 lakh inputs all are randomly generated:\n");
  printf("\n7.No of recursive calls by Normal Quick sort is: %d\n",count7);
  printf("8.No of recursive calls by Tail optimization Quick sort is: %d\n",count8);
}
