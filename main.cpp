/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////
     Progame by group 6 Thilina Satoru

     Admin panel
     password     : 12345
     
 *///////////////////////////////////////////////////// HEADER FILES /////////////////////////////////////////////////////////
#include<iostream>  // (standard I/O functions)             - cin,cout...
#include<conio.h>   // (Ms-Dos I/O functions)               - getch(),system("color 0A") clrscr,text,background colors... 
#include<stdlib.h>  // (Standard General Utilities Library) - System(),system("cls")...
#include<windows.h> // (Windows API functions)              - Sleep()... [wait for a current thread for a specified time]
#include<iomanip>   // (defines the manipulator functions)  - setw()

using namespace std;

///////////////////////////////////////////////////////  defining functions to the compiler
void menu();          // display main menu
void Admin_List();    // display admin panel menu
void welcome();       // welcome screen
void get_quantity();  // input quantity query
void confirm();       // confirmation screen for food choice
void out_stock();     // error out of stock
void pls_correct();   // error invalid
void no_zero();       // error not zero
void Total();         // display total

// classess of employees and foods in the system
class employee
{
	public:
		string duty;
		string name;
        int code;
        string contact;
        int age;
};

class food
{
	public:
		string foodname;
        int quantity;
        float price;
        int data;
		float tot_price; // adds purchased 
};


//long term variables
float total;
float subtotal[5];
float cost;
int quantity;


int main()////////////////////////main//////////////////////////main/////////////////////////main///////////////////////
{


	////////////////////////////    FOOD DATA   enter food data if you want
	food f1;
	f1.foodname ="doughnut";
	f1.data =1;
	f1.price=60.00;
	f1.quantity=20;
	f1.tot_price=subtotal[0];
	food f2;
	f2.foodname="Pan-Pizza";
	f2.data=2;
	f2.price=200.00;
	f2.quantity=10;
	f2.tot_price=subtotal[1];
	food f3;
 	f3.foodname="Ham-Burger";
	f3.data=3;
	f3.price=150.00;
	f3.quantity=12;
	f3.tot_price=subtotal[2];
	food f4;
	f4.foodname="Hot-dogs";
	f4.data=4; 
	f4.price=70.00;
	f4.quantity=25;
	f4.tot_price=subtotal[3];
	food f5;
	f5.foodname="Vegi-Burger";
	f5.data=5;
	f5.price=100.00;
	f5.quantity=20;
	f5.tot_price=subtotal[4];
	// ////////////////////////////   EMPLOYEE DATA   enter employee data if you want
	employee e1;
	e1.code=27;
	e1.duty="Manager";
	e1.name="Anuradha";
	e1.age=20;
	e1.contact="GADSE191F-027";
	employee e2;
	e2.code=28;
	e2.duty="cashier 1";
	e2.name="Viduni";
	e2.age=22;
	e2.contact="GADSE191F-028";
	employee e3;
	e3.code=29;
	e3.duty="treasurer";
	e3.name="Kalana";
	e3.age=20;
	e3.contact="GADSE191F-029";
	employee e4;
	e4.code=30;
	e4.duty="cashier 2";
	e4.name="Satoru";
	e4.age=21;
	e4.contact="GADSE191F-030";

	system("cls");      //  clear CMD screen
	system("color 0A"); // set text color green
    welcome();          // welcome text animation

    mainmenu:  //------------------------------------------------------------------   main menu   ---------------------------------------------------------------------------
    
	menu();	
	int menu_choice; 
	cin >> menu_choice;

	if((menu_choice >=1 && menu_choice <=3)) // then valid choice
	{
		if(menu_choice==1) // then list food items
		{
			foodlist:      //-------------------------labeled statement------------------food

			system("cls");
			cout <<"\n\t\t=>0. Main Menu " << endl;
			cout << "\n\t\t";
			cout << "_____________________________________________________________ "<< endl;
			cout << "\n\t\t";
			cout << "\n\t\t\t\t|  Item No.  |   Item Name   |  Price  |   Available   |"<< endl;
			cout << "\n\t\t"<< endl;
			cout << "\t\t\t\t   "<< f1.data  <<  "\t\t" <<std::left<< setw(13) << f1.foodname  <<"\tRs." <<  f1.price  <<"\t\t" << f1.quantity  << endl;Sleep(100);
			cout << "\t\t\t\t   "<< f2.data  <<  "\t\t" <<std::left<< setw(13) << f2.foodname  <<"\tRs." <<  f2.price  <<"\t\t" << f2.quantity  << endl;Sleep(100);
			cout << "\t\t\t\t   "<< f3.data  <<  "\t\t" <<std::left<< setw(13) << f3.foodname  <<"\tRs." <<  f3.price  <<"\t\t" << f3.quantity  << endl;Sleep(100);
			cout << "\t\t\t\t   "<< f4.data  <<  "\t\t" <<std::left<< setw(13) << f4.foodname  <<"\tRs." <<  f4.price  <<"\t\t" << f4.quantity  << endl;Sleep(100);
			cout << "\t\t\t\t   "<< f5.data  <<  "\t\t" <<std::left<< setw(13) << f5.foodname  <<"\tRs." <<  f5.price  <<"\t\t" << f5.quantity  << endl;Sleep(100);
			cout << "\n\t\t";
			cout << "-------------------------------------------------------------"<< endl; Sleep(100);

				cout << "\n\t\t";

		}
		else if( menu_choice==2) // then authenticate
		{
			adminpanelchoice:   // goto statement provides an unconditional jump to a labeled statement (in the same function)

				int admin_pannel_pass;

				system("cls");
				cout <<"\n\t\t=> 0. Main Menu " << endl;
				cout << "\n\n\n\n\t\t Please Enter Passcode(int.)"<< endl;
				cout << "\t\t              or              "<< endl;
				cout << "\t\t  press 0 to Back in Main Menu       : ";
				cin >> admin_pannel_pass;  // input admin pass

			if(admin_pannel_pass==12345)   // then password correct. admin options
			{

				adminchoice: //------------------------------------------------ admin choice

						Admin_List();        // list of admin choices
						int admin_choice;
					    cin >> admin_choice; // input admin choice

					    if(admin_choice==1)  // choice 1
					    {
					    	displayearnigs:  // display details of earnings
				    		system("cls");
							cout << "\n\t\t";
							cout << "_____________________________________________________________ "<< endl;
							cout << "\n\t\t";
							cout << "\n\t\t\t\t|  Item No.  |   Item Name   |  Price  |   total earnings   | "<< endl;
							cout << "\n\t\t"<< endl;
							cout << "\t\t\t\t   "<< f1.data  <<  "\t\t" <<std::left<< setw(13) << f1.foodname  <<"\tRs." <<  f1.price  <<"\t\tRs." << f1.tot_price   << endl;Sleep(100);
							cout << "\t\t\t\t   "<< f2.data  <<  "\t\t" <<std::left<< setw(13) << f2.foodname  <<"\tRs." <<  f2.price  <<"\t\tRs." << f2.tot_price   << endl;Sleep(100);
							cout << "\t\t\t\t   "<< f3.data  <<  "\t\t" <<std::left<< setw(13) << f3.foodname  <<"\tRs." <<  f3.price  <<"\t\tRs." << f3.tot_price   << endl;Sleep(100);
							cout << "\t\t\t\t   "<< f4.data  <<  "\t\t" <<std::left<< setw(13) << f4.foodname  <<"\tRs." <<  f4.price  <<"\t\tRs." << f4.tot_price   << endl;Sleep(100);
							cout << "\t\t\t\t   "<< f5.data  <<  "\t\t" <<std::left<< setw(13) << f5.foodname  <<"\tRs." <<  f5.price  <<"\t\tRs." << f5.tot_price   << endl;Sleep(100);
							cout << "\n\t\t";
							cout << "-------------------------------------------------------------"<< endl; Sleep(100);

								cout << "\n\t\t";
                                
							    total=subtotal[0]+subtotal[1]+subtotal[2]+subtotal[3]+subtotal[4]+subtotal[5];
								Total();  // calculate and show tatal money earned ---------------------------++++++++++++++-
								cout <<"\n\t\t====>  press any key to go back.......  <========= " << endl;
								getch();

							    goto adminchoice;
						}
						else if (admin_choice==2) // view employee data 
						{
							system("cls");
							cout << "\n\n\n\t\t";
							cout << "______________________________________________________ "<< endl;
							cout << "\n\t\t";
							cout << "\n\t\t\t  |   Code  |     Duty     |     Name    |     Age     |      Contact     | "<< endl;
							cout << "\n\t\t"<< endl;
							cout << "\t\t\t\t"<< e1.code  <<  "\t"<<std::left << setw(10) << e1.duty  <<"\t" << setw(10) <<  e1.name  <<"\t" << e1.age <<"\t   "<< e1.contact << endl;Sleep(100);
							cout << "\t\t\t\t"<< e2.code  <<  "\t"<<std::left << setw(10) << e2.duty  <<"\t" << setw(10) <<  e2.name  <<"\t" << e2.age <<"\t   "<< e2.contact << endl;Sleep(100);
							cout << "\t\t\t\t"<< e3.code  <<  "\t"<<std::left << setw(10) << e3.duty  <<"\t" << setw(10) <<  e3.name  <<"\t" << e3.age <<"\t   "<< e3.contact << endl;Sleep(100);
							cout << "\t\t\t\t"<< e4.code  <<  "\t"<<std::left << setw(10) << e4.duty  <<"\t" << setw(10) <<  e4.name  <<"\t" << e4.age <<"\t   "<< e4.contact << endl;Sleep(100);
							cout << "\n\t\t";
							cout << "-------------------------------------------------------"<< endl; 
							cout << "\n\t\t";
							cout <<"\n\t\t====>  press any key to go back.......  <========= " << endl;
							getch();
							
							goto adminchoice; // goto statement provides an unconditional jump from the goto to a labeled statement in the same function
						}
						else if(admin_choice==0) // back to main menu
						{
							goto mainmenu;
						}
						else
						{
							pls_correct();
							goto adminchoice;
						}

			}
			else if(admin_pannel_pass==0)
			{
				goto mainmenu;
			}
			else
			{
				cout << "\t\t\t\n\n---------------> please try again <----------------- " << endl;
				Sleep(500);
				goto adminpanelchoice;
			}
		}
		else if (menu_choice==3)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\tThank You For Using Our System. \n\n\t\t\t\t Brought To You By 'GROUP 6 TEAM' \n\n\n\n\n\n\n";
			Sleep(1000);
			exit(1); // exits the main program
			cout <<"\n\t\t====>  press any key to exit.......  <========= " << endl;
			getch();

		}
	}
	else
		{
			pls_correct();
			goto mainmenu;
		}
	//------------------------------------------------------------------------   end main menu  -------------------------------------------------------

	int food_choice;
	int confirm_choice=0;
	cout << "Place Your Order:(item No.) ";
				cin >> food_choice;
			if(food_choice==0)      //choice no  ///////////////////////////
			{
				goto mainmenu;
			}
			
			
			
			if(food_choice==1)	    // choice 1   ///////////////////////////////
			{
				if (f1.quantity==0)
				{
					out_stock();   // out stock massage
					goto foodlist;
				}

				get_quantity();    //  enter quantity

			    if(quantity > f1.quantity)
				{
					system("cls");
					cout << "\n\n\n\t\t\t-------------------> Sorry! Only\t"<<f1.quantity<<"\tAvailable !<---------------------";
					Sleep(2000);
					goto foodlist;
				}
				else if(quantity==0)
				{
					no_zero();
					goto foodlist;
				}
					confirm();
					cin >> confirm_choice;

					if (confirm_choice==2)
					{
						goto foodlist;
					}
					else if(confirm_choice==1)
					{
					system("cls");
					f1.quantity = f1.quantity - quantity;   // quantity available
					cost = f1.price * quantity;   // subtotal of food
					cout <<"\n\n\n\n\t\t\t---> "<< quantity<<"x"<< f1.foodname <<"\t succesfull ! <---" <<endl;
					cout <<"\n your cost : Rs." << cost;
					f1.tot_price=f1.tot_price+cost;
					Sleep(2000);
					goto foodlist;
					cost=0;
				    }
				    else
					{
						pls_correct();
						goto foodlist;
					}


			}
			else if(food_choice==2)   // choice 2   /////////////////////////////
			{
				if (f2.quantity==0)
				{
					out_stock();      // out stock massage
					goto foodlist;
				}

				get_quantity();       //  enter quantity

			    if(quantity > f2.quantity)
				{
					system("cls");
					cout << "\n\n\n\t\t\t-------------------> Sorry! Only\t"<<f2.quantity<<"\tAvailable!<---------------------";
					Sleep(2000);
					goto foodlist;
				}
				else if(quantity==0)
				{
					no_zero();
					goto foodlist;
				}
					confirm();
					cin >> confirm_choice; 

					if (confirm_choice==2)
					{
						goto foodlist;
					}
					else if(confirm_choice==1)
					{
					system("cls");
					f2.quantity = f2.quantity - quantity;  // quantity available
					cost = f2.price * quantity;    // subtotal of food
					cout <<"\n\n\n\n\t\t\t---> "<< quantity<<"x"<< f2.foodname <<"\t succesfull! <---" <<endl;
					cout <<"\n your cost : Rs." << cost;
					f2.tot_price=f2.tot_price+cost;
					Sleep(2000);
					goto foodlist;
					cost=0;
				    }
				    else
					{
						pls_correct();
						goto foodlist;
					}

			}
			else if(food_choice==3)  // choice 3   /////////////////////////////
			{
				if (f3.quantity==0)
				{
					out_stock();     // out stock massage
					goto foodlist;
				}

				get_quantity();      //  enter quantity

			    if(quantity > f3.quantity)
				{
					system("cls");
					cout << "\n\n\n\t\t\t-------------------> Sorry! Only\t"<<f3.quantity<<"\tAvailable!<---------------------";
					Sleep(2000);
					goto foodlist;
				}
				else if(quantity==0)
				{
					no_zero();
					goto foodlist;
				}
					confirm();
					cin >> confirm_choice;

					if (confirm_choice==2)
					{
						goto foodlist;
					}
					else if(confirm_choice==1)
					{
					system("cls");
					f3.quantity = f3.quantity - quantity;   // quantity available
					cost = f3.price * quantity;   // subtotal of food
					cout <<"\n\n\n\n\t\t\t---> "<< quantity<<"x"<< f3.foodname <<"\t succesfull! <---" <<endl;
					cout <<"\n your cost : Rs." << cost;
					f3.tot_price=f3.tot_price+cost;
					Sleep(2000);
					goto foodlist;
					cost=0;
				    }
				    else
					{
						pls_correct();
						goto foodlist;
					}

			}
			else if(food_choice==4)  // choice 4   /////////////////////////////
			{
				if (f4.quantity==0)
				{
					out_stock();     // out stock massage
					goto foodlist;
				}

				get_quantity();      //  enter quantity

			    if(quantity > f4.quantity)
				{
					system("cls");
					cout << "\n\n\n\t\t\t-------------------> Sorry! Only\t"<<f4.quantity<<"\tAvailable!<---------------------";
					Sleep(2000);
					goto foodlist;
				}
				else if(quantity==0)
				{
					no_zero();
					goto foodlist;
				}
					confirm();
					cin >> confirm_choice;

					if (confirm_choice==2)
					{
						goto foodlist;
					}
					else if(confirm_choice==1)
					{
					system("cls");
					f4.quantity = f4.quantity - quantity;   // quantity available
					cost = f4.price * quantity;   // subtotal of food
					cout <<"\n\n\n\n\t\t\t---> "<< quantity<<"x"<< f4.foodname <<"\t succesfull! <---" <<endl;
					cout <<"\n your cost : Rs." << cost;
					f4.tot_price=f4.tot_price+cost;
					Sleep(2000);
					goto foodlist;
					cost=0;
				    }
				    else
					{
						pls_correct();
						goto foodlist;
					}

			}
			else if(food_choice==5)  // choice 5   /////////////////////////////
			{
			if (f5.quantity==0)
				{
					out_stock();    // out stock massage
					goto foodlist;
				}

				get_quantity();     //  enter quantity

			    if(quantity > f5.quantity)
				{
					system("cls");
					cout << "\n\n\n\t\t\t-------------------> Sorry! Only\t"<<f5.quantity<<"\tAvailable!<---------------------";
					Sleep(2000);
					goto foodlist;
				}
				else if(quantity==0)
				{
					no_zero();
					goto foodlist;
				}
					confirm();
					cin >> confirm_choice;

					if (confirm_choice==2)
					{
						goto foodlist;
					}
					else if(confirm_choice==1)
					{
					system("cls");
					f5.quantity = f5.quantity - quantity;  // quantity available
					cost = f5.price * quantity;  // subtotal of food
					cout <<"\n\n\n\n\t\t\t---> "<< quantity<<"x"<< f5.foodname <<"\t succesfull! <---" <<endl;
					cout <<"\n your cost : Rs." << cost;
					f5.tot_price=f5.tot_price+cost;
					Sleep(2000);
					goto foodlist;
					cost=0;
				    }
				    else
					{
						pls_correct();
						goto foodlist;
					}
			}



	else
	{
		pls_correct();
		goto foodlist;
	}





}
//-------------------------------------------------------------------------------- end main ----------------------------

////  functions    ///////////////////////
void menu()
{
	Sleep(400);
	system("cls");

	cout << "\n\n\n\n\n\t\t\t --------->>>> Main menu <<<<--------- "; Sleep(250);
	cout << "\n\n\n\n\n\t\t\t>> 1. Item List"; Sleep(250);
	cout << "\n\n\t\t\t>> 2. Admin Panel"; Sleep(250);
	cout << "\n\n\t\t\t>> 3. Exit programme \t";  Sleep(250);
	cout << "\n\n\n\n\n\t\t\t ------------------------------------- ";Sleep(250);
    cout << "\n\n\n\n\t\t\t\t Select your option :";
}
void welcome() 
{
	cout <<"\n\n\n\n\n\t\t\t\t\t\tWELCOME"<< endl;
	Sleep (500);
	cout <<"\n\n\t\t\t\t\t\t\t TO" << endl;
	Sleep (500);
	cout << "\n\n\n\t\t\t\t\t\t FOOD"<< endl;
	Sleep (500);
	cout <<"\n\n\n\t\t\t\t\t\t\t MANAGEMENT SYSTEM"<< endl;
	Sleep (500);
}
void Admin_List()
{
	Sleep(300);
	system("cls");
	cout <<"\n\t\t=>0. Main Menu " << endl;
	cout << "\n\n\n\n\n\t\t\t ----------->>>> Admin Panel <<<<--------- "; Sleep(250);
	cout << "\n\n\n\n\n\t\t\t>> 1.Total Cash "; Sleep(250);
	cout << "\n\n\t\t\t>> 2. Employees"; Sleep(250);
	cout << "\n\n\t\t\t>> 0. main menu \t";  Sleep(250);
	cout << "\n\n\n\n\n\t\t\t ----------------------------------------- "; Sleep(250);
    cout << "\n\t\t\t Select your option :";
}
void get_quantity()
{
	quantity=0;
	cout << "\n\n\t\t\t\t   How many ?  :";
	cin >> quantity;
}
void confirm() 
{
	system("cls");
	cout << "\n\n\n\t\t\t Are you sure ?  "<< endl; Sleep(100);
	cout << "\n"<< endl;
	cout << "\t\t\t ->1. confirm"<< endl; Sleep(100);
	cout << "\n\t\t\t ->2. cancel"<< endl; Sleep(100);
}
void out_stock() 
{
	system("cls");
	cout << "\n\n\n\t\t\t-------------------> Out of Stock ! <---------------------";
	Sleep(2000);
}
void pls_correct() 
{
	cout << "\n\n\n\t\t\t----------------> Please Enter Correct Choice <------------------";
	Sleep(1000);
}
void no_zero() 
{
	cout << "\t\t\t\n\n-------------------> quantity cannot be zero <---------------------";
	Sleep(1000);
}
void Total() 
{
	cout << "\t\t\t\t\t\t\n\n\n\n  Total Cash Today  :" << total << endl;
	total=0; // reset total incase of view again
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  coding time 12 hours  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   

// Thilina Satoru 



