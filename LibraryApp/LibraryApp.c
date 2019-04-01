#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//Preprocessor Variable
#define SIZE 10

struct book{
  char id[30],name[30],author[30],customer[30];
  int year,loanedTimes;
  bool loaned;
  double value;
};

struct LinearNode {
	struct book *element;
	struct LinearNode *next;
};

struct LinearNode *front = NULL;
struct LinearNode *last = NULL;

void readFile(),writeFile(),menu(),add(),borrow(),returnBook(),deleteBook(),viewAll(),viewOne(),viewPopNo(),viewValue();
bool isEmpty(),bookExists(char[]);
int main(int argc, char *argv[]) {	
  	menu();
	return 0;
}

/*-------------------------------------Menu------------------------------------------*/
void menu(){
	int x = 0;
	do{
	printf("1. Add a new book to the library \n");
	printf("2. Allow customer to take out a book \n");
	printf("3. Allow Customer to return a book \n");
	printf("4. Delete an old book from stock \n");
	printf("5. View all books \n");
	printf("6. View a specific book \n");
	printf("7. View details of most popular and least popular books \n");
	printf("8. Check value of the books \n");
	printf("9. Exit the system \n");
  scanf("%d",&x);
  getchar();
  if (x==1)
  add();
  else if (x==2)
  borrow();
  else if (x==3)
  returnBook();
  else if (x==5)
  viewAll();
  else if (x==4)
  deleteBook();
  else if (x==6)
  viewOne();
  else if (x==7)
  viewPopNo();
  else if (x==8)
  viewValue();
  else if (x>9)
  printf("Error - Please chose an option from the menu.\n");
	}while(x!=9);
	
} 
/*--------------------------------------Add Function----------------------------------------*/
void add(){ 
  struct LinearNode *aNode;
	struct book *anElement;
	bool valid = true;;
	char idVal[30],name[30];
	int i;
  anElement = (struct book *)malloc(sizeof(struct book));
  if (anElement == NULL)
    	printf("Error - no space for the new element\n");
		else{
      printf("Please enter the book ID.\n");
      do{
      	fgets(idVal, 30, stdin);
      	valid = true;
      if(idVal[4] != '-')
        valid = false;
	  if(strlen(idVal)>10)
	   valid = false;
	  if(strlen(idVal)<10)
	   valid = false;
      for(i = 0; i != '\0'; i++) {
      	if((!isdigit(idVal[i]))&& i!=4)
      		valid = false;
		}
      if(valid == false){
        	printf("Invalid ID format please type it in XXXX-XXXX form.\n");
        }
      else if(bookExists(idVal)){
      		printf("This ID already exists please enter a different one.\n");
			}
      else {
			break;
		}
      }while(true);
      printf("Please enter the name of the book.\n");
      fgets(anElement->name, 30, stdin);
      printf("Please enter the name of the book author.\n");
      fgets(anElement->author, 100, stdin); 
      printf("Please enter the year of publication.\n");
      do{
	  scanf("%d", &anElement->year);
	  if(anElement->year<2008)
	  printf("Year of publication can not be older than 2008.\n");
	  }while(anElement->year<2008);
      printf("Please enter the initial book value.\n$");
      scanf("%lf", &anElement->value);
      anElement->loanedTimes = 0;
      anElement->loaned = false;
      strcpy(anElement->customer, "");
	  strcpy(anElement->id, idVal);
      aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
      if (aNode == NULL)
		     	printf("Error - no space for the new node\n");
		  else { // add data part to the node
		       	aNode->element = anElement;
			    aNode->next = NULL;
                //add node to end of the list
			    if (isEmpty()) {
				   front = aNode;
				   last = aNode;
                }
			    else {
				     last->next = aNode;
				     last = aNode;
			      } //end else
           }
    }
}
/*--------------------------------------Loan out a book function.----------------------------------------*/
void borrow(){
	char loan[30];
	bool notFound = true;
	struct LinearNode *current, *previous;
	printf("\n");
	if (isEmpty())
		printf("Error, no books in the database.\n");
	else  {
			current = previous = front;
			printf("Please enter the book ID of the book you wish to loan out.\n");
			fgets(loan, 30, stdin);
			if(bookExists(loan) == false)
				printf("Book with this ID doesn't exist.\n");
				else{
				
			while (notFound && current != NULL) {
				if (strcmp(loan, current->element->id) == 0){
					notFound = false;
				}else {
						previous = current;
						current = current->next;
				}
			}
			 if(current->element->loaned == false){
				 	printf("Please enter the customer name to whom you wish to loan the book.\n");
					fgets(current->element->customer, 30, stdin);
					current->element->loaned = true;
					current->element->loanedTimes += 1;
					current->element->value *= 0.99;
					printf("This book is now loaned by: %s \n",current->element->customer);
				}else
				printf("This book is already loaned out.\n");
			}
		}
	}
/*--------------------------------------Return a book function.----------------------------------------*/
void returnBook(){
	char loan[30];
	char cust[30];
	bool notFound = true;
	struct LinearNode *current, *previous;
	printf("\n");
	if (isEmpty())
		printf("Error, no books in the database.\n");
	else  {
			current = previous = front;
			printf("Please enter the book ID of the book you wish to return.\n");
			fgets(loan, 30, stdin);
			if(bookExists(loan) == false)
				printf("Book with this ID doesn't exist.\n");
				else{
			while (notFound && current != NULL) {
				if (strcmp(loan, current->element->id) == 0){
					notFound = false;
				}else {
						previous = current;
						current = current->next;
				}
			}
			 if(current->element->loaned == false){
				 	printf("This Book is not loaned out.\n");	
				}else if(current->element->loaned == true){
				printf("Please enter the customer name.\n");
				fgets(cust, 30, stdin);
				}
		   	 if (strcmp(cust, current->element->customer) == 0){
		   	 	 current->element->loaned = false;
		   	 	 strcpy(current->element->customer , "");
		   	 	 printf("The book has been successfully returned. \n");
			 }else{
			 	printf("The customer names do not match!\n");
			 }
		}
	}
}
/*--------------------------------------View All Function----------------------------------------*/
void viewAll() {
	struct LinearNode *current;
	printf("\n");
	if (isEmpty())
		printf("Error, no books in the database.\n");
	else {
		current = front;
		int i = 1;
		while (current != NULL) {
			printf("Book %d details: \nBook Id: %sBook Name: %s",i,current->element->id,current->element->name);
			i++;
			current = current->next;
		}
	}
}
/*--------------------------------------View Specific book function----------------------------------------*/
void viewOne(){
	
	char view[30];
	bool notFound = true;
	struct LinearNode *current, *previous;
	printf("\n");
	if (isEmpty())
		printf("Error, no books in the database.\n");
	else  {
			current = previous = front;
			printf("Please enter the book ID of the book you wish view details.\n");
			fgets(view, 30, stdin);
			if(bookExists(view) == false)
				printf("Book with this ID doesn't exist.\n");
				else{
				
			while (notFound && current != NULL) {
				if (strcmp(view, current->element->id) == 0){
					notFound = false;
				}else {
						previous = current;
						current = current->next;
				}
			}
			char loaned[15] = "Loaned";
			char notLoaned[15] = "Not Loaned";
			char status[15];
			if(current->element->loaned == true)
			strcpy(status, loaned);
			else 
			strcpy(status, notLoaned);
			 printf("Book details: \n Book Id: %s Book Name: %s Book Author: %s Book year of publication: %d \n Book Status: %s \n Times Loaned: %d \n Customer Name: %s \n Book Value: %.2f \n",
				current->element->id,current->element->name, current->element->author, 
				current->element->year,status,current->element->loanedTimes,current->element->customer,current->element->value);
			}
		}
}


/*--------------------------------------Delete Book Function----------------------------------------*/
void deleteBook() {
	struct LinearNode *current, *previous;
	bool notFound = true;
  	char idRem[30];
  	printf("Please enter the book ID that you want to delete.\n");
  	fgets(idRem,30,stdin);
     printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else  {
			current = previous = front;
			while (notFound && current != NULL) {
				if (strcmp(idRem, current->element->id) == 0)
					notFound = false;
				else {
						previous = current;
						current = current->next;
				}
			}
			if (notFound)
				printf("Error - there is not such ID with value:  %s.\n", idRem);
			else if(current->element->year>=2010)
				printf("Error - Only books older than 2010 can be deleted.\n");
			else  {
				if (current == front) { //delete front node
					front = front->next;
					free(current);
				} //end else
				else if (current == last) {//delete last node
                     free(current);
                     previous->next = NULL;
                     last = previous;
                 }
				else {//delete node in middle of list
						previous ->next= current->next;
						free(current);
				} 
				printf("Book with ID %s has been deleted.\n", idRem);
			}
		}
}
void viewPopNo(){
	int min = 10000;
	int max = 0;
	struct LinearNode *current;
    printf("\n");
	if (isEmpty())
		printf("Error - there are no Books in the list\n");
	else {
			current = front;
			while (current != NULL) {
				if(current->element->loanedTimes>max)
				max = current->element->loanedTimes;
				if(current->element->loanedTimes<min)
				min = current->element->loanedTimes;
				
				current=current->next;
			}
			current = front;
			while (current != NULL) {
				if(current->element->loanedTimes==max)
				printf("Most popular book(s) details: \nBook Id: %sBook Name: %s",current->element->id,current->element->name);
				if(current->element->loanedTimes==min)
				printf("Least popular book(s) details: \nBook Id: %sBook Name: %s",current->element->id,current->element->name);
				
				current=current->next;
    }//end else
}
}
/*--------------------------------------Check value of Books Function----------------------------------------*/
/*Each time  a book is loaned out the value of the book decreases by 1%*/
void viewValue(){
	struct LinearNode *current;
	double totalValue = 0;
	printf("\n");
	if (isEmpty())
		printf("Error, no books in the database.\n");
	else {
		current = front;
		int i = 1;
		while (current != NULL) {
			printf("Book %d details: \nBook Id: %sBook Name: %sBook Value: %.2f \n",i,current->element->id,current->element->name,current->element->value);
			i++;
			totalValue +=current->element->value;
			current = current->next;
		}
		printf("All books total value is: $%.2f \n",totalValue);
	}
}

/*--------------------------------------Checks if book exists----------------------------------------*/
bool bookExists(char *bkID){
	struct LinearNode *current, *previous;
	if (isEmpty())
		return false;
	else  {
			current = previous = front;

			while (current != NULL) {
				if (strcmp(bkID, current->element->id) == 0)
					return true;
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while
		}
	return false;		
}

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
