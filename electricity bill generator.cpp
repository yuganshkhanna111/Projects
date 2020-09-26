#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
struct customer
 {
   char name[20];
   int cid;
   float price;
 };
 
struct bill
 { 
   int bid;
   char name[20];
   float price;	
   int unit;
 };
 
 int customer_id()
  {
   int x;
   FILE *fp;
   fp=fopen("cid1.txt","r");
    if(fp==NULL) 
      x=1;
    else
      {
       fscanf(fp,"%d",&x);
       x++;
      }
   fclose(fp);
   
   fp=fopen("cid1.txt","w");
   fprintf(fp,"%d",x);
   fclose(fp);
   return x;
  } 
  
  
  
  int bill_id()
  {
   int y;
   FILE *fp;
   fp=fopen("bid1.txt","r");
    if(fp==NULL) 
      y=1;
    else
      {
       fscanf(fp,"%d",&y);
       y++;
      }
   fclose(fp);
   
   fp=fopen("bid1.txt","w");
   fprintf(fp,"%d",y);
   fclose(fp);
   return y;
  } 
  
  
   
 void add_customer()
  {
   system ("cls");
   FILE *ptr;
   int i;
   char password[10];
   struct customer c;
   ptr=fopen("cust.txt","a");
     fflush(stdin);
   printf("\n Enter customer details :- \n Name  -  ");
   gets(c.name);
     fflush(stdin);
 
   printf("\n Price of each unit  -  ");
   scanf("%f",&c.price);
   c.cid=customer_id();
    
       printf("\n Record added successfully.  ");
       printf("\n Your customer id is   %d",c.cid);
       getch(); 	
    
   fwrite(&c,sizeof(c),1,ptr);
   fclose(ptr);   
 } 
  
  
 void generate_bill()
  {
   system ("cls");
   int cusid;
   FILE *ptr,*ptr1;
   struct customer c;
   struct bill b;
   printf("\n Enter your customer id.  ");
   scanf("%d",&cusid);
    
   ptr=fopen("cust.txt","r");
    while(!feof(ptr))
     {
       fread(&c,sizeof(c),1,ptr);
       if(c.cid==cusid)
        {
          ptr1=fopen("bill1.txt","a");
          b.bid=bill_id();
          strcpy(b.name,c.name);
          printf("\n price per unit is  %f",c.price);
          b.price=c.price;
          printf("\n Enter number of unit consumed in this month.  ");
          scanf("%d",&b.unit);
          printf("\n Bill has been generateg successfully.   ");
          printf("\n Your bill id is   %d",b.bid);
          fwrite(&b,sizeof(b),1,ptr1);
          fclose(ptr1);
        }	
     }
   
   fclose(ptr);	
  }
  
  
 void display_bill()
  {
   system ("cls");
   int flag=0,billid,cusid;
   FILE *ptr1;
   struct bill b;
   printf("\n Enter your customer id.  ");
   scanf("%d",&cusid);
    if(cusid==-1)
     {
      exit(0);
     }
    else
   {  
   ptr1=fopen("bill1.txt","r");
   printf("\n Enter bill id. whose bill you want to display.  ");
   scanf("%d",&billid);
    while(!feof(ptr1))
     {
       fread(&b,sizeof(b),1,ptr1);
        if(b.bid==billid)
         {
           flag++;
           printf("\n MAKE IN INDIA Electricity pvt. ltd.  ");
           printf("\n        Electricity Bill");
           printf("\n   Bill id :- %d",b.bid);
           printf("\n   Name    :- %s",b.name);
           printf("\n   Customer id  :-  %d",cusid);
          
           printf("\n   Price per unit :- %f",b.price);
           printf("\n   Unit consumed :- %d",b.unit);
           printf("\n   Total amount :- %f",b.price*b.unit);
           printf("\n          THANK YOU");
           getch();
         }
     } 
  }
  fclose(ptr1);    
}
  
  void delete_bill()
   {
    system ("cls");
    int flag=0,billid,cusid;
    FILE *ptr,*ptr1;
    struct bill b;
    printf("\n Enter your customer id.  ");
   scanf("%d",&cusid);
     if(cusid==-1)
     {
      exit(0);
     }
    else
   {  
    ptr=fopen("bill1.txt","r");
    ptr1=fopen("temp.txt","w");	
    printf("\n Enter bill id. whose bill you want to delete.  ");
    scanf("%d",&billid);
     while(!feof(ptr1))
      {
       fread(&b,sizeof(b),1,ptr);
        if(b.bid==billid)
         {
           flag++;
           printf("\n Bill with id no.  %d DELETED successfully.",b.bid);
         }
        else
         fwrite(&b,sizeof(b),1,ptr);
      }
   }
    fclose(ptr);  
    fclose(ptr1);
     if(flag==0)
      printf("\n Error! No such bill with id no.  %d  exist.",billid);
    remove("bill1.txt");
    rename("temp.txt","bill1.txt");
   }
  
  
    

 main()
  {
   	 	
   int choice=1;
    while(choice!=5)
     {
      system ("cls");	
      printf("\n\n\n\t\t\t\t\t **************************************  ");
      printf("\n\t\t\t\t\t   MAKE IN INDIA Electricity pvt. ltd.  ");
      printf("\n\t\t\t\t\t **************************************  ");
      printf("\n\n\n\t\t\t\t\t      Electricity Bill Calculator");
      printf("\n\t\t\t\t\t   ++++++++++++++++++++++++++++++++");
      printf("\n\n\t\t\t\t\t\t @@@@@  MAIN MENU  @@@@@");
      printf("\n\n\t\t\t\t\t\t  1. Add new customer  "); 	
      printf("\n\t\t\t\t\t\t  2. Generate new bill  ");
      printf("\n\t\t\t\t\t\t  3. Display bill  ");
      printf("\n\t\t\t\t\t\t  4. Delete bill  ");
      printf("\n\t\t\t\t\t\t  5. EXIT ");
      printf("\n\n\t\t\t\t\t\t Enter your choice    ");
      scanf("%d",&choice);
       switch(choice)
        {
          case 1: add_customer();
                  break;
          case 2: generate_bill();
                  break;        
          case 3: display_bill();
                  break;
          case 4: delete_bill();
                  break;
          case 5: break;	  	  
          default:{
          	   printf("\n\n  Invalid Choice...!");
          	   printf("\n\n Press any key to continue..");
          	   getch();
	  } 	          
	  	
        }
     } 	
 }
  
  
  
  
  
  
  
  
  
  
