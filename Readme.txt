Purpose: The purpose of this software is to  manipulate records of patients and employees from a hospital.
Developer & Development Date: Iqra McIlveen - March 6, 2018

Software organization: 
	There are 4 .c files consisting of:
		- employee.c
		- patient.c
		- hospital.c
		- populateRecords.c
	There are 4 .h files consisting of:
		- employee.h
		- patient.h
		- populateRecords.h
		- struct.h

Compilation Instructions:
	- Open the terminal and locate the a3 file using the 'cd' command.
	- To compile the files, input:
		gcc hospital.c employee.c patient.c populateRecords.c

Running/using the software:
	- To run, input:
		./a.out
	- Make sure to widen the terminal window, so that the information can be displayed neatly.
	- Once it is running, a menu will come up. Select one of the menu options by inputting its corresponding number and pressing ENTER.

Limitations:
	The user can only choose one of the following options given, hence:
		- They cannot add people.
		- They cannot search employees.
		- Any other option that has not been specified.
	The family name must be spelled with proper capitalization.
		- For example johnson is an invalid name, whereas Johnson is valid.
	The user may have to widen the terminal window themself to display the information as desired.
