
 #include<iostream>
 using namespace std;
 
 /*---------------------------------------------------------------------------------------------
 -------------------------------- Below structure for Singly Linked List -----------------------
 ------------------------------------- And also for Stack and Queue ----------------------------
 ---------------------------------------------------------------------------------------------*/

 template <typename T>   
 struct Snode
  {
    T data;
    struct Snode *next;
  };

/*---------------------------------------------------------------------------------------------
 -------------------------------- Below structure for Doubly Linked List ----------------------
 ------------------------------------ And also for Binary Search tree -------------------------
 ---------------------------------------------------------------------------------------------*/

 template <typename T>   
 struct Dnode
  {
    T data;
    struct Dnode *next;
    struct Dnode *prev;
  };

/*---------------------------------------------------------------------------------------------
 -------------------------------- Below Class for Singly Linear Linked List -------------------
 ---------------------------------------------------------------------------------------------*/
 
 template <class T> 
 class SinglyLL
  { 
    private :
       Snode<T> * first;
       int size;
    
    public :
       SinglyLL();
       
       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPos(T,int);
       
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int); 
        
       void Display();
       int Count();   
  }; 

/*-----------------------------------------------------------------------------------------------
 --------------------------- Below Class for Singly Circular Linked List ------------------------
 -----------------------------------------------------------------------------------------------*/
 
 template <class T>
 class SinglyCL
  {
    private : 
      Snode<T> * first ;
      Snode<T> * last;
      int size;
    
    public :
       SinglyCL();
       
       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPos(T,int);
       
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int); 
        
       void Display();
       int Count();
  };
 
 /*---------------------------------------------------------------------------------------------
 -------------------------- Below Class for Doubly Linear Linked List --------------------------
 ----------------------------------------------------------------------------------------------*/
 
 template <typename T>   
 class DoublyLL
  { 
    private :
       Dnode<T> * first;
       Dnode<T> * prev;
       int size;
    
    public :
       DoublyLL();
       
       void InsertFirst(T);
       void InsertLast(T);
       void InsertAtPos(T,int);
       
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int); 
        
       void Display();
       int Count();   
  };  
 
 /*--------------------------------------------------------------------------------------------
 -------------------------- Below Class for Doubly Circular Linked List------------------------
 ----------------------------------------------------------------------------------------------*/
 
 template <class T>
 class DoublyCL
  {
    private :
      Dnode<T> *first;
      Dnode<T> *last;
      T size;
    
    public :
      DoublyCL();
       
      void Display();
      int Count();
      
      void InsertFirst(T no); 
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);
      
      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);  
  }; 
 
/*--------------------------------------------------------------------------------------------
 ---------------------------------- Below Class for Stack ------------------------------------
 ----------------------------------------------------------------------------------------------*/
 
 template <class T>
 class Stack                     
  {
    private :
      Snode<T> * first;
      int size;
    
    public :
      Stack();      
      void Display();       
      int Count();       
      void push(T);       
      T pop();  
  };
 
/*---------------------------------------------------------------------------------------------
 ---------------------------------- Below Class for Queue -------------------------------------
 ----------------------------------------------------------------------------------------------*/

 template <class T>
 class Queue     
  {
    private :
      Dnode<T> *first;
      int size;
    
    public :
      Queue();
      void Enqueue(T); 
      int Dequeue();
      void Display();
      int Count();
  }; 

/****************************************************************************************************
 ****************************************************************************************************
                                          Functions
 ****************************************************************************************************
 ***************************************************************************************************/
 

/*---------------------------------------------------------------------------------------------
 -------------------------------- Below Functions for Singly Linear Linked List ---------------
 ---------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/  
 
 template <class T>
 SinglyLL <T> :: SinglyLL()   
  {
    first = NULL;
    size = 0;         
  }
     
/*______________________________________________________________________________________________*/  
    
 template <class T>  
 void SinglyLL<T> :: InsertFirst(T no)
  {
    Snode<T> *  newn = new   Snode<T>; 
          
    newn->data = no;
    newn->next = NULL;
          
    if(first == NULL)  
     {
       first = newn;
     }
    else
     {
       newn->next = first;
       first = newn;           
     }
    size++;       
  }
       
/*______________________________________________________________________________________________*/  
         
 template <class T> 
 void SinglyLL<T>  :: InsertLast(T no)
  {
    Snode<T> * newn = new   Snode<T>; 
    Snode<T> * temp = first;    
          
    newn->data = no;
    newn->next = NULL;
          
    if(first == NULL) 
     {
       first = newn;
     }
    else
     {
       while(temp->next != NULL)
        {
          temp = temp->next;
        }
       temp->next = newn;         
     }
    size++;      
        
  }
       
/*______________________________________________________________________________________________*/  
         
 template <class T> 
 void SinglyLL<T>  :: InsertAtPos(T no,int ipos)
  {
    if((ipos < 1) || (ipos > size+1))
     { 
       cout<<"Invalid Position \n";
       return;            
     }
          
    if(ipos == 1)
     {
       InsertFirst(no);
     }
    else if(ipos == size+1)
     {
       InsertLast(no);
     }
    else
     {
       int i = 0 ;
       Snode<T> * newn = new   Snode<T>;
       Snode<T> * temp = first;
             
       newn->data = no;
       newn->next = NULL;
             
       for(i=1 ; i < (ipos-1) ; i++) 
        {
          temp = temp->next;
        }
             
       newn->next = temp->next;
       temp->next = newn;
       size++;
     }        
  }
       
/*______________________________________________________________________________________________*/  
         
 template <class T>  
 void SinglyLL<T>  :: DeleteFirst()
  {
    Snode<T> * temp = first;
          
    if(first != NULL)    
     {
       first = first->next;
       delete(temp);  
       size--;             
     }          
  }
       
/*______________________________________________________________________________________________*/  
         
 template <class T>
 void SinglyLL<T>  :: DeleteLast()
  {
    Snode<T> * temp = first;
          
    if(first == NULL)
     {
       return;
     }
    else if(first->next == NULL)
     {
       delete first;
       first = NULL;
       size--;
     }
    else
     {
       while(temp->next->next != NULL)
        {
          temp = temp->next;
        }
              
       delete temp->next;
       temp->next = NULL;
       size--;
     }
  }
       
/*______________________________________________________________________________________________*/  
         
 template <class T> 
 void SinglyLL<T>  :: DeleteAtPos(int ipos)
  {
    Snode<T> * temp = first;
    Snode<T> * targeted = NULL;
          
    if((ipos < 1) || (ipos > size))
     {
       cout<<"invalid position \n";
       return;
     } 
           
    if(ipos == 1)
     {
       DeleteFirst();
     }
    else if(ipos == size)
     {
       DeleteLast();
     }
    else
     {
       int i = 0;
             
       for(i=1 ; i < ipos-1 ; i++)
        {
          temp = temp->next;
        }
             
       targeted = temp->next;  
       temp->next = temp->next->next;   
             
       delete targeted;
       size--;
     }       
  }
        
/*______________________________________________________________________________________________*/  
         
 template <class T> 
 void SinglyLL<T>  :: Display()
  {
    Snode<T> * temp = first;
          
    while(temp != NULL)
     {
       cout<< "|" << temp->data << "|-> ";
       temp = temp->next;
     }
    cout<<"\n";
  }
  
/*______________________________________________________________________________________________*/  
         
 template <class T>  
 int SinglyLL<T>  :: Count()
  {
    return size;
  }
 
/*______________________________________________________________________________________________*/  
 
/*------------------------------------------------------------------------------------------------
 --------------------------- Below Functions for Singly Circular Linked List ---------------------
 -----------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/  
  
 template <class T>
 SinglyCL<T> :: SinglyCL()
  {
    first = NULL;
    last = NULL;
    size = 0;
  }  

/*______________________________________________________________________________________________*/  
  
 template <class T>    
 void SinglyCL<T> :: Display()
  {
    Snode<T> * temp = first;
        
    if((first== NULL) && (last == NULL))
     {
       return;
     }
        
    do     
     {
       cout<< "|" << temp->data << "|-> ";
       temp = temp->next;
     }while(temp != last->next);
     
    cout<<"\n";
  }

/*______________________________________________________________________________________________*/  
  
 template <class T>    
 int SinglyCL<T> :: Count()
  {
    return size; 
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>      
 void SinglyCL<T> :: InsertFirst(T no) 
   {
     Snode<T> * newn = NULL;
     newn = new Snode<T>;
        
     newn->data = no;
     newn->next = NULL;
       
     if((first == NULL) && (last == NULL))   
      {
        first = newn;
        last = newn;
      }
     else
      {
        newn->next = first;
        first = newn;        
      }
        
     last->next = first;
     size++;
   }

/*______________________________________________________________________________________________*/  
 
 template <class T>      
 void SinglyCL<T> :: InsertLast(T no) 
  {
    Snode<T> * newn = NULL;
    newn = new Snode<T>;
       
    newn->data = no;
    newn->next = NULL;
       
    if((first == NULL) && (last == NULL))  
     {
       first = newn;
       last = newn;
     }
    else
     {
       last->next = newn;
       last = newn;
     }
        
    last->next = first;
    size++;    
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>     
 void SinglyCL<T> :: InsertAtPos(T no , int ipos) 
  {
    if((ipos < 1) || (ipos > (size+1)))     
     {
       return;
     }
        
    if(ipos == 1)              
     {
       InsertFirst(no);
     }
    else if(ipos == size+1)    
     {
       InsertLast(no);
     }
    else                       
     {
       Snode<T> * newn = NULL;
       newn = new Snode<T>;      
           
       newn->data = no;
       newn->next = NULL;
           
       Snode<T> * temp = first;
           
       for(int i=1 ; i < (ipos-1) ; i++)
        {
          temp = temp->next;
        }
           
       newn->next = temp->next;
       temp->next = newn;  
       size++;         
     }      
  }

/*______________________________________________________________________________________________*/  
  
 template <class T>     
 void SinglyCL<T> :: DeleteFirst()
  {
    if((first == NULL) && (last == NULL))   
     {
       return;
     }
    else if(first == last) 
     {
       delete first;
       first = NULL;
       last = NULL;
     }
    else
     {
       first = first->next;
       delete last->next;
       last->next = first;
     }
    size--;
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>      
 void SinglyCL<T> :: DeleteLast()
  {
    Snode<T> * temp = first;
        
    if((first == NULL) && (last == NULL))   
     {
       return;
     }
    else if(first == last)  
     {
       delete first;
       first = NULL;
       last = NULL;
     }
    else
     {
       while(temp->next != last)
        {
          temp = temp->next;
        }
           
       delete last;
       last = temp;
       last->next = first;
     }
            
    size--;
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>     
 void SinglyCL<T> :: DeleteAtPos(int ipos)
  {
   if((ipos < 1) || (ipos > (size)))     
    {
      return;
    }
      
   if(ipos == 1)
    {
      DeleteFirst();
    }
   else if(ipos == size)
    {
      DeleteLast();
    }
   else
    {
      Snode<T> * temp = first;
           
      for(int i=1 ; i < (ipos-1) ; i++)
       {
         temp = temp->next;
       }
           
      Snode<T> * targeted = temp->next;    
      temp->next = targeted->next;    
      delete(targeted);
           
      size--;
     }     
  }
 
/*______________________________________________________________________________________________*/  
 
/*------------------------------------------------------------------------------------------------
 --------------------------- Below Functions for Doubly Linear Linked List -----------------------
 -----------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/ 
 
 template <typename T>   
 DoublyLL<T> :: DoublyLL()
  {
    first = NULL;
    prev = NULL;
    size = 0;         
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>          
 void DoublyLL<T> :: InsertFirst(T no)
  {
    Dnode<T> *newn = new Dnode<T>; 
          
    newn->data = no;
    newn->next = NULL;
    newn->next = NULL;
          
    if(first == NULL) 
     {
       first = newn;
     }
    else
     {
       first->prev = newn;
       newn->next = first;
       first = newn;
     }
    size++;       
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>         
 void DoublyLL<T> :: InsertLast(T no)
  {
    Dnode<T> *newn = new Dnode<T>; 
    Dnode<T> *temp = first;  
          
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
          
    if(first == NULL)
     {
       first = newn;
     }
    else
     {
       while(temp->next != NULL)
        {
          temp = temp->next;
        }
       temp->next = newn;
       newn->prev = temp;         
     }
    size++;      
  }

/*____________________________________________________________________________________________*/ 
 
 template <typename T>           
 void DoublyLL<T> :: InsertAtPos(T no,int ipos)
  {
    if((ipos < 1) || (ipos > size+1))
     { 
       cout<<"Invalid Position \n";
       return;            
     }
          
    if(ipos == 1)
     {
       InsertFirst(no);
     }
    else if(ipos == size+1)
     {
       InsertLast(no);
     }
    else
     {
       int i = 0 ;
       Dnode<T> *newn = new Dnode<T>;
       Dnode<T> *temp = first;
             
       newn->data = no;
       newn->next = NULL;
       newn->prev = NULL;
             
       for(i=1 ; i < (ipos-1) ; i++) 
        {
          temp = temp->next;
        }
       newn->next = temp->next;
       newn->prev = temp;
             
       temp->next->prev = newn;
       temp->next = newn; 
            
       size++;
     }        
  }
   
/*____________________________________________________________________________________________*/ 

 template <typename T>        
 void DoublyLL<T> :: DeleteFirst()
  {
    Dnode<T> *temp = first;
        
    if(first != NULL)  
     {
       first = first->next;
       first->prev = NULL;
       delete(temp);  
       size--;             
     }          
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>       
 void DoublyLL<T> :: DeleteLast()
  {
    Dnode<T> *temp = first;
        
    if(first == NULL)
     {
       return;
     }
    else if(first->next == NULL)
     {
       delete first;
       first = NULL;
     }
    else
     {
       while(temp->next != NULL)
        {
          temp = temp->next;
        }
       
       temp->prev->next = NULL;    
       delete temp;
     }
    size--;
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>            
 void DoublyLL<T> :: DeleteAtPos(int ipos)
  {
    Dnode<T> *temp = first;
    Dnode<T> *targeted = NULL;
          
    if((ipos < 1) || (ipos > size))
     {
       cout<<"invalid position \n";
       return;
     } 
           
    if(ipos == 1)
     {
       DeleteFirst();
     }
    else if(ipos == size)
     {
       DeleteLast();
     }
    else
     {
       int i = 0;
             
       for(i=1 ; i < ipos-1 ; i++)
        {
          temp = temp->next;
        }
             
       targeted = temp->next;   
       temp->next = temp->next->next;  
       temp->next->prev = temp;
             
       delete targeted;
       size--;
     }       
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>          
 void DoublyLL<T> :: Display()
  {
    Dnode<T> *temp = first;
        
    while(temp != NULL)
     {
       cout<< "|" << temp->data << "|-> ";
       temp = temp->next;
     }
    cout<<"\n";
  }

/*____________________________________________________________________________________________*/ 
  
 template <typename T>         
 int DoublyLL<T> :: Count()
  {
    return size;
  }
 
/*______________________________________________________________________________________________*/ 
 
/*------------------------------------------------------------------------------------------------
 --------------------------- Below Functions for Doubly Circular Linked List ---------------------
 -----------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/ 
 
 template <class T>
 DoublyCL<T> :: DoublyCL()
  {
    first = NULL;
    last = NULL;
    size = 0;
  }
       
 template <class T>
 void DoublyCL<T> :: InsertFirst(T no)
  {
    Dnode<T> *newn = NULL;
    newn = new Dnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL)&&(last == NULL))
     {
       first = newn;
       last = newn;
     }
    else 
     {
       newn->next = first;
       first->prev = newn;
       first = newn;
     }
    
    last->next = first;
    first->prev = last;
    size++;
  }

/*____________________________________________________________________________________________*/ 
  
 template <class T>
 void DoublyCL<T> :: InsertLast(T no)
  {
    Dnode<T> *newn = NULL;
    newn = new Dnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL)&&(last == NULL))
     {
       first = newn;
       last = newn;
     }
    else 
     {
       last->next = newn;
       newn->prev = last;
       last = newn;
     }
    
    last->next = first;
    first->prev = last;
    size++;
  }

/*____________________________________________________________________________________________*/ 
 
 template <class T>
 void DoublyCL<T> :: InsertAtPos(T no, int ipos)
  {
    if((ipos < 1) || (ipos > size+1))
     {
       return;      
     }
  
    if(ipos == 1) 
     {
       InsertFirst(no);
     }
    else if(ipos == size+1)
     {
       InsertLast(no);
     }
    else
     {
       Dnode<T> *newn = NULL;
       newn = new Dnode<T>;
       
       newn->data = no;
       newn->next = NULL;
       newn->prev = NULL;
       
       Dnode<T> *temp = first;
       
       for(int i=1 ; i < ipos-1 ; i++)
        {
          temp = temp->next;
        }
       
       newn->next = temp->next;
       newn->next->prev = newn;
       
       temp->next = newn;
       newn->prev = temp;
       
       size++;       
     }
  }

/*____________________________________________________________________________________________*/ 
   
 template <class T> 
 void DoublyCL<T> :: Display()
  {
    Dnode<T> *temp = first;
    
    for(int i=1 ; i <= size ; i++)
     {
       cout<< "|" << temp->data << "|-> ";
       temp = temp->next;
     }
    cout<< "\n";         
  } 
 
/*____________________________________________________________________________________________*/ 
 
 template <class T>  
 int DoublyCL<T> :: Count()
  {
    return size;
  }

/*____________________________________________________________________________________________*/ 
  
 template <class T>
 void DoublyCL<T> :: DeleteFirst()
  {
    if((first == NULL) && (last == NULL))  
     {
       return;
     }
    else if(first == last)
     {
       delete first;
       first == NULL;
       last == NULL;
     }
    else
     {
       first = first->next;
       delete last->next;  //  delete first->prev;
     
       first->prev = last;
       last->next = first;
     }
    size--;   
  }

/*____________________________________________________________________________________________*/ 
  
 template <class T>
 void DoublyCL<T> :: DeleteLast()
  {
    if((first == NULL) && (last == NULL))  
     {
       return;
     }
    else if(first == last)
     {
       delete first;
       first == NULL;
       last == NULL;
     }
    else
     {
       last = last->prev;
       delete last->next;  //  delete first->prev;
     
       first->prev = last;
       last->next = first;
     }
    size--;   
  }
 
/*____________________________________________________________________________________________*/ 
  
 template <class T>
 void DoublyCL<T> :: DeleteAtPos(int ipos)
  {
    if((ipos < 1) || (ipos > size))
     {
       return;      
     }
  
    if(ipos == 1) 
     {
       DeleteFirst();
     }
    else if(ipos == size)
     {
       DeleteLast();
     }
    else
     {
       Dnode<T> *temp = first;
       
       for(int i=1 ; i < ipos-1 ; i++)
        {
          temp = temp->next;
        }
       
       temp->next = temp->next->next;
       delete temp->next->prev;
       temp->next->prev = temp;
       size--;    
     }
  }
  
/*______________________________________________________________________________________________*/ 
 
/*------------------------------------------------------------------------------------------------
 --------------------------------------- Below Functions for Stack -------------------------------
 -----------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/ 

 template <class T>
 Stack<T> :: Stack()  
  {
    first = NULL;
    size = 0;
  }

/*______________________________________________________________________________________________*/ 
 
 template <class T>       
 void Stack<T> :: Display()
  {
    Snode<T> *temp = first;
         
    while(temp != NULL)
     {
       cout<< "|" << temp->data << "|" <<"\n";
       temp =temp->next;
     }
    cout<< "\n";
  }

/*______________________________________________________________________________________________*/ 
 
 template <class T>       
 int Stack<T> :: Count()
  {
    return size;
  }

/*______________________________________________________________________________________________*/ 

 template <class T>        
 void Stack<T> :: push(T no)       
  {
    Snode<T> *newn = NULL;
    newn = new Snode<T>;
         
    newn->data = no;
    newn->next = NULL;
         
    if(first == NULL)
     {
       first = newn;
     }
    else
     {
       newn->next = first;
       first = newn;
     }
         
    size++;
  }

/*______________________________________________________________________________________________*/ 

 template <class T>       
 T Stack<T> :: pop()                       
  { 
    T iNO = 0;
    Snode<T> *temp = first;
         
    if(first == NULL)                     
     {
       cout<< "Stack is empty \n";
       return -1;
     }
          
    if(first->next == NULL)                 
     {
       iNO = first->data;
       delete first;
       first = NULL;
     }
    else                                   
     {
       iNO = first->data;
       first = first->next;
       delete temp;
     }
         
    size--;
    return iNO;
  }
 
/*______________________________________________________________________________________________*/ 
 
/*------------------------------------------------------------------------------------------------
 --------------------------------------- Below Functions for Queue -------------------------------
 -----------------------------------------------------------------------------------------------*/
/*______________________________________________________________________________________________*/  

 template <class T>
 Queue<T> :: Queue()  
  {
    first = NULL;
    size = 0;
  }

/*______________________________________________________________________________________________*/  
  
 template <class T>
 void Queue<T> :: Enqueue(T no) 
  {
    Dnode<T> *newn = NULL;
    newn = new Dnode<T>;
         
    newn->data = no;
    newn->next = NULL;
         
    if(size == 0)    
     {
       first = newn;
     }
    else
     {
       Dnode<T> *temp = first;
            
       while(temp->next != NULL)
        {
          temp = temp->next;
        }
       temp->next = newn;
     }
    size++;      
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>       
 int Queue<T> :: Dequeue()  
  {
    int iNO = 0;
    Dnode<T> *temp = first;
         
    if(first == NULL)            
     {
       cout<< "Queue is empty \n";
       return -1;
     }
          
    if(first->next == NULL)      
     {
       iNO = first->data;
       delete first;
       first = NULL;
     }
    else                    
     {
       iNO = first->data;
       first = first->next;
       delete temp;
     }
         
    size--;
    return iNO;
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>      
 void Queue<T> :: Display()
  {
    Dnode<T> *temp = first;
     
         
   for(int i=1 ; i<= size ; i++ , temp = temp->next)
    {
      cout<<"|"<< temp->data << "|-> ";
    }
    cout<<"NULL \n";
  }

/*______________________________________________________________________________________________*/  
 
 template <class T>       
 int Queue<T> :: Count()
  {
    return size;
  }

/*______________________________________________________________________________________________*/  

 
 int main()
  {
    int Choice1 = 1,Choice2 = 1, Choice3 = 1, iRet = 0, pos = 0 ;
    
    int ivalue = 0;
    char cvalue = '\0';
    float fvalue = 0.0f;
    double dvalue = 0.0;
      
    SinglyLL <int>SLL_i_obj;
    SinglyLL <char>SLL_c_obj; 
    SinglyLL <float>SLL_f_obj; 
    SinglyLL <double>SLL_d_obj; 
    
    SinglyCL <int>SCL_i_obj;
    SinglyCL <char>SCL_c_obj; 
    SinglyCL <float>SCL_f_obj; 
    SinglyCL <double>SCL_d_obj;
    
      
    DoublyLL <int>DLL_i_obj;
    DoublyLL <char>DLL_c_obj; 
    DoublyLL <float>DLL_f_obj; 
    DoublyLL <double>DLL_d_obj; 
    
      
    DoublyCL <int>DCL_i_obj;
    DoublyCL <char>DCL_c_obj; 
    DoublyCL <float>DCL_f_obj; 
    DoublyCL <double>DCL_d_obj; 
    
    Queue <int>Q_i_obj;
    Queue <char>Q_c_obj; 
    Queue <float>Q_f_obj; 
    Queue <double>Q_d_obj;
          
          
    cout<< "\n-----------------------------------------------------------------------";
    cout<< "\n---------------------------- Welcome ----------------------------------"; 
    
    while(Choice1 != 0)
     { 
       cout<< "\n-----------------------------------------------------------------------\n";
     
       cout<< "1 : To Create a Singly Linear Linked List \n";
       cout<< "2 : To Create a Singly Circular Linked List \n";
       cout<< "3 : To Create a Doubly Linear Linked List \n";       
       cout<< "4 : To Create a Doubly Circular Linked List \n"; 
       cout<< "5 : To Create a Queue \n";   
     //  cout<< "6 : To Create a Stack \n";     
       cout<< "0 : Terminate the Application \n";
       
       cout<< "-----------------------------------------------------------------------\n";
       cout<< "Select the Desired operation that you want perform on linked list : ";
       cin>> Choice1;
       cout<< "-----------------------------------------------------------------------\n";
        
       switch(Choice1)
        {
          case 1 :
                   cout<< "\n-----------------------------------------------------------------------";
                   cout<< "\n------------------- Welcome to Singly Linear Linked List --------------"; 
                   
                   while(Choice2 != 0)
                    {
                      cout<< "\n---------------------------------------------------------------------\n";
     
                      cout<< "1 :  For integer Linked List \n";
                      cout<< "2 :  For Character Linked List \n";
                      cout<< "3 :  For Float Linked List \n";       
                      cout<< "4 :  For Double Linked List \n";    
                      cout<< "0 :  Back \n";
       
                      cout<< "-----------------------------------------------------------------------\n";
                      cout<< "Select the Desired operation that you need : ";
                      cin>> Choice2;
                      cout<< "-----------------------------------------------------------------------\n";
       
                      switch(Choice2)
                       {
                         case 1 :
                                 ivalue = 0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    SLL_i_obj.InsertFirst(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    SLL_i_obj.InsertLast(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_i_obj.InsertAtPos(ivalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SLL_i_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SLL_i_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_i_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SLL_i_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SLL_i_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 		              
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                 
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                         
                         case 2 : 
                                 cvalue = '\0';     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    SLL_c_obj.InsertFirst(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    SLL_c_obj.InsertLast(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_c_obj.InsertAtPos(cvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SLL_c_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SLL_c_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_c_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SLL_c_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SLL_c_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											              
								     }    // end of Switch 3          
							      }       // end of while 3    
							     break; 
							                             
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 3 : 
                                 fvalue = 0.0f;     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    SLL_f_obj.InsertFirst(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    SLL_f_obj.InsertLast(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_f_obj.InsertAtPos(fvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SLL_f_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SLL_f_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_f_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SLL_f_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SLL_f_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											                            
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                        
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      
                         case 4 :
                                 dvalue = 0.0;      
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    SLL_d_obj.InsertFirst(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    SLL_d_obj.InsertLast(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_d_obj.InsertAtPos(dvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SLL_d_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SLL_d_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SLL_d_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SLL_d_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SLL_d_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											      
						            }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                    
                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 0 :
							     cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
								 cout<< "-----------------------------------------------------------------------\n\n";
								 break;
										 
                        }  // end of Switch 2
                    }      // end of while 2
               break; 
                 
         ///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*   
         
          case 2 :
                   cout<< "\n-----------------------------------------------------------------------";
                   cout<< "\n------------------- Welcome to Singly Circular Linked List ------------"; 
                   
                   while(Choice2 != 0)
                    {
                      cout<< "\n-----------------------------------------------------------------------\n";
     
                      cout<< "1 :  For integer Linked List \n";
                      cout<< "2 :  For Character Linked List \n";
                      cout<< "3 :  For Float Linked List \n";       
                      cout<< "4 :  For Double Linked List \n";    
                      cout<< "0 :  Back \n";
       
                      cout<< "-----------------------------------------------------------------------\n";
                      cout<< "Select the Desired operation that you need : ";
                      cin>> Choice2;
                      cout<< "-----------------------------------------------------------------------\n";
       
                      switch(Choice2)
                       {
                         case 1 :
                                 ivalue = 0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    SCL_i_obj.InsertFirst(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    SCL_i_obj.InsertLast(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_i_obj.InsertAtPos(ivalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SCL_i_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SCL_i_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_i_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SCL_i_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SCL_i_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 		              
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                 
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                         
                         case 2 : 
                                 cvalue = '\0';     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    SCL_c_obj.InsertFirst(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    SCL_c_obj.InsertLast(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_c_obj.InsertAtPos(cvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SCL_c_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SCL_c_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_c_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SCL_c_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SCL_c_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											              
								     }    // end of Switch 3          
							      }       // end of while 3    
							     break; 
							                             
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 3 : 
                                 fvalue = 0.0f;     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    SCL_f_obj.InsertFirst(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    SCL_f_obj.InsertLast(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_f_obj.InsertAtPos(fvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SCL_f_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SCL_f_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_f_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SCL_f_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SCL_f_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											                            
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                        
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      
                         case 4 :
                                 dvalue = 0.0;      
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    SCL_d_obj.InsertFirst(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    SCL_d_obj.InsertLast(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_d_obj.InsertAtPos(dvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    SCL_d_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    SCL_d_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    SCL_d_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    SCL_d_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = SCL_d_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											      
						            }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                    
                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 0 :
							     cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
								 cout<< "-----------------------------------------------------------------------\n\n";
								 break;
										 
                        }  // end of Switch 2
                    }      // end of while 2
               break;   
       
       ///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*       
         
          case 3 :
                   cout<< "\n-----------------------------------------------------------------------";
                   cout<< "\n------------------- Welcome to Doubly Linear Linked List --------------"; 
                   
                   while(Choice2 != 0)
                    {
                      cout<< "\n---------------------------------------------------------------------\n";
     
                      cout<< "1 :  For integer Linked List \n";
                      cout<< "2 :  For Character Linked List \n";
                      cout<< "3 :  For Float Linked List \n";       
                      cout<< "4 :  For Double Linked List \n";    
                      cout<< "0 :  Back \n";
       
                      cout<< "-----------------------------------------------------------------------\n";
                      cout<< "Select the Desired operation that you need : ";
                      cin>> Choice2;
                      cout<< "-----------------------------------------------------------------------\n";
       
                      switch(Choice2)
                       {
                         case 1 :
                                 ivalue = 0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    DLL_i_obj.InsertFirst(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    DLL_i_obj.InsertLast(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_i_obj.InsertAtPos(ivalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DLL_i_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DLL_i_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_i_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DLL_i_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DLL_i_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 		              
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                 
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                         
                         case 2 : 
                                 cvalue = '\0';     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    DLL_c_obj.InsertFirst(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    DLL_c_obj.InsertLast(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_c_obj.InsertAtPos(cvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DLL_c_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DLL_c_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_c_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DLL_c_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DLL_c_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											              
								     }    // end of Switch 3          
							      }       // end of while 3    
							     break; 
							                             
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 3 : 
                                 fvalue = 0.0f;     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    DLL_f_obj.InsertFirst(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    DLL_f_obj.InsertLast(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_f_obj.InsertAtPos(fvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DLL_f_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DLL_f_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_f_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DLL_f_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DLL_f_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											                            
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                        
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      
                         case 4 :
                                 dvalue = 0.0;      
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    DLL_d_obj.InsertFirst(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    DLL_d_obj.InsertLast(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_d_obj.InsertAtPos(dvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DLL_d_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DLL_d_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DLL_d_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DLL_d_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DLL_d_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											      
						            }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                    
                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 0 :
							     cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
								 cout<< "-----------------------------------------------------------------------\n\n";
								 break;
										 
                        }  // end of Switch 2
                    }      // end of while 2

             break;  
              
     ///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*         
          
          case 4 :
                   cout<< "\n-----------------------------------------------------------------------";
                   cout<< "\n------------------- Welcome to Doubly Circular Linked List --------------"; 
                   
                   while(Choice2 != 0)
                    {
                      cout<< "\n---------------------------------------------------------------------\n";
     
                      cout<< "1 :  For integer Linked List \n";
                      cout<< "2 :  For Character Linked List \n";
                      cout<< "3 :  For Float Linked List \n";       
                      cout<< "4 :  For Double Linked List \n";    
                      cout<< "0 :  Back \n";
       
                      cout<< "-----------------------------------------------------------------------\n";
                      cout<< "Select the Desired operation that you need : ";
                      cin>> Choice2;
                      cout<< "-----------------------------------------------------------------------\n";
       
                      switch(Choice2)
                       {
                         case 1 :
                                 ivalue = 0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    DCL_i_obj.InsertFirst(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											    DCL_i_obj.InsertLast(ivalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> ivalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_i_obj.InsertAtPos(ivalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DCL_i_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DCL_i_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_i_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DCL_i_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DCL_i_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 		              
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                 
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                         
                         case 2 : 
                                 cvalue = '\0';     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    DCL_c_obj.InsertFirst(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											    DCL_c_obj.InsertLast(cvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> cvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_c_obj.InsertAtPos(cvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DCL_c_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DCL_c_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_c_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DCL_c_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DCL_c_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											              
								     }    // end of Switch 3          
							      }       // end of while 3    
							     break; 
							                             
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 3 : 
                                 fvalue = 0.0f;     
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    DCL_f_obj.InsertFirst(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											    DCL_f_obj.InsertLast(fvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> fvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_f_obj.InsertAtPos(fvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DCL_f_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DCL_f_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_f_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DCL_f_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DCL_f_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											                            
								     }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                        
                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      
                         case 4 :
                                 dvalue = 0.0;      
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
                                    cout<< "\n-----------------------------------------------------------------------\n";
                                    cout<< "1 : Insert the node at first position \n";
                                    cout<< "2 : Insert the node at last position \n";
                                    cout<< "3 : Insert the node at desired position \n";       
                                    cout<< "4 : Delete the first node \n"; 
                                    cout<< "5 : Delete the Last node \n";   
                                    cout<< "6 : Delete the node at desired position \n";     
                                    cout<< "7 : Display the contents of linked list \n";     
                                    cout<< "8 : Count the number of nodes from Linked List \n";     
                                    cout<< "0 : back \n";
       
                                    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on linked list : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
								   
									switch(Choice3)
									 {
									   case 1 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    DCL_d_obj.InsertFirst(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
									   case 2 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											    DCL_d_obj.InsertLast(dvalue);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
											 
									   case 3 :
											    cout<< "Enter the data to insert : ";
											    cin>> dvalue;
											 
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_d_obj.InsertAtPos(dvalue,pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;   
										  
									   case 4 :
											    DCL_d_obj.DeleteFirst();  
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
											
									   case 5 :
											    DCL_d_obj.DeleteLast(); 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
											
									   case 6 :
											    cout<< "Enter the Position : ";
											    cin>> pos;
											    DCL_d_obj.DeleteAtPos(pos);
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											 
									   case 7 :
											    cout<< "Elements of Linked List are : \n";
											    DCL_d_obj.Display();   
											    cout<< "\n-----------------------------------------------------------------------\n\n";   
											    break;   
										  
									   case 8 :
											    iRet = DCL_d_obj.Count();
											    cout<< "Number of Elements are : "<< iRet << "\n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";    
											    break;
										 
									   case 0 :
											    cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break;
										  
										  
									   default :
											    cout<< "Please enter Correct choice....\n";
											    cout<< "-----------------------------------------------------------------------\n\n";
											    break; 
											      
						            }    // end of Switch 3          
							      }       // end of while 3
                                 break;
                                    
                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        case 0 :
							     cout<< "Thank you for using Linked List...🙏️🙏️🙏️ \n"; 
								 cout<< "-----------------------------------------------------------------------\n\n";
								 break;
										 
                        }  // end of Switch 2
                    }      // end of while 2 

             break;
             
    ///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*          
         
          case 5 :
                   cout<< "\n-----------------------------------------------------------------------";
                   cout<< "\n------------------------- Welcome to Queue -----------------------------"; 
                   
                   while(Choice2 != 0)
                    {
                      cout<< "\n-----------------------------------------------------------------------\n";
     
                      cout<< "1 :  For integer Queue \n";
                      cout<< "2 :  For Character Queue \n";
                      cout<< "3 :  For Float Queue \n";       
                      cout<< "4 :  For Double Queue \n";    
                      cout<< "0 :  Back \n";
       
                      cout<< "-----------------------------------------------------------------------\n";
                      cout<< "Select the Desired operation that you need : ";
                      cin>> Choice2;
                      cout<< "-----------------------------------------------------------------------\n";
                    
                      switch(Choice2)
                        {
                          case 1 :
                                 ivalue = 0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
								    cout<< "\n-----------------------------------------------------------------------\n";
								    cout<< "1 : To Insert the node \n";
								    cout<< "2 : To Delete the node \n";
								    cout<< "3 : To Display the nodes of Queue \n";       
								    cout<< "4 : To Count nodes \n";  
								    cout<< "0 : Terminate the Application \n";
								   
								    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on Queue : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
									   
								    switch(Choice3)
									 {
									   case 1 :
										        cout<< "Enter the data to insert : ";
										        cin>> ivalue;
										        Q_i_obj.Enqueue(ivalue);
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									  
									   case 2 :
										        Q_i_obj.Dequeue();
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;   
										 
									   case 3 :
										        cout<< "Elements of Queue are : \n";
										        Q_i_obj.Display();   
										        cout<< "-----------------------------------------------------------------------\n\n";   
										        break;     
									  
									   case 4 :
										        iRet = Q_i_obj.Count();
										        cout<< "Number of Elements in Queue are : "<< iRet << "\n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";    
										        break;
									 
									   case 0 :
									            cout<< "Thank you for using Queue...🙏️🙏️🙏️ \n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									   
									   default :
										        cout<< "Please enter Correct choice....\n";
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;             
							         
							         }  // end of switch3             
					               }   //  end of while3
					            break;
					            
					      //////////////////////////////////////////////////////////////////////////////////////////////////////////// 
					      					      
					      case 2 :
                                 cvalue = '\0';
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
								    cout<< "\n-----------------------------------------------------------------------\n";
								    cout<< "1 : To Insert the node \n";
								    cout<< "2 : To Delete the node \n";
								    cout<< "3 : To Display the nodes of Queue \n";       
								    cout<< "4 : To Count nodes \n";  
								    cout<< "0 : Terminate the Application \n";
								   
								    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on Queue : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
									   
								    switch(Choice3)
									 {
									   case 1 :
										        cout<< "Enter the data to insert : ";
										        cin>> cvalue;
										        Q_c_obj.Enqueue(cvalue);
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									  
									   case 2 :
										        Q_c_obj.Dequeue();
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;   
										 
									   case 3 :
										        cout<< "Elements of Queue are : \n";
										        Q_c_obj.Display();   
										        cout<< "-----------------------------------------------------------------------\n\n";   
										        break;     
									  
									   case 4 :
										        iRet = Q_c_obj.Count();
										        cout<< "Number of Elements in Queue are : "<< iRet << "\n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";    
										        break;
									 
									   case 0 :
									            cout<< "Thank you for using Queue...🙏️🙏️🙏️ \n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									   
									   default :
										        cout<< "Please enter Correct choice....\n";
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;             
							         
							         }  // end of switch3             
					               }   //  end of while3
					              break;
					              
					     //////////////////////////////////////////////////////////////////////////////////////////////////////////// 
					      					      
					      case 3 :
                                 fvalue = 0.0f;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
								    cout<< "\n-----------------------------------------------------------------------\n";
								    cout<< "1 : To Insert the node \n";
								    cout<< "2 : To Delete the node \n";
								    cout<< "3 : To Display the nodes of Queue \n";       
								    cout<< "4 : To Count nodes \n";  
								    cout<< "0 : Terminate the Application \n";
								   
								    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on Queue : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
									   
								    switch(Choice3)
									 {
									   case 1 :
										        cout<< "Enter the data to insert : ";
										        cin>> fvalue;
										        Q_f_obj.Enqueue(fvalue);
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									  
									   case 2 :
										        Q_f_obj.Dequeue();
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;   
										 
									   case 3 :
										        cout<< "Elements of Queue are : \n";
										        Q_f_obj.Display();   
										        cout<< "-----------------------------------------------------------------------\n\n";   
										        break;     
									  
									   case 4 :
										        iRet = Q_f_obj.Count();
										        cout<< "Number of Elements in Queue are : "<< iRet << "\n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";    
										        break;
									 
									   case 0 :
									            cout<< "Thank you for using Queue...🙏️🙏️🙏️ \n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									   
									   default :
										        cout<< "Please enter Correct choice....\n";
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;             
							         
							         }  // end of switch3             
					               }   //  end of while3                   
					              break;
					              
					    //////////////////////////////////////////////////////////////////////////////////////////////////////////// 
					      					      
					      case 4 :
                                 dvalue = 0.0;
                                 Choice3 = 1;
                                 
                                 while(Choice3 != 0)
   						          {
								    cout<< "\n-----------------------------------------------------------------------\n";
								    cout<< "1 : To Insert the node \n";
								    cout<< "2 : To Delete the node \n";
								    cout<< "3 : To Display the nodes of Queue \n";       
								    cout<< "4 : To Count nodes \n";  
								    cout<< "0 : Terminate the Application \n";
								   
								    cout<< "-----------------------------------------------------------------------\n";
								    cout<< "Select the Desired operation that you want perform on Queue : ";
								    cin>> Choice3;
								    cout<< "-----------------------------------------------------------------------\n";
									   
								    switch(Choice3)
									 {
									   case 1 :
										        cout<< "Enter the data to insert : ";
										        cin>> dvalue;
										        Q_d_obj.Enqueue(dvalue);
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									  
									   case 2 :
										        Q_d_obj.Dequeue();
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;   
										 
									   case 3 :
										        cout<< "Elements of Queue are : \n";
										        Q_d_obj.Display();   
										        cout<< "-----------------------------------------------------------------------\n\n";   
										        break;     
									  
									   case 4 :
										        iRet = Q_d_obj.Count();
										        cout<< "Number of Elements in Queue are : "<< iRet << "\n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";    
										        break;
									 
									   case 0 :
									            cout<< "Thank you for using Queue...🙏️🙏️🙏️ \n"; 
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;
									   
									   default :
										        cout<< "Please enter Correct choice....\n";
										        cout<< "-----------------------------------------------------------------------\n\n";
										        break;             
							         
							         }  // end of switch3             
					               }   //  end of while3                   
					      
					      case 0 :
						          cout<< "Thank you for using Queue...🙏️🙏️🙏️ \n"; 
								  cout<< "-----------------------------------------------------------------------\n\n";
								  break;     
					               
					    }    // end of switch2 
			         }      //  end of while2
             break;
             
     ///*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*             
          case 6 :
             
             break; 
             
          
         
          case 0 :
             cout<< "Thank you for using STL...🙏️🙏️🙏️ \n"; 
             cout<< "-----------------------------------------------------------------------\n\n";
             break;
          
          
          default :
             cout<< "Please enter Correct choice....\n";
             cout<< "-----------------------------------------------------------------------\n\n";
             break;             
        
        }  // end of Switch 1            
     } // end of while 1
   
    return 0;
  }
 
