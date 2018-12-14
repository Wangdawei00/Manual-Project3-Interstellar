Project 3

README

Project Group 21

REGULAR ONE:

Brief Introduction:

	There are 6 .cpp files in this project, which are main.cpp, slot.cpp, Floor.cpp, parkingLot.cpp, Ticket.cpp, Vehicle.cpp. 
	
	main.cpp is used to call all the related functions and classes. 
                    Slot is the minimum unit of a floor, which means that a floor contains several slots. 
	    Every floor contains 5x5 slots.
                    Similarly, floor is the minimum unit of parkingLot, which means several floors form a parkingLot.
	(attention£ºwe define 1s in real life to be 10 minutes in the programme)
	
	Ticket.cpp contains all the methods and attributes related to ticket, such as printing, recording the time, calculate the price,etc.
	
	Vehicle.cpp contains all the methods and attributes related to vehicles, such as arriving, departing,etc.
	
Main Idea:
	1.the initialization
	2.the for loop: 1)printleaving(vector<Vehicle>)->/*for every floor*/floor.refresh()->(for every slot)we randomly judge whether the vehicle will go or not,if it will, we return a Vehicle
                                            by doing this, we can get a vector of vehicles leaving and then print their tickets
		        2)parkingLot.refreshIn()/* just simply initialze the slot and print the arrival ticket*/

Initialzation:
             ATTENTION: as a player, you need to edit configurations, which can be found in"run",
	 and write something in programme argument such as"--time 25"(25 means the number of cars , which you can change)
	
	as a player, at first, you need to initialize the prices for every kind of vehicle respectively	

	a kind reminder: we can read a file if there's one created by the player to define the names of vehicles;
		          otherwise, we will take  "Car", "Van", "Motorbike", "Bicycle" by default

Detailed Description:

	Because most of those .cpp files above are the interfaces of different classes, I would like to directly explain those classes.
	
	Class Slot:
		Every slot has its type. which is related to the vehicles. That's because the basic floor needs to make all the vehicles stop on this floor belonging to the same type, so that drivers can easily identify which floor to go. And circumstances such as a bike occupying a slot for cars will never happen.
		
		When a slot is initialized, it is empty. And there are methods to identify whether it is empty and also to change its mode.
		
		We put the method "put_vehicle" here which can be easily linked to the methods in the class "ParkingLot"£¬so as "push_vehicle"
		
	Class Floor:	
		Every floor has its type, size(row and column), and index(indicates which floor). Because of the setting of the row and column, some situations such as on different columns, there will be different numbers of slots will never happen, which can let the floor look more tidy.
		
		We use a vector to store an empty slot's [row][column]
		
	Class ParkingLot:		
		We use map to define the variable "floors", which contains a string(indicates its type) and a floor(a type defined in floor.cpp)

		We use clearSlot and pushSlot to do the basic function that a parkingLot needs to do. In pushSlot, there is a code which is linked to a slot method "put_vehicle".
		
	Class Ticket:	
		There are a variable "type" and a virtual method "print" in it.
		
		There are 2 classes inheriting Class Ticket: ArriTicket and DepartTicket.
		
		Class ArriTicket:
			A specific method "print" is stated, only for printing the information when arriving.
			
			Method "set" is used to initialize the statement of the ticket.
			
		Class DepartTicket:
			A specific "print" method is stated, only for printing the information when departing.
			
			Method "set" is used to set the final statement of the ticket.
			
	Class Vehicle:
		Several methods are stated to get the related data. Here we use local time as the standard of the consuming of the time, which means that all the times will be transformed into the form of local time first, and then do the calculation.
		
		Method "setPrice" is used to set the different prices of different vehicles by inputing.





Interstellar:
Brief Introduction:
	
	main.cpp is used to call all the related functions and classes. 
                    Slot is the minimum unit of a parkinglot, which means that a parkinglot contains several slots. 
	   
	
Main Idea:
	1.the initialization(we allow the user to initialize the column of the slots!!!!--special way to initialize,detailed in initialization)
	2.we uses two functions to draw :
		1)drawingInitialize :to make everything move/spin/rotate 
		2)draw: just draw everything
	ATTENTION: it might seem weird when the window is small, zoom it to full-screen!!!!!!! and you will find it normal.


Initialzation:
             ATTENTION: as a player, you need to edit configurations, which can be found in"run",
	 and write something in programme argument such as"--size 5"(5 means the column of the slots , which you can change)


Detailed Description:
	REMINDER: we define various crafts or something like that as class Group £¬ meaning it is the group of several shapes
	
	Shape.cpp/.h :are for basic shapes such as rectangle. They contain various basic shapes as classes.

	Vector.cpp/h: is just for helping us dealing with the coordinates. Inside them, we overload some operators to make our life easier.

	Slot.cpp/h: it contains its center's coordinates;datum(helping for rotating or something else);
		and most importantly contains a vehicle
		it can store, show and push the vehicle
	
	Figure.h: 
	Figure.cpp it mainly contains various groups as well as their functions
		all kinds of groups inherit from class Group and they all have a special function called special move 
		this is because almost all kinds of groups have its own way to move(like spinning or shining)
	MainFigure.cpp :this is the main class as it contains a parkinglot to deal with all the fucntions
		users only use the methods of this to deal with all the things
	(the both are under the same header file)

	parkinglot.cpp/h: it mainly consists of three things 1. the moving car 2. the initialized settings (such as the slots) 3.all the cars parking in it
	to judge the moving car ,we use several flags so that it can move in a right direction.
	also, the setting and the cars parking in it are easy to draw,
	


	





		