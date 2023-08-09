#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <string>


#define N 9

using namespace std;


struct BookNode
{
    string title;
    string author;
    string date;
    string type;
    int refNum;
    int status;

    BookNode *bef;
    BookNode *next;

    BookNode(string _title= "", string a = "", string d = "", string t ="",int _refNum = 0) 
    {
        title = _title;
        author = a;
        date = d;
        type = t;
        status = 0;
        refNum = _refNum;

        next = NULL;
        bef = NULL;
    }
};


int convertDateR(string dateReturned){
  
    int integerR;

    string s1 = dateReturned;
        
     string days = s1.substr(0,2);
        
     string months = s1.substr(3,2);
        
     string years = s1.substr(6,4);
     
     //convert days to int
     
    integerR = stoi(days); 
     
     
     return integerR;
  
}


 int convertDateB(string dateBorrowed){
  
    int integerD;

    string s1 = dateBorrowed;
        
    string days = s1.substr(0,2);
        
    string months = s1.substr(3,2);
        
    string years = s1.substr(6,4);
     
    //convert days to int
     
    integerD = stoi(days); // explicit type casting
     
    // cout << " days in integer : " << integerD;
     
    return integerD;
  
}



int getTotalDays(int a,int b){
  
  int totaldays;
 
  totaldays = b - a;
 
  return totaldays;
  
}



void getDateBorrowed(string dateBorrowed){
  

      
        string month;
        
        string s1 = dateBorrowed;
        
        string days = s1.substr(0,2);
        
        string months = s1.substr(3,2);
        
        string years = s1.substr(6,4);
          
        
          if (months=="01")
                month="JANUARY";

            else 
            if(months=="02")
                month="FEBRUARY";

            else 
            if (months=="03")
                month="MARCH";

            else 
            if (months=="04")
                month="APRIL";

            else 
            if (months=="05")
                month="MAY";

            else 
            if(months=="06")
                month="JUNE";

            else 
            if (months=="07")
                month="JULY";

            else 
            if (months=="08")
                month="AUGUST";

            else 
            if (months=="09")
                month="SEPTEMBER";

            else 
            if (months=="10")
                month="OCTOBER";

            else 
            if (months=="11")
                month="NOVEMBER";
                
            else
                month="DECEMBER";
          
          
          
          cout << days <<" "<< month <<" "<< years <<endl;
    
}

void getDateReturned(string dateReturned){
  
      
        string month;
        
        string s1 = dateReturned;
        
        string days = s1.substr(0,2);
        
        string months = s1.substr(3,2);
        
        string years = s1.substr(6,4);
          
        
          if (months=="01")
                month="JANUARY";

            else 
            if(months=="02")
                month="FEBRUARY";

            else 
            if (months=="03")
                month="MARCH";

            else 
            if (months=="04")
                month="APRIL";

            else 
            if (months=="05")
                month="MAY";

            else 
            if(months=="06")
                month="JUNE";

            else 
            if (months=="07")
                month="JULY";

            else 
            if (months=="08")
                month="AUGUST";

            else 
            if (months=="09")
                month="SEPTEMBER";

            else 
            if (months=="10")
                month="OCTOBER";


else 
            if (months=="11")
                month="NOVEMBER";
                
            else
                month="DECEMBER";
          
          
          
          cout << days <<" "<< month <<" "<< years <<endl;
    
}


string DisplayStatus(int status)
{
    string s;

	if(status == 1)
    {
		s = "BORROWED [SUBMITTED]";
	}
	else 
    if(status == 2){
		s = "BORROWED [APPROVED]";
	}
    else
    if(status == 0)
    {
		s = "AVAILABLE";
	}
    return s;
}

class BookList
{
    private:
        BookNode *head;
        BookNode *tail;

    public:
    friend class LibraryQueue;
    BookList()
    {
        head = NULL;
        tail = NULL;
    }
    // Mutator

    void setStatus(string status, int BookId)
    {
        BookNode *temp = head;
        
        while(temp != NULL)
        {
            if(temp->refNum == BookId )
            {
                if(status == "BORROWED [SUBMITTED]")
                {
                    temp->status = 1;
                }
                else 
                if(status == "BORROWED [APPROVED]"){
                    temp->status = 2;
                }
                else 
                if(status == "AVAILABLE")
                {
                    temp->status = 0;
                }
            }
            temp = temp->next;
        }
    }
    // Accessors
    int getStatus(int BookId)
    {
        BookNode *temp = head;

        int s;

        while(temp !=NULL){
            if(BookId == temp->refNum)
            {
                s = temp->status; // Return the integer value
            }

            temp = temp->next;
        }

        return s;
    }
    string getAuthor(int id)
    {
        BookNode *temp = head;
        string a;
    
        while(temp != NULL)
        {
            if(id == temp->refNum)
            {
                a = temp->author;
            }
            temp = temp->next;
        }

        return a;
    }
    string getTitle(int id)
    {
        string t;

        BookNode *temp = head;
        while(temp != NULL)
        {
            if(id == temp->refNum)
            {
                t = temp->title;
            }
            temp = temp->next;
        }
        return t;
    }
    string getDate(int id)
    {
        string d;

        BookNode *temp = head;
        while(temp != NULL)
        {
            if(id == temp->refNum)
            {
                d = temp->date;
            }
            temp = temp->next;
        }

        return d;
    }
    string getType(int id)
    {
        string t;

        BookNode *temp = head;
        while(temp != NULL)
        {
            if(id == temp->refNum)
            {
                t = temp->type;
            }
            temp = temp->next;
        }
        return t;
    }

    bool isEmpty()
    {
        return head = NULL;
    
    }
    // Approval from admin
    int ApprovalAdmin(int _status)
    {
        int status; // It will return status Borrowed[Approved] or Return[Approved]

        if(_status == 1 ) // Borrowed [Submitted]
        {
            return (status == 2);
        }
    }
    // Insert the node on empty list
    void insertOnEmptyList(BookNode *newNode)
    {
        head = newNode;
        tail = newNode;
        head->bef = NULL;
        tail->next = NULL;

    }
    // Insert default node in the list (in front of the list)
    void insertDefaultNode(BookNode *newNode)
    {
        newNode->next = head;
        head->bef = newNode;
        head = newNode;
    }
    void readFile()
    {
        ifstream fin;
        int count = 0;

        string title;
        string author;
        string date;
        string type;
        int refNum;
        int status;

        fin.open("bookinputfile.txt");

        if(fin.fail())
        {
            exit(0);
        }
        while(getline(fin,title,','))
        {
            getline(fin,author,',');

            fin >> date;

            fin >> type;

            fin >> refNum;

            fin.ignore();

            count++;

            BookNode *newNode = new BookNode(title,author,date,type,refNum);

            if(count == 1)
            {
                insertOnEmptyList(newNode);
            }
            else
            {
                insertDefaultNode(newNode);
            }
        }

        fin.close();

    }
    BookNode* findBook(int bookId)
    {			
        BookNode* currNode = head;
        int currIndex = 1;

        while (currNode && currNode->refNum != bookId) 
        {
            currNode = currNode->next;
            currIndex++;
        }
        if (currNode)
            return currNode;
        else
        return 0;
	}
    
    //Insert New Node in Front of The List
    void insertNewNode(string _title, string _author, string _date, string _type, int bookId, int &size)
    {
        BookNode *nn = new BookNode;

		nn->title = _title;
        nn->author = _author;
        nn->date = _date;
        nn->type = _type;
        nn->refNum = bookId;
        nn->status = 0; // Default values for all new added node
        //nn->refNum = _refNum;

		nn->bef = NULL;
        nn->next = NULL;
        
		int opt;
        BookNode *tmp = head;
        
       	cout << "\n\t\t\t\t ==================== [ STUDENT MENU ] ====================";
        cout << "\n\n\t\t\t\t CHOOSE YOUR OPTION : \n"
             << "\n\t\t\t\t 	   [1] INSERT BOOK IN FRONT OF THE LIST"
             << "\n\t\t\t\t 	   [2] INSERT BOOK AT THE MIDDLE OF THE LIST"
             << "\n\t\t\t\t 	   [3] INSERT BOOK AT THE END OF THE LIST \n\n"
             << "\n\t\t\t\t YOUR OPTION : "; 
                
        cin >> opt;
        
        switch(opt)  
        {
            //Insert the node in front of the list
            case 1: 
            {
                nn->next = head;
                head->bef =nn;
        
                head = nn;
                
                size++;
                
                break;
            }
            // Insert the node in the middle of the list (anywhere that user want to put the node)
            case 2:
            {
                int ch;
        
                cout << "\n\t\t\t\t What position would you like to enter the new books data ? " << endl;
                cout << "\n\t\t\t\t Choice : ";
                cin >> ch;

                BookNode *tmp;

                tmp = head;
                int i = 1;

                while (i < (ch-1)) 
                {
                    tmp = tmp->next;
                    i++;
                }
		        nn->next = tmp->next;
                tmp->next->bef = nn;
                tmp->next = nn;
                nn->bef = tmp;

                size++;

                break;
            }
            case 3: // Insert on the last position of the list
            {
                tail->next = nn;
                tail = nn;

                size++;

        
                break; 
            } 
            default:
            {
    				cout << "INPUT DATA IS WRONG!" << endl;
                break;
            }

        }
    }
    void removeNode(int ch)
    {
        BookNode *tmp = head, *delnode;
        int i = 1;

        while(i< (ch-1)){
            tmp = tmp -> next;
            i++;
        }
    
            delnode = tmp -> next;    
            delnode -> next -> bef = tmp;
            tmp -> next= delnode -> next;
            delnode -> next = NULL;
            delnode -> bef = NULL;

        delete delnode; 

        cout << "\n\t\t\t      *******  RETURN BOOK PROCESS IS SUCCESSFUL   *******     " << endl << endl;

        cout << "\n\t\t\t                    PRESS ANY KEY TO CONTINUE      ";
        getch();
        
    }
    void sortingTheNode(int size)
    {
        int choiceSorting;
        int choiceOrder;

        string tempValue;

         cout << "\n\t\t\t\t ------------------------------------------------------\n";
        cout << "\n\t\t\t\t                       DATA SORTING               \n";
        cout << "\n\t\t\t\t ------------------------------------------------------\n";
        cout << "\n\t\t\t\t CHOOSE YOUR OPTION :\n"
                << "\n\t\t\t\t		    [1] SORT BY TITLE"
                << "\n\t\t\t\t		    [2] SORT BY AUTHOR"
                << "\n\t\t\t\t\t            [3] SORT BY BOOK ID"
                << "\n\t\t\t\t\t            [4] SORT BY STATUS\n\n"
                << "\n\t\t\t\t YOUR OPTION: ";
        
        cin >> choiceSorting;

        // SORTING BY TITLE

        if(choiceSorting == 1)
        {

            cout << "\n\t\t\t\t ------------------------------------------------------\n";
            cout << "\n\t\t\t\t                          ORDER                      \n";
        	cout << "\n\t\t\t\t ------------------------------------------------------\n";
        	cout << "\n\t\t\t\t CHOOSE YOUR OPTION :\n"
                 << "\n\t\t\t\t		    [1] ASCENDING "
                 << "\n\t\t\t\t		    [2] DESCENDING"
                 << "\n\t\t\t\t YOUR OPTION: ";
            
            cin >> choiceOrder;

            //Ascending
            if(choiceOrder == 1)
            {
                    for (int pass = 1; pass < size; pass += 1) 
                    {
					BookNode *node;
                    node = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node;
						   BookNode *second = node -> next;

						    if (first -> title > second -> title) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;

                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;

                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;

                            }
                            node = node -> next;
						}
                    }
                cout << "\n\t\t\t\t    ***** SORTED INCREASING BY TITLE COMPLETED *****    " << endl;
            }     
            else
            if(choiceOrder == 2) // DESCENDING
            {
                for (int pass = 1; pass < size; pass += 1) 
                {
					BookNode *node2;
                    node2 = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node2;
						    BookNode *second = node2 -> next;

						    if (first -> title < second -> title) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;
                                
                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;
                                
                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;
                            }
                            node2 = node2 -> next;
						}
                }
                cout << "\n\t\t\t\t    ***** SORTED DECREASING BY TITLE COMPLETED *****    " << endl;

            } 
            
        }
        // SORTING BY AUTHOR
        else if(choiceSorting == 2) 
        {
            cout << "\n\t\t\t\t ------------------------------------------------------\n";
            cout << "\n\t\t\t\t                          ORDER                      \n";
        	cout << "\n\t\t\t\t ------------------------------------------------------\n";
        	cout << "\n\t\t\t\t CHOOSE YOUR OPTION :\n"
                 << "\n\t\t\t\t		    [1] ASCENDING "
                 << "\n\t\t\t\t		    [2] DESCENDING"
                 << "\n\t\t\t\t YOUR OPTION: ";
            
            cin >> choiceOrder;

            //Ascending
            if(choiceOrder == 1)
            {
                    for (int pass = 1; pass < size; pass += 1) 
                    {
					BookNode *node;
                    node = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node;
						    BookNode *second = node -> next;

						    if (first -> author > second -> author) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;
                                
                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;

                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;

                            }
                            node = node -> next;
						}
                    }
                cout << "\n\t\t\t\t    ***** SORTED INCREASING BY AUTHOR COMPLETED *****    " << endl;
            }     
            else
            if(choiceOrder == 2) // DESCENDING
            {
                for (int pass = 1; pass < size; pass += 1) 
                {
					BookNode *node2;
                    node2 = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node2;
						    BookNode *second = node2 -> next;

						    if (first -> author < second -> author) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;
                                
                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;

                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;

                            }
                            node2 = node2 -> next;
						}
                }
                cout << "\n\t\t\t\t   ***** SORTED DECREASING BY AUTHOR COMPLETED *****    " << endl;

            } 

        }
        
        // SORTING BY REFERENCE NUMBER
        else if(choiceSorting == 3) 
        {
            cout << "\n\t\t\t\t ------------------------------------------------------\n";
            cout << "\n\t\t\t\t                          ORDER                      \n";
        	cout << "\n\t\t\t\t ------------------------------------------------------\n";
        	cout << "\n\t\t\t\t CHOOSE YOUR OPTION :\n"
                 << "\n\t\t\t\t		    [1] ASCENDING "
                 << "\n\t\t\t\t		    [2] DESCENDING"
                 << "\n\t\t\t\t YOUR OPTION: ";
            
            cin >> choiceOrder;

            //Ascending
            if(choiceOrder == 1)
            {
                    for (int pass = 1; pass < size; pass += 1) 
                    {
					BookNode *node;
                    node = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node;
						    BookNode *second = node -> next;

						    if (first->refNum > second->refNum) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;
                                
                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;

                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;

                            }
                            node = node -> next;
						}
                    }
                cout << "\n\n\t\t\t\t                        SORTED INCREASING BY REFERENCE NUMBER COMPLETED          " << endl;
            }     
            else
            if(choiceOrder == 2) // DESCENDING
            {
                for (int pass = 1; pass < size; pass += 1) 
                {
					BookNode *node2;
                    node2 = head;

                        for (int x = 0; x < size - pass; x += 1) 
                        {
                            // Compare
						    BookNode *first = node2;
						    BookNode *second = node2 -> next;

						    if (first ->refNum < second ->refNum) 
                            {
                                // swap the item in the node
                                string temp;
                                int tmp;

                                temp = first->author;
                                first->author = second->author;
                                second->author = temp;

                                temp = first->title;
                                first->title = second->title;
                                second->title = temp;
                                
                                temp = first->date;
                                first->date = second->date;
                                second->date = temp;

                                temp = first->type;
                                first->type = second->type;
                                second->type = temp;
                                
                                tmp = first->refNum;
                                first->refNum = second->refNum;
                                second->refNum = tmp;

                                tmp = first->status;
                                first->status = second->status;
                                second->status = tmp;

                            }
                            node2 = node2 -> next;
						}
                }
                cout << "\n\n                        SORTED DECREASING BY REFERENCE NUMBER COMPLETED          " << endl;

            } 

        }
        
        //SORTING BY STATUS
        else 
		{
            for(int pass = 1; pass < size; pass += 1) 
            {
				BookNode *node2;
                node2 = head;

                    for (int x = 0; x < size - pass; x += 1) 
                    {
                        // Compare
					    BookNode *first = node2;
					    BookNode *second = node2 -> next;

					    if (first -> status < second -> status) 
                        {
                            // swap the item in the node
                            string temp;
                            int tmp;

                            temp = first->author;
                            first->author = second->author;
                            second->author = temp;

                            temp = first->title;
                            first->title = second->title;
                            second->title = temp;
                            
                            temp = first->date;
                            first->date = second->date;
                            second->date = temp;

                            temp = first->type;
                            first->type = second->type;
                            second->type = temp;
                            
                            tmp = first->refNum;
                            first->refNum = second->refNum;
                            second->refNum = tmp;

                            tmp = first->status;
                            first->status = second->status;
                            second->status = tmp;

                        }
                        node2 = node2 -> next;
					}
					
            }

        } 
    }

    //Print all of the infomations inside the node
    void PrintDetails () // to print all data in the list in forward order.
    {
        BookNode *temp;

        temp = head;
        cout << " \n===================================================== BOOKS ============================================================================= " << endl;
            cout << left << setw(3) << " " << "NO" << setw(5) << " " << "BOOK ID"<< setw(12) << " " << "TITLE" << setw(15) << " " << "AUTHOR" << setw(18)  << " " << "YEAR" << setw(18) << " " << "TYPE" << setw(18) << " " << "STATUS" <<  endl;
            cout << "======================================================================================================================================== " << endl;
            int i = 0;

            while(temp!=NULL)
            {   
                if((i+1)>9)
                    cout << setw(1) << " " << "["<< i+1 << "]" << setw(6) << " "; 
                else
                {
                    cout << setw(2) << " " << "["<< i+1 << "]" << setw(6) << " ";
                }

                cout << setw(10) << temp->refNum
                     << setw(25) << temp->title
                     << setw(25) << temp->author
                     << setw(24) << temp->date
                     << setw(23) <<temp->type 
                     << DisplayStatus(temp->status) << endl; 

                temp = temp->next;                 
                i++;
            }
            cout<<endl;

            cout << "\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE..";
            getch();
    }

    //Deleting the first node
    void deleteNode(int &size)
    {
        BookNode *tmp = head;
		int delNodeChoice;

		cout << "\n\t\t\t\t =============== [ DELETE BOOK MENU ] ================";
        cout << "\n\n\t\t\t\t CHOOSE YOUR OPTION : \n" << endl
             << "\t\t\t\t 	[1] DELETE THE FIRST BOOK IN THE LIST" << endl
             << "\t\t\t\t 	[2] DELETE THE MIDDLE BOOK IN THE LIST" << endl
             << "\t\t\t\t	[3] DELETE THE LAST BOOK IN THE LIST" << endl;

        cout << " \n\t\t\t\t YOUR OPTION : ";

        cin >> delNodeChoice;
        
        switch (delNodeChoice)
        {
            // DELETE THE FIRST NODE
            case 1:
            {
             	BookNode *temp;

                temp = head;
                head = head->next;

                temp->next = NULL;

                delete temp;

                size--;
        
                break;
            }
            //DELETE THE MIDDLE NODE
            case 2:
            {
                int ch;
        
                cout << "\n\t\t\t\t What position would you like to delete the new books data ? " << endl;
                cout << "\n\t\t\t\t Choice : ";
                cin >> ch;

                int i = 1;
				BookNode *tmp = head, *delnode;
			
				while(i< (ch-1)){
					tmp = tmp -> next;
					i++;
								}
			
				    delnode = tmp -> next;    
				    delnode -> next -> bef = tmp;
				    tmp -> next= delnode -> next;
				    delnode -> next = NULL;
				    delnode -> bef = NULL;

				delete delnode;   

                size--; 

                break;
            }
            // DELETE THE LAST NODE
            case 3:
            {        
                BookNode *temp = tail;

                tail = temp->bef;
                tail->next = NULL;
                temp ->bef = NULL;

                delete temp;

                size--;

                break;

            }
        }

    }
    int findPosition(int id)
    {
        BookNode *temp = head;
        int i = 0;

        while(temp!= NULL)
        {
            if(temp->refNum == id)
            {
                return i;
            }
            temp = temp->next;
            i++;
        }
        return 100; // If the id is not exist
    }
    // SEARCH THE INFORMATION IN THE LIST
    void searchNode()
    {
        BookNode *temp;

        int choice;
        bool found; 

        system("cls");
        
        cout << "\n\t\t\t\t     HOW WOULD YOU LIKE TO SEARCH THE BOOK ? " << endl
             << "\t\t\t\t           [1] SEARCH BY TITLE "   << endl
             << "\t\t\t\t           [2] SEARCH BY AUTHOR"   << endl
             << "\t\t\t\t           [3] SEARCH BY BOOK ID"  << endl
             << "\t\t\t\t           [4] SEARCH BY YEAR PUBLISHED" << endl;
           
        cout << "\n\t\t\t\t YOUR OPTION : ";
        cin >> choice;

        switch (choice)
        {
            // SEARCH BY TITLE
            case 1:
            {
                temp = head;

                string _title;

                cin.ignore();

                cout << "\n\t\t\t\t ENTER THE TITLE OF THE BOOK ( in CAPITAL LETTERS ): ";
                getline(cin,_title);

                found = false;
                
                while(!found && temp!= NULL)
                {
                    //CASE SENSITIVE
                    if( temp->title == _title )
                    {
                        found = true;

                        cout << "\n\t\t\t\t THESE ARE THE INFORMATION FOR THE BOOK THAT YOU HAVE SEARCHED BY TITLE : " << endl << endl
                             << "\t\t\t\t BOOK ID        : " << temp->refNum << endl
                             << "\t\t\t\t TITLE          : " << temp->title  << endl
                             << "\t\t\t\t AUTHOR         : " << temp->author << endl
                             << "\t\t\t\t YEAR PUBLISHED : " << temp->date   << endl
                             << "\t\t\t\t TYPE           : " << temp->type   << endl;
                        
                        break;
                    }
                    temp = temp->next;
                }
                if(!found)
                    cout << "\n\t\t\t\t SORRY ! THE BOOKS THAT YOU ENTERED IS NOT IN THE LIST...." << endl;
                    
                break;
            }
            //SEARCH BY AUTHOR
            case 2:
            {
                found = false;

                temp = head;

                string _author;

                cin.ignore();

                cout << "\n\t\t\t\t ENTER THE AUTHOR OF THE BOOK ( in CAPITAL LETTERS ): ";
                getline(cin,_author);

                int i = 0;
                while(!found && temp!= NULL)
                {
                    //CASE SENSITIVE

                    if(temp->author == _author )
                    {
                        found = true;

                        cout << "\n\t\t\t\t THESE ARE THE INFORMATION FOR THE BOOK THAT YOU HAVE SEARCHED BY AUTHOR : " << endl << endl
                             << "\t\t\t\t BOOK ID        : " << temp->refNum << endl
                             << "\t\t\t\t TITLE          : " << temp->title  << endl
                             << "\t\t\t\t AUTHOR         : " << temp->author << endl
                             << "\t\t\t\t YEAR PUBLISHED : " << temp->date   << endl
                             << "\t\t\t\t TYPE           : " << temp->type   << endl;

                        break;
                    }
                    temp = temp->next;
                    i++;
                }
                if(!found)
                    cout << "\n\t\t\t\t SORRY ! THE BOOKS THAT YOU ENTERED IS NOT IN THE LIST...." << endl;
                    
                break;
            }
            case 3:
            {
                temp = head;

                int id;

                cout << "\n\t\t\t\t ENTER THE BOOK ID OF THE BOOK ( eg 1000 ): ";
                cin >> id;
                
                while(!found && temp!= NULL)
                {
                    //CASE SENSITIVE
                    if( temp->refNum == id)
                    {
                        found = true;

                        cout << "\n\t\t\t\t THESE ARE THE INFORMATION FOR THE BOOK THAT YOU HAVE SEARCHED BY BOOK ID: " << endl << endl
                             << "\t\t\t\t BOOK ID        : " << temp->refNum << endl
                             << "\t\t\t\t TITLE          : " << temp->title  << endl
                             << "\t\t\t\t AUTHOR         : " << temp->author << endl
                             << "\t\t\t\t YEAR PUBLISHED : " << temp->date   << endl
                             << "\t\t\t\t TYPE           : " << temp->type   << endl;
                        
                        break;
                    }
                    temp = temp->next;
                }
                if(!found)
                    cout << "\n\t\t\t\t SORRY ! THE BOOKS THAT YOU ENTERED IS NOT IN THE LIST...." << endl;
                    
                break;
            }
            case 4:
            {
                temp = head;

                found = false;

                string year;

                cin.ignore();

                cout << "\n\t\t\t\t ENTER THE YEAR OF PUBLISHED OF THE BOOK ( eg 2021 ): ";
                getline(cin,year);
                
                while(temp!= NULL)
                {
                    //CASE SENSITIVE
                    if( temp->date == year)
                    {
                        found = true;

                        cout << "\t\t\t\t THESE ARE THE INFORMATION FOR THE BOOK THAT YOU HAVE SEARCHED BY YEAR OF PUBLISHED : " << endl 
                             << "\t\t\t\t BOOK ID        : " << temp->refNum << endl
                             << "\t\t\t\t TITLE          : " << temp->title  << endl
                             << "\t\t\t\t AUTHOR         : " << temp->author << endl
                             << "\t\t\t\t YEAR PUBLISHED : " << temp->date   << endl
                             << "\t\t\t\t TYPE           : " << temp->type   << endl;
                    }
                    temp = temp->next;
                    cout << endl;
                }
                if(found == false)
                    cout << "\n\t\t\t\t SORRY ! THE BOOKS THAT YOU ENTERED IS NOT IN THE LIST...." << endl;
               
                break;

            }
        }

        cout << "\n\n\t\t\t\t PRESS ANY KEY TO CONTINUE...";
        getch();
    }

};

class LibraryNode
{
    public:
        string name;
        string matricNum;
        string dateBorrowed;
        string dateReturned;
        int totalDuration;
        int bookId;
        string title;
        string author;
        string date;
        string type;
        int status;

        LibraryNode *next;

        LibraryNode()
        {
            next = NULL;
        }
};

class LibraryQueue
{
    private:
        LibraryNode *front;
        LibraryNode *back;
    
    public:
        friend class BookList;
    
        //Mutators
        
        void createQueue()
        {
            front = NULL;
            back = NULL;
        }
        bool isEmpty()
        {
            return (front == NULL && back == NULL);
        }
        void enQueue(string n, string m, string db, string dr, int td, int bId, string a, string t, string d, string _t)
        {
            BookList book;

            LibraryNode *newNode = new LibraryNode;
            newNode->name = n; // Name
            newNode->matricNum = m; // Matric number
            newNode->dateBorrowed = db; // Date borrow the book
            newNode->dateReturned = dr; // Date return the book
            newNode->totalDuration = td; // Total duration of borrowing the book
            newNode->bookId = bId; // Book Id
            newNode->author = a; // Author
            newNode->title = t; // Title
            newNode->date = d;
            newNode->type = _t;
            newNode->status = 0;

            if(isEmpty())
            {
                back = newNode;
                front = newNode;
            }
            else
            {
                back->next = newNode;
                back = newNode;
            }
        }

        void deQueue() // If the student has return the book. It will be deleted from the list
        {
            LibraryNode *temp;
            temp = front;
            

            if(!front)
            {
                back = NULL;
            }
            if(isEmpty())
            {
                cout << "\n\n\t\t\t   ------                          ELYSIUM LIBRARY                     --------" << endl;
                cout << "\t\t\t   ------                  UNIVERSITY OF TECHNOLOGY MALAYSIA           --------" << endl;
                cout << "\t\t\t   ------              STUDENTS' APPLICATION TO BORROW A BOOK          --------" << endl << endl;

                cout << "\n\t\t\t            *******  NO APPLICATION HAS BEEN MADE BY THE STUDENT  *******     " << endl;

                cout << "\n\n\t\t\t\t PRESS ANY KEY TO CONTINUE...";

                getch();
            }
            else
            {
                front = front->next;
                temp->next = NULL;
                delete temp;
            }
        }
        
        void printApplication() // PRINT ALL APPLICATION
        {
            LibraryNode *tmp = front;
            int a,b;

            if(isEmpty())
            {
                system("cls");

                cout << "\n\n\t\t\t   ------                          ELYSIUM LIBRARY                     --------" << endl;
                cout << "\t\t\t   ------                  UNIVERSITY OF TECHNOLOGY MALAYSIA           --------" << endl;
                cout << "\t\t\t   ------              STUDENTS' APPLICATION TO BORROW A BOOK          --------" << endl << endl;

                cout << "\n\t\t\t           *******  NO APPLICATION HAS BEEN MADE BY THE STUDENT  *******     " << endl;

                cout << "\n\n\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE...";
                
                getch();

                return;  
            }
            else
            {
                
                int i = 0;

                cout << "\n\n\t\t\t   ------                          ELYSIUM LIBRARY                     --------" << endl;
                cout << "\t\t\t   ------                  UNIVERSITY OF TECHNOLOGY MALAYSIA           --------" << endl;
                cout << "\t\t\t   ------              STUDENTS' APPLICATION TO BORROW A BOOK          --------" << endl;

                cout << "\n\n\t\t\t\t     NAME               : " << tmp->name << endl;
                cout << "\t\t\t\t     MATRIC NUMBER      : " << tmp->matricNum << endl;

                cout << "\n\t\t\t   ----------------------------------------------------------------------------" << endl;

                         cout << "\t\t\t                                  APPLICATIONS      " << endl;

                while(tmp != NULL)
                {
                    tmp->status = 1;
           

                    cout << "\n\t\t\tAPPLICATION " <<"[" << i + 1 << "]" << endl 
                         << "\t\t\t\t\t     TITLE               : " << tmp->title  << endl 
                         << "\t\t\t\t\t     AUTHOR              : " << tmp->author << endl
                         << "\t\t\t\t\t     PUBLISHED DATE      : " << tmp->date   << endl
                         << "\t\t\t\t\t     TYPE                : " << tmp->type   << endl;
                    

                    cout << "\n\t\t\t   ----------------------------------------------------------------------------" << endl;

                    cout << "\n\t\t\t                      DETAILS OF THE BORROWING TRANSACTIONS " << endl << endl;

                
                    cout << "\t\t\t\t\t     BORROWED DATE       : ";
                    getDateBorrowed(tmp->dateBorrowed);
                    cout << "\t\t\t\t\t     RETURN DATE         : ";
                    getDateReturned(tmp->dateReturned);

                    a = convertDateB(tmp->dateBorrowed);
                    b = convertDateR(tmp->dateReturned);     

                    cout << "\t\t\t\t\t     TOTAL BORROWING DAY : " <<  getTotalDays(a,b) << " DAYS";

            
                    cout << "\n\t\t\t\t\t     STATUS              : " << DisplayStatus(tmp->status) << endl;
                
                 

                    cout << "\n\t\t\t   ----------------------------------------------------------------------------" << endl;
                    
                    cout << endl << endl;
                    tmp = tmp->next;   
                    i++;              
                }

                cout << "\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE..";
                getch();

            }
        }
        void ApprovalApplication(BookList list)
        {
            LibraryNode *tmp = front, *tmp2;
            int a,b;
            string status;
            int choice;
            int count = 0;
            int i = 0;
            char ch;

            system("cls");

            while(tmp != NULL)
            {
                system("cls");

                cout << "\n\t\t\t\t------------------------------------------------------" << endl;
                cout << "\t\t\t\t-----     REVIEWING THE STUDENTS APPLICATION    ------" << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                cout << "\n\t\t\t\t\t\t  APPLICATION TO BOOK " << i + 1 << endl;

                 cout << "\n\t\t\t\tTITLE             : " << tmp->title << endl 
                      << "\t\t\t\tAUTHOR            : " << tmp->author << endl
                      << "\t\t\t\tPUBLISHED DATE    : " << tmp->date << endl
                      << "\t\t\t\tTYPE              : " << tmp->type << endl
                      << "\t\t\t\tBOOK ID           : " << tmp->bookId << endl;

                cout << "\t\t\t\t------------------------------------------------------" << endl;
                
                cout << "\n\n\t\t\t\t\tDETAILS OF THE BORROWING TRANSACTIONS " << endl;

                //cout << "\n\t\t\t\tBORROWED DATE      : " << tmp->dateBorrowed << endl;
                
                //cout << "\t\t\t\tRETURN DATE        : " << tmp->dateReturned << endl;

                    cout << "\n\t\t\t\tBORROWED DATE       : ";
                    getDateBorrowed(tmp->dateBorrowed);
                    cout << "\t\t\t\tRETURN DATE         : ";
                    getDateReturned(tmp->dateReturned);

                      a = convertDateB(tmp->dateBorrowed);
                    b = convertDateR(tmp->dateReturned);
                    
                    cout << "\t\t\t\tTOTAL BORROWING DAY : " << getTotalDays(a,b);
                    
                    cout << " DAYS " << endl;
                
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                cout << "\n\t\t\t\t\tDO YOU WANT TO APPROVE THIS APPLICATION ? " << endl;
                cout << "\n\t\t\t\t\t   [1]  YES " << endl
                     << "\t\t\t\t\t   [0]  NO " << endl; 
                cout << "\n\t\t\t\t\tCHOICE     : ";
                cin >> choice;

                if(choice == 1)
                {
                    status = DisplayStatus(2); // Set in the default list of book in the library
                    tmp->status = 2;          
                    list.setStatus(status,tmp->bookId);

                    tmp2 = tmp;
                    tmp = tmp->next;
                    deQueue(); // Queue Implementation
                }
                i++;

                cout << "\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE..";
                getch();
            }
        }
};

int DisplayMainMenu()
{
    int choiceMain;

    system("cls");

    cout << "					   WELCOME TO ELYSIUM LIBRARY					" << endl;
    cout << "\t\t\t              UNIVERSITY OF TECHNOLOGY MALAYSIA               " << endl;
    cout << "\n\t\t\t\t =============== [ MAIN MENU ] ===============";
    cout << " \n\n\t\t\t\t LOG IN AS : \n"
            << "\t\t\t\t 		[1] LIBRARY ADMIN" << endl
            << "\t\t\t\t 		[2] STUDENT" << endl
            << "\t\t\t\t 		[3] EXIT THE SYSTEM" << endl;
        
    cout << " \n\t\t\t\t YOUR OPTION : ";
    cin >> choiceMain;

    return choiceMain;
}

int DisplayStudentMenu()
{
    int choice;

    system("cls");

    cout << "\n\t\t\t\t ============= [ STUDENT MENU ] =============";
    cout << "\n\t\t\t\t CHOOSE YOUR OPTION\n"
        << "\t\t\t\t		[1] PRINT THE LIST OF BOOK" << endl
        << "\t\t\t\t		[2] BORROW A BOOK" << endl
        << "\t\t\t\t		[3] RETURN A BOOK" << endl
        << "\t\t\t\t\t        [4] SEARCH A BOOK" << endl
        << "\t\t\t\t\t        [5] SORT THE BOOKS" << endl
        << "\t\t\t\t		[0] BACK TO MAIN MENU " << endl;

    cout << "\n\t\t\t\t YOUR OPTION : ";
    
    cin >> choice;

    return choice;

}

int DisplayAdminMenu()
{
    system("cls");

    int choice;

    cout << "\n\t\t\t\t =============== [ LIBRARY STAFF MENU ] ===============";
           
            cout << "\n\n\t\t\t\t CHOOSE YOUR OPTION : \n\n"
                << "\t\t\t\t 		 [1] INSERT NEW BOOKS" << endl
                << "\t\t\t\t 		 [2] DELETE THE BOOKS" << endl
                << "\t\t\t\t 		 [3] SEARCH THE BOOKS" << endl
                << "\t\t\t\t 		 [4] PRINT THE BOOKS" << endl
                << "\t\t\t\t 		 [5] SORT THE BOOKS"  << endl
                << "\t\t\t\t 		 [6] REVIEW STUDENTS' APPLICATION"  << endl // Queue Implementation
                << "\t\t\t\t 		 [0] BACK TO MAIN MENU" << endl;

            cout << " \n\t\t\t\t YOUR OPTION : ";
            
            cin >> choice;

            return choice;
}

int main()
{
    BookList list; //  A student can only borrowed maximum 5 books
    LibraryQueue libQ;
    BookList listReturn;

    int s;
    int count = 0;
    int bookId;
    int size = N;
    int choice;
    int booksize;


    string name;
    string matricNum;
    string title;
    string author;
    string date;
    string type;
    string status;
    string doB[N];
    string doR[N];
    int id[N];


    libQ.createQueue();
    list.readFile();
   
    // There are actually default books in the list currently...
    int choiceMain;
    int ch;

    A:
        choiceMain = DisplayMainMenu();

    do
    {
        switch (choiceMain)
        {
        case 1:
        {
            system("cls");
            
 			int choice;

            choice = DisplayAdminMenu();

            do
            {
                switch (choice)
                {
                    //Insert new item in the list
                    case 1:
                        system("cls");

                        cout << "\n\t\t\t\t ==================== [ ADD BOOK ] ===================="<< endl << endl;
                        
                        cout << "\n\t\t\t\t Enter the details of the books that you want to enter"
                            << "\n\t\t\t\t in the list " << endl << endl;
                        
                        cin.ignore();

                        cout << "\t\t\t\t TITLE  [DATA STRUCTURE AND ANALYSIS] : ";
                        getline(cin,title);
                        cout << "\t\t\t\t AUTHOR [DR LIZAWATI BINTI YUSOF]     : ";
                        getline(cin,author);
                        cout << "\t\t\t\t DATE   [20/12/2022]                  : ";
                        getline(cin,date);
                        cout << "\t\t\t\t TYPE   [NON-FICTION]                 : ";
                        getline(cin,type);
                        cout << "\t\t\t\t TYPE   [BOOK ID]                     : ";
                        cin >> bookId;

                
                        cout << endl << endl;

                        list.insertNewNode(title,author,date,type,bookId,size); 

                        break;

                    //DELETE THE NODES
                    case 2:
                        list.deleteNode(size);
                
                        break;
                    
                    // Search the nodes
                    case 3:
                        list.searchNode();

                        break;

                    // Printing all the details in the list
                    case 4:
                        list.PrintDetails();   
                        break;    
                    case 5:
                        list.sortingTheNode(size);
                        list.PrintDetails();
                        break;

                    case 6:
                    {
                        int id;

                        // Print all the request made by the student (Queue implementation)
                        libQ.printApplication();

                        // Admin will approve the students application to borrow the book
                        libQ.ApprovalApplication(list);  

                        
                    }
                }

                choice = DisplayAdminMenu();

                if(choice == 0)
                    goto A;

            }while(choice != 0);

            break;
        }
        // Student Menu
        case 2:
        {
           // system("cls");  -- kalau letak system cls kat sini nanti bila print books dia tak keluar

            int choiceStudent;
            choiceStudent = DisplayStudentMenu();

            do 
            {
                switch (choiceStudent)
                {
                    //Print the details of the books in the library system
                    case 1:
                    {
                        list.PrintDetails();

                        break;
                    }
                    //Borrow a book 
                    case 2:
                    {
                        string dateBorrowed;
                        string dateReturned;
                        int totalDuration;
                        string author;
                        string title;
                        string date;
                        string type;
                        int totalD;
                        int position = 0;

                        int loop = 1;
                        int choiceLoop;

                        system("cls");

                        cout << "\n\n\t\t   ------                          ELYSIUM LIBRARY                     --------" << endl;
                        cout << "\t\t   ------                  UNIVERSITY OF TECHNOLOGY MALAYSIA           --------" << endl;
                        cout << "\t\t   ------                          [BORROW A BOOK]                     --------" << endl;

                        cin.ignore();

                        if(count == 0)
                        {
                            cout << "\n\t\t\tNAME             : ";
                            getline(cin,name);
                            cout << "\t\t\tMATRIC NUMBER    : ";
                            getline(cin,matricNum);
                        }
                        do
                        {
                            
                        
                            cout << "\n\t\t\tWHAT IS THE BOOK ID THAT YOU WOULD LIKE TO BORROW ? " << endl;
                            cout << "\t\t\tBOOK ID [eg 1002,1003 ]  : ";
                            cin >> bookId;

                            if(list.findBook(bookId) && ( list.getStatus(bookId) != 1 || list.getStatus(bookId) != 2) )
                            {
                                cout << "\n\n\t\t   ------                          INFORMATION                         --------" << endl;
                                
                                cout << "\n\n\t\t\t                     THE BOOK IS IN THE LIST   " << endl;

                                title = list.getTitle(bookId);
                                author = list.getAuthor(bookId);
                                date = list.getDate(bookId);
                                type = list.getType(bookId);

                                cout << "\n\t\t\tTITLE             : " << title << endl;
                                cout << "\t\t\tAUTHOR            : " << author << endl;
                                cout << "\t\t\tPUBLISHED DATE    : " << date << endl;
                                cout << "\t\t\tTYPE              : " << type << endl;

                                
                                cout <<"\n\n\t\t\tREMINDER TO STUDENTS : ~ YOU NEED TO PUT RETURN DATE MAXIMUM 2     " << endl
                                     <<"\t\t\t                         WEEKS (14 DAYS) FROM THE DAY YOU BORROWED " << endl << endl 
                                     <<"\t\t\t                       ~ DATE BORROWED IS CURRENT DATE             " << endl << endl;

                                
                                cin.ignore();
                                int a,b,total;
                                bool verify;
                                
                                do 
                                {
                                    verify = false;
                                    cout << "\n\t\t\tDATE BORROWED (DD/MM/YYYY) : ";
                                    getline(cin,dateBorrowed);
                                    
                                    cout << "\t\t\tDATE RETURNED (DD/MM/YYYY) : ";
                                    getline(cin,dateReturned);

                                    a = convertDateB(dateBorrowed);
                                    b = convertDateR(dateReturned);
                                    total = getTotalDays(a,b);

                                    if(total > 14)
                                    {
                                        cout << "\n\n\t\t\tYOU HAVE EXCEEDED THE MAXIMUM DAYS TO BORROW THE BOOK.   " << endl;
                                        cout << "\t\t\t              PRESS ANY KEY TO CONTINUE.." << endl << endl;
                                        getch();

                                        verify = true;
                                    }

                                }while(verify);

                                doB[position] = dateBorrowed;
                                doR[position] = dateReturned;
                                id[position] = bookId;

                                position++;
                                
        
                                // SEND A REQUEST TO THE ADMIN TO APPROVED AN APPLICATION TO BORROW A BOOK FROM THE LIBRARY
                                s = 1; 
                                status = DisplayStatus(s);

                                // Set status in the node to Borrowed [Submitted]
                                list.setStatus(status, bookId); 
                        
                                cout << "\n\t\t   ---------------------------------------------------------------------------" << endl;

                                cout << "\n\t\t\t\tYOUR REQUEST TO BORROW A BOOK HAS BEEN SUBMITTED  " << endl;
                                cout << "\t\t\t\t     WAIT FOR ADMIN TO APPROVE THE REQUEST          " << endl;
                                
                                libQ.enQueue(name,matricNum,dateBorrowed,dateReturned,totalDuration,bookId,author,title,date,type);
                            }
                            else
                            {   
                                cout << "\n\t\t   ---------------------------------------------------------------------------" << endl;
                                cout << "\n\t\t       *** THE BOOK ID YOU ENTERED IS NOT EXIST OR ALREADY BORROWED ! ****    " << endl;
                                cout << "\n\t\t   ---------------------------------------------------------------------------" << endl << endl;
                            }
                            
                            cout << " \n\t\t\t\t DO YOU WANT TO CONTINUE BORROW A BOOK ? " << endl
                                 << "\n\t\t\t\t               [1] YES " << endl
                                 << "\t\t\t\t               [0] NO  " << endl;
                            
                            cout << "\n\t\t\t                 CHOICE : ";
                            cin >> choiceLoop;
                        
                        }while(loop == 1 && choiceLoop == 1);

                        
                        break;
                    }
                    //Return a book
                    case 3:
                    {
                        int bookid;
                        int choice;
                        int choiceReturn;
                        int n;
                        string s;
                        bool verification;

                        do
                        {
                            system("cls");

                            cout << "\n\t\t\t----------------------------------------------------------------------------" << endl;;
                            cout << "\t\t\t------                          ELYSIUM LIBRARY                     --------" << endl;
                            cout << "\t\t\t------                  UNIVERSITY OF TECHNOLOGY MALAYSIA           --------" << endl;
                            cout << "\t\t\t----------------------------------------------------------------------------" << endl << endl;
                            
                            // It will print all the details of the book that was borrowed by the student
                            
                            cout << "\n\n\t\t\tNAME               : " << name      << endl;
                            cout << "\t\t\tMATRIC NUMBER      : " << matricNum << endl;

                        
                            cout << "\n\t\t\t----------------------------------------------------------------------------" << endl;
                            cout << "\t\t\t------                          RETURN A BOOK                      ---------" << endl;
                            cout << "\t\t\t----------------------------------------------------------------------------" << endl << endl;

                        
                            cout << "\n\t\t\t\tENTER BOOK ID THAT YOU WANT TO RETURN : ";
                            cin >> bookid;

                            int i;
                            int position;
                
                            for(i = 0; i < N ; i++)
                            {
                                if(bookid == id[i])
                                {
                                    position = i;
                                    cout << "\n\t\t\t\t\t\tBOOK BORROWED." << endl;
                                    verification = true;
                                    break;
                                }
                            }

                            cout << "\n\t\t\t----------------------------------------------------------------------------" << endl;
                            cout << "\t\t\t------                        BOOK INFORMATION                      --------" << endl;
                            cout << "\t\t\t----------------------------------------------------------------------------" << endl << endl;

                            int j = 0;

                            if(verification)
                            {
                                cout << "\t\t\t\t\t\tBOOK DETAILS      " << endl;

                                cout << "\t\t\t\t[" << j + 1 << "]" << endl

                                    << "\t\t\t\tTITLE             : " << list.getTitle(id[position])  << endl 
                                    << "\t\t\t\tAUTHOR            : " << list.getAuthor(id[position]) << endl
                                    << "\t\t\t\tPUBLISHED DATE    : " << list.getDate(id[position])   << endl
                                    << "\t\t\t\tTYPE              : " << list.getType(id[position])   << endl
                                    << "\t\t\t\tBOOK ID           : " << id[position] << endl;
                                
                                cout << "\n\t\t\t------------------------------------------------------------------------" << endl;

                                cout << "\t\t\t\t\t\tDETAILS OF THE BORROWING TRANSACTIONS " << endl;

                                cout << "\t\t\t\tBORROWED DATE      : "; 
                                getDateBorrowed(doB[position]);
                                
                                cout << "\t\t\t\tRETURN DATE        : ";
                                getDateBorrowed(doR[position]);

                                cout << "\t\t\t\tSTATUS             : " << DisplayStatus(list.getStatus(id[position])) << endl;
                        
                                cout << "\n\t\t\t------------------------------------------------------------------------" << endl;
                                cout << " \n\t\t\t\tARE YOU CONFIRM ON RETURNING THIS BOOK ? " << endl
                                     << "\t\t\t\t\t    [1] YES " << endl
                                     << "\t\t\t\t\t    [0] NO  " << endl;
                            
                                cout << "\n\t\t\t\t\tCHOICE  :";
                                cin >> choiceReturn;

                                if(choiceReturn == 1)
                                {
                                    n = 0; 
                                    s = DisplayStatus(n);
                                    // Set status in the node to Borrowed [Submitted]
                                    list.setStatus(s,id[position]); 
                                    cout << " \n\t\t\t**** BOOK HAS BEEN RETURNED. THANK YOU MR/MS " << name << " ****" <<  endl;
                            
                                }
                                
                                cout << endl << endl;
                
                            }
                            else
                            {
                                cout << "\n\t\t\t      *******  THE BOOK IS NOT BEING BORROWED BY THE STUDENT  *******     " << endl;
                            }
                            
                            cout << "\n\t\t\t\tDO YOU WANT TO CONTINUE RETURN A BOOK ? " << endl
                                 << "\t\t\t\t\t    [1] YES " << endl
                                 << "\t\t\t\t\t    [0] NO  " << endl;
                            
                            cout << "\n\t\t\t\t\tCHOICE  : ";
                            cin >> choice;

                        }while(choice != 0);
 
                        break;
                    }
                    case 4: // Search the book
                    {
                        list.searchNode();

                        break;
                    }
                    case 5:
                    {
                        list.sortingTheNode(size);
                        list.PrintDetails();
                        break;
                    }
                    case 0:
                    {
                        choiceMain = DisplayMainMenu();

                        break;
                    }
                }
                choiceStudent = DisplayStudentMenu();

                if(choiceStudent == 0)
                    goto A;

            }while(choiceStudent != 0 );
        }
        case 3:
            int choiceMain;
            choiceMain = DisplayMainMenu();
            break;
        }   
    }while(choiceMain != 3);

    system("pause");

    return 0;
}

