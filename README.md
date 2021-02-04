# Hospital_Data_Management

PROJECT DESCRIPTION:
1) The program allows the user to maintain a Hospital data base management system.

2)	Each Patient profile consists of the patient’s roll number, name, date of appointment and remarks. 

3) In the Drop Down Menu, the user can choose between various options whether to add the details of a new patient, modify details of patient, book an appointment and search about the details of the patient.


PROGRAM ALGORITHM

1) The execution begins in the main().

2) The user views the main menu first and is given a list of options to choose from. 

3) Depending on the choice, program begins further.

4) If user chooses to create a new record, getdata() function is called to get patient details from the user. Execution then returns to the main.

5) If user chooses to search for an existing record, he is then asked to enter the patient number to be searched and an if statement is used check whether the record of that patient exists. 

6) If the record exists, putdata function is called. If it does not exist, program gives an output “No record found”. 

7) Execution then returns to the main. 

8) If user chooses to modify an existing record, he is then asked to enter the patient number of patient whose record needs to be modified and an if statement is used check whether the record of that patient exists. 

9) If the record exists, the user is asked to enter the new details of the patient.

10) If record does not exist, the program will give an output that reads “No record found”. 

11) If user chooses to book an appointment, he is then asked to enter the date at which he wants the appointment for and then an if statement is used check whether that date is already taken by some other patient.

12) If not then appointment is confirmed, else appointment booking ceases.

13) After each choice, with the use of a do-while loop, the user is asked whether they want to return to the main menu. 

14) The Main Menu keeps appearing as long as their answer remains “y”.
