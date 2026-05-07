#include<stdio.h>
#include<stdlib.h>
//function declarations
void create();
void display();
void finsert();
void fdel();
void linsert();
void ldel();
void sinsert();
void sdel();
void search();
//structure declarations
struct Aadhar
{
char name[20];
char fname[20];
char mname[20];
char address[100];
char aadharno[12];
char gender[10];
char pnumber[10];
int age;
struct Aadhar *Next;
};
struct Aadhar *head=NULL;
//main function
int main()
{
int ch;
do
{
printf("MENU:\n");
printf("1.Create\n");
printf("2.Insert at First\n");
printf("3.Insert at Last\n");
printf("4.Insert at Specific position\n");
printf("5.Delete at First\n");
printf("6.Delete at Last\n");
printf("7.Delete at Specific position\n");
printf("8.Search\n");
printf("9.Display\n");
printf("10.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:create();break;
case 2:finsert();break;
case 3:linsert();break;
case 4:sinsert();break;
case 5:fdel();break;
case 6:ldel();break;
case 7:sdel();break;
case 8:search();break;
case 9:display();break;
case 10:printf("Byee....");break;
default: printf("\nEnter the options between 1 and 9 only...!!");break;
}
}while(ch!=10);
return 0;
}
//create function
void create()
{
struct Aadhar*temp;
temp=(struct Aadhar*)malloc(sizeof(struct Aadhar));
printf("Enter Name\n");
scanf("%s",temp->name);
printf("Enter Father Name\n");
scanf("%s",temp->fname);
printf("Enter Mother Name\n");
scanf("%s",temp->mname);
printf("Enter Address\n");
scanf("%s",temp->address);
printf("Enter Aadhar Number\n");
scanf("%s",temp->aadharno);
printf("Enter Gender\n");
scanf("%s",temp->gender);
printf("Enter Phone Number\n");
scanf("%s",temp->pnumber);
printf("Enter age\n");
scanf("%d",&temp->age);
temp->Next=NULL;
if(head==NULL)
{
head=temp;
}
else
{
temp->Next=head;
head=temp;
}
}
//insert at first function
void finsert()
{
struct Aadhar *tp;
tp=(struct Aadhar*)malloc(sizeof(struct Aadhar));
printf("Enter Name\n");
scanf("%s",tp->name);
printf("Enter Father Name\n");
scanf("%s",tp->fname);
printf("Enter Mother Name\n");
scanf("%s",tp->mname);
printf("Enter Address\n");
scanf("%s",tp->address);
printf("Enter Aadhar Number\n");
scanf("%s",tp->aadharno);
printf("Enter Gender\n");
scanf("%s",tp->gender);
printf("Enter Phone Number\n");
scanf("%s",tp->pnumber);
printf("Enter Age\n");
scanf("%d",&tp->age);
tp->Next=head;
head=tp;
printf("Inserted Successfully\n");
}
//delete at first function
void fdel()
{
struct Aadhar *tp;
if(head==NULL)
{
printf("No Data is present\n");
return;
}
else
{
head=head->Next;
tp=head;
free(tp);
printf("Deleted Successfully\n");
}
}
//insert at last function
void linsert()
{
struct Aadhar *tp,*lp;
tp=(struct Aadhar*)malloc(sizeof(struct Aadhar));
printf("Enter Name\n");
scanf("%s",tp->name);
printf("Enter Father Name\n");
scanf("%s",tp->fname);
printf("Enter Mother Name\n");
scanf("%s",tp->mname);
printf("Enter Address\n");
scanf("%s",tp->address);
printf("Enter Aadhar Number\n");
scanf("%s",tp->aadharno);
printf("Enter Gender\n");
scanf("%s",tp->gender);
printf("Enter Phone Number\n");
scanf("%s",tp->pnumber);
printf("Enter Age\n");
scanf("%d",&tp->age);
lp = head;
while(lp->Next != NULL)
{
lp = lp->Next;
}
lp->Next = tp;
tp->Next = NULL;
printf("Inserted Successfully\n");
}
//delete at last function
void ldel()
{
struct Aadhar *lp,*tp;
if(head==NULL)
{
printf("No Data is present\n");
return;
}
if(head->Next==NULL)
{
tp=head;
head=NULL;
free(tp);
printf("Deleted Successfully\n");
}
else
{
tp=head;
lp=NULL;
while(tp->Next!=NULL)
{
lp=tp;
tp=tp->Next;
}
lp->Next=NULL;
free(tp);
printf("Deleted Successfully\n");
}
}
//insert at specific position function
void sinsert()
{
struct Aadhar *tp,*lp;
int k=1,pos;
tp=(struct Aadhar*)malloc(sizeof(struct Aadhar));
printf("enter name\n");
scanf("%s",tp->name);
printf("Enter father name\n");
scanf("%s",tp->fname);
printf("Enter mother name\n");
scanf("%s",tp->mname);
printf("Enter address\n");
scanf("%s",tp->address);
printf("Enter aadhar number\n");
scanf("%s",tp->aadharno);
printf("Enter gender\n");
scanf("%s",tp->gender);
printf("Enter Phone Number\n");
scanf("%s",tp->pnumber);
printf("Enter age\n");
scanf("%d",&tp->age);
printf("Enter position\n");
scanf("%d",&pos);
lp = head;
while(k!=pos)
{
lp = lp->Next;
k++;
}
tp->Next = lp->Next;
lp->Next = tp;
printf("Inserted Successfully\n");
}
//delete at specific position function
void sdel()
{
struct Aadhar *tp,*lp;
int k=1,pos;
printf("Enter position\n");
scanf("%d",&pos);
if(head==NULL)
{
printf("No Data is present\n");
return;
}
if(head->Next==NULL && k==pos)
{
tp=head;
head=NULL;
free(tp);
printf("Deleted Successfully\n");
}
else
{
tp=head;
lp=NULL;
while(tp->Next!=NULL && k==pos)
{
lp=tp;
tp=tp->Next;
}
lp->Next=tp->Next;
free(tp);
printf("Deleted Successfully\n");
}
}
//search function
void search()
{
struct Aadhar *temp=head;
char key[12];
printf("Enter Aadhar number to be searched\n");
scanf("%s",key);
while(temp!=NULL)
{
if(temp->aadharno==key)
{
printf("Record found\n");
break;
}
temp=temp->Next;
}
if(temp==NULL)
{
printf("Record not found\n");
}
}
//display function
void display()
{
struct Aadhar *tp=head;
while(tp!=NULL)
{
printf("\n");
printf("Name-%s\n",tp->name);
printf("Father Name-%s\n",tp->fname);
printf("Mother Name-%s\n",tp->mname);
printf("Address-%s\n",tp->address);
printf("Aadhar Number-%s\n",tp->aadharno);
printf("Gender-%s\n",tp->gender);
printf("Phone Number-%s\n",tp->pnumber);
tp=tp->Next;
}
print("NULL\n");
}