/* Program Name :- Write A C Programm For ATM Transaction .
   Developer Name :- Dhoke Saurabh 
   Date :- 01/09/2021  */

#include<stdio.h>
int main ()
 {
   int x,y,no,n,p1,p2;
   int pin=0,temp=0,count=0,caunt=0;
   printf("   Welcome...\n");
   printf("Swipe Your Card \n");
   printf("Then...\n");
   printf("Enter Your 4 Digit ATM Pin : \a");
   
     p : if(count < 3)
       {
         scanf("%d",&p1);
         temp=p1;
         int cnt=0;
       
           if(p1>0)
             {
               while(p1!=0)
                 {
		    pin=p1%10;
		    cnt++;
		    p1=p1/10;
		 }
               p1=temp;
               if(cnt==4)
                 {  
                   int am=0; 
                   printf("Enter Initial Amount : \a");
                   amount: if(am < 3)
                     {
	                scanf("%d",&x);
	                if(x>0)
                          {
		             printf("\n\t 1 : For Credit \n \t 2 : For Debit \n \t 3 : For Balance \n \t 4 : cancel Operation \nEnter the operation number which you want to perform : \a");
		             main :if(caunt< 3)
		                     {
		                       scanf("%d",&no);
		                       switch(no)
		                        {
		                          case 1 :
		                                    printf("Enter Credit Amount : \a");
			                            scanf("%d",&y);
				                     if(y>0)
                                                     {
				                       x=x+y;
				                       printf("Total Balance : %d ", x);				       
				                      }
				                     else
						      {
					               printf("Invalied Credit...\a");
					               return 0;
					              }
					             break;
				
				     
		                         case 2 :
		                                  printf("\n\t 1 : 200 \t\t 2 : 500 \n\t 3 : 1000 \t\t 4 : 2000 \n\t 5 : 5000 \t\t 6 : 10000 \n\t\t 7 : Enter Amount \n\t\t 8 : Cancel Transaction \nEnter the number which Amount you want to debited : \a");
		                                  int menue=0;
			                           menue : if(menue< 3)
		                                            {  
				                              scanf("%d",&n);
					                      switch(n) 
						                {
						                  case 1 : 
								   	    printf("Enter Your ATM Pin : \a");
								  	    int chance = 0;
								  	    ab : if(chance < 3)
								  	            {
									  	             scanf("%d",&p2);
									  	             if(p1 == p2)
												  {
													  if(x>=200)
													    {
													      printf("Rs 200 is successfully Debited from your account \n");
													      printf("Collect Your Cash ");     
													      x=x-200;
													      printf("\nRemaining Balance : %d ",x);     
													    }
													  else 
													    {
													      printf("Insuficient Balance in your account");
													    }
											  
												 }
											     else
												 {
													   printf("Invalied Pin ");
													   chance++;
													   goto ab;
												 }  
									   
								                   }
									         else
									           {
											 printf("WARNING...\a");
											 return 0;
									           }										 
									        break;                              
						        
						        
				                
						      	         case 2 :
								      printf("Enter Your ATM Pin : \a");
						   	              int a=0;
					          		      a : if(a < 3)
									       {
										    scanf("%d",&p2);
										    if(p1 == p2)
										         {
											      if(x>=500)
											          {
											             printf("Rs 500 is successfully Debited from your account ");
											             printf("Collect Your Cash ");     
											             x=x-500;
											             printf("\nRemaining Balance : %d ",x);               
											          }
											      else 
											          {
											            printf("Insuficient Balance in your account");
											          }
											  
										         }
										    else
										      {
											 printf("Invalied Pin \a");
											 a++;
											 goto a;
										      } 
										} 
									    else
									       {
										   printf("WARNING...\a");
										   return 0;
									       }               
								        break;      
										   
								   
							      case 3 : 
								    printf("Enter Your ATM Pin : \a");
								    int b=0;
							  	    b : if(b < 3)
								            {  
								  	       scanf("%d",&p2);
								  	       if(p1 == p2)
									            {
										       if(x>=1000)
										            {
											       printf("Rs 1000 is successfully Debited from your account ");
											       printf("Collect Your Cash ");     
											       x=x-1000;
											       printf("\nRemaining Balance : %d ",x);                            
										            }
										       else 
										            {
										               printf("Insuficient Balance in your account");
										            }
									   
									            }
									       else 
									          {
									             printf("Invalied Pin \a");
									             b++;
									             goto b;
									         } 
									   }  
									else
									   {
									      printf("WARNING...\a");
									      return 0;
									   }  
								  break;    
				        
				           
						            case 4 : 
								  printf("Enter Your ATM Pin : \a");
								  int c=0;
								  c :if(c < 3)
								         {  
							  	           scanf("%d",&p2);
							  	           if(p1 == p2)
								                 {
								                    if(x>=2000)
									                {
											    printf("Rs 2000 is successfully Debited from your account ");
											    printf("Collect Your Cash ");     
											    x=x-2000;
											    printf("\nRemaining Balance : %d ",x);                            
										         } 
								                    else 
									               {
									                  printf("Insuficient Balance in your account");
									               }
								                 }  
								           else
								              {
								                 printf("Invalied Pin \a");
								                 c++;
								                 goto c;
								              } 
								          }
								     else
								        {
								           printf("WARNING ...\a");
								           return 0;
								        }         
								break;   
				          
				           
						           case 5 :  
							        printf("Enter Your ATM Pin : \a");
							        int d=0;
							        d : if(d < 3)
								         {  
							  	           scanf("%d",&p2);
							  	           if(p1 == p2)
								               { 
								                  if(x>=5000)
								                      {
									                  printf("Rs 5000 is successfully Debited from your account ");
									                  printf("Collect Your Cash ");     
									                  x=x-5000;
									                  printf("\nRemaining Balance : %d ",x);                            
								                      }
								                   else 
								                      {
									                  printf("Insuficient Balance in your account");
								                      }
							    
								              }
								           else
								              {
								                 printf("Invalied Pin \a");
								                 d++;
								                 goto d;
								              }  
								         }
								      else
								         {
								            printf("WARNING ...\a");
								            return 0;
								         }     
								     break; 
				           
				           
							   case 6 : 
							         printf("Enter Your ATM Pin : \a");
							         int e=0;
							         e : if(e < 3)
								          {  
							  	            scanf("%d",&p2);
							  	            if(p1 == p2)
								                {
								                  if(x>=10000)
								                      {
											  printf("Rs 10000 is successfully Debited from your account ");
											  printf("Collect Your Cash ");     
											  x=x-10000;
											  printf("\nRemaining Balance : %d ",x);                            
								                      }
								                   else 
								                      {
									                  printf("Insuficient Balance in your account");
								                      }
								     
								                }
							             	     else
								                {
								                  printf("Invalied Pin \a");
								                  e++;
								                  goto e;
								                }
								          }
								      else
								          {
								             printf("WARNING ...\a");
								             return 0;
								          }          
								    break; 
				          
								   
							     case 7 : 
								      printf("Please Enter Debit Amount in multiple of 100 : \a");
								      int amt=0;
								      amt : if(amt < 3)
								                 {  
								                    scanf("%d",&y);
								                    if(y%100 == 0)
								                        {
								                      	    printf("Enter Your ATM Pin : \a");
								  	                    pin : scanf("%d",&p2);
								  	                    if(p1 == p2)
									                        {
									                           if(y>=0)
										                      {
										                         if(y>=100) 
										                            { 
											                       if(x>=y)
											                          {
											                              printf("Rs %d is successfully Debited from your account \n",y);
											                              printf("Collect Your Cash ");     
											                              x=x-y;
											                              printf("\nRemaining Balance : %d",x);                           
											                          }
											                       else 
											                          {
											                             printf("Insuficient Balance in your account");
											                          }
										                            }										  
										                         else
										                            {
										                               printf("Please Enter Amount Above 100 : \a");
										                               goto amt;
										                            }
										                      } 									       
									                           else
										                      {
										                         printf("You Entered Amount is Invalid please Enter valied amount : \a");
										                         goto amt;
										                      }
									                       }
									                    else
									                       {
									                          printf("Invalied Pin \a");
									                          amt++;
									                          goto pin;
									                       }    									 
									                 }
									 
								                     else
								                       {
									                   printf(" Invalid amount \a");
									                   amt++;
									                   goto amt;
								                       }
								                 }
								             else
								                {
						                                  printf("WARNING...\a");
			 					                  return 0;
								                }
								      break;      
							     
							  case 8 : 
							             break;
								
							  default : 
							            printf("Invalied operation ");
								    menue++;
								    goto menue;
						        }             
						break; 
			                      }			   
			                  else
                                            {
                                               printf("WARNING...");
                                               return 0; 
                                            }        
			            
			             case 3 :
			                       printf("Amount in your account is Rs %d \a",x);
				               break;
				 
		                    case 4 : 
		                              break;
		               
		                    default : 
		                               printf("Invalied operation \a");
		                               caunt++;
		                               goto main;
		                 }
	                     }      
                         else
                            {
                              printf("WARNING...");
                              return 0; 
                            }   
                       }    
                   else
                     {
                        printf("Invalied Initial Amount \a");
                        am++;
                        goto amount;     
                     } 	 
                  }
              else
                 {
                    printf("WARNING..\a");
                    return 0;
                 }
            }
         else
            { 
              count++;
              printf("Invalied Pin \a");
              goto p;
           }
        }
     else
        {
          count++;
          printf("Invalied Pin \a"); 
          goto p;
       }
    }  
 else
    {
      printf("WARNING...\a");
      return 0;
    }
  
  printf("\n  Thank You For Visit \n  Visit Again \n  Have A Nice Day ...\n");   
  return 0;
} 
                             
