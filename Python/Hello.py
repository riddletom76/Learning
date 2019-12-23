#Hello World
print("Hello world")

#Drawing a shape
print("   /|")
print("  / |")
print(" /  |")
print("/___|")

#Variables in python
name = "NewName"
print("There was a person named "+ name)
name = "Rishabh"
print("Now the  person named "+ name)
#different types of data that can be stored in the variables
#string - plain text 
#numbers - 50, 100, 50.5678213
#boolean - True, False
booleanValue = True
print(booleanValue)

#working with numbers
# - \n to insert a new line
print("Rishabh\nSharma")
# - \" to insert a quotation mark
print("Rishabh\"Sharma")
#concatination
phrase = "Rishabh Sharma"
print(phrase+" is a student")
#converting a phrase to lowercase
print(phrase.lower())
#converting to uppercase
print(phrase.upper())
#check if upper or lower
print(phrase.isupper())
#chaining functions
print(phrase.upper().isupper())
#indexing the characters in string
print(phrase[0])
#get index of a character - (is case sensitive)
print(phrase.index("S"))
#replacing a character
print(phrase.replace("Rishabh", "Nice Guy"))

#working with numbers
#converting a number to string
my_num = -5
print(str(my_num)+" my favorite number")
#absolute value
print(abs(my_num))
#exponent value - pow
print(pow(my_num, 3))
#max/min
print(max(4,5))
#round
print(round(3.7))
#floor - this requires you to import math 
from math import * #importing math
print(floor(3.7))
#square root
print(sqrt(25))
#getting input from users
#>>input("Enter your name: ")
#storing the input
#>>age = input("Enter your age: ")
#>>print("Entered age as "+ age)

#Basic calculator in python
#whenver we get e user inout from the user,
#python implicitly converts it into string
#even if you enter a number that will be converted to string
#hence to convert the numric inputs to numbers
#we'll have to use convert functions

#>>num1 = input("enter number1: ")
#>>num2 = input("enter number2: ")
#>>result = num1 + num2
#>>print(result)
#>>result = int(num1) + int(num2)
#>>print(result)

#lists
#everything which we write in between the open and close square
#parenthesis is treated as list
#we can put strings numbers and boolean in one list
friends = ["Kevin", "Karen", "Jim", "Harry", "Sehgal"]
print(friends)
#accessing any element of the list
#any element of the list can be accessed
#using the index which is a zero based 
print(friends[0])
#when we use negative index
#it starts travesing the list in reverse direction
print(friends[-1])
#inorder to print a specific number of elements
print(friends[1:3]) # this will print starting from index 1
# till index 3, including 1 but excluding 3
#-
#if you want to print everything after 1
print(friends[1:])

#exteding an existing list
new_list = ["Hello"]
friends.extend(new_list)
print(friends)
#to append a new element in list
friends.append("Good")
print(friends)
#if want to add a new element at a specific index
friends.insert(1,'Rishabh')
print(friends)
#to remove an element from list
friends.remove("Rishabh")
print(friends)
#to pop an element from the list
friends.pop() #this removed the last inserted element in the list
print(friends)
#to clear the whole list
#>>friends.clear()
#>>print(friends)
#to check if a particular element is in the list
print(friends.index("Kevin")) #this helps in knowing
#if an element exist in the list or not
#to count the number of times an element appears in a list
friends.append("Hello")
friends.append("Hello")
print(friends.count("Hello"))
#to sort the list in ascending order
friends.sort()
print(friends)
#to reverse a list
friends.reverse()
print(friends)


#Tuple - tuples are immutable
#tuples are created by ()
coordinates = (4,5)
#once a tuple is created it cannot be changed
print(coordinates[0])
#tuples are used to store data that does not need to
#be changed


#Functions
#in order to define a function keyword def is used

def Say_Hi():
    print("Hello user")
print("Top")
Say_Hi() #calling the function
print("Bottom")
#passing parameters to the function
def Say_Hi(name):
    print("Hello "+name)
Say_Hi("Rishabh")

#Return Statement in Python
def cube(num):
    return num*num*num
print(cube(3))

#If conditions
is_male = True
is_tall = True
if is_male:
    print("Person is male")
else:
    print("Person is not a male")


if is_male or is_tall:
    print("you are male or tall or both")
else:
    print("You are neither male nor tall")


if is_male and is_tall:
    print("you are tall male")
elif is_male and not(is_tall):
    print("you are male but not tall")
elif not(is_male) and is_tall:
    print("you are not male but tall")
else:
    print("You are neither male nor tall")

#Advance calculator
#>>num1 = float(input("Enter first number: "))
#>>op = input("Enter operator: ")
#>>num2 = float(input("Enter second number: "))
op = '&'
if op == '+':
    print (num1 + num2)
elif op == '-':
    print (num1 - num2)
elif op == '*':
    print (num1*num2)
elif op == '/':
    print (num1/num2)
else:
    print ("Please enter a valid operator")

#Dictionary - Key Value pair
monthConversions = {
    "Jan" : "January",
    "Feb" : "February",
    "Mar" : "March"
}

print (monthConversions["Mar"])
print (monthConversions.get("Jan"))
#to get a default value in case the key does not exist in the dictionary
print (monthConversions.get("Jun", "Default value"))

#While loop

i = 1
while i<=10:
    print(i)
    i+=1
print("Done with loop")

#Guessing game in python
secret_word = "Giraffe"
guess = ""
#while guess != secret_word:
#    guess = input("Enter the secret word: ")

print("You win!")

#for loops
for letter in "RishabhSharma" :
    print (letter)
#looping through collection
friends = ["Jim", "Karen", "Kevin"]
for friend in friends:
    print (friend)
#looping through a range
for index in range(10):
    print (index)
#range between two numbers
for index in range(3,10):
    print(index)
for index in range(len(friends)):
    print(friends[index])
for index in range(5):
    if index == 0:
        print ("first iteration")
    else:
        print ("something else")

#Exponent function
def raise_to_power(num, exp):
    result = 1
    for index in range(exp):
        result = result*num
    return result

print(raise_to_power(2,3))
print(raise_to_power(12,2))
print(raise_to_power(15,2))
print(raise_to_power(3,3))

#2D lists & Nested Loops
number_grid = [
    [1,2,3,4],
    [5,6,7,8],
    [9,0]
]

print(number_grid[0][2])
print(number_grid[2][1])
#if you try to access any idex which is not defined in the
#2D collection, then it'll thwo an index out of range exception

#Nested Loops
print("2D List")
for row in number_grid:
    for ele in row:
        print(ele)

#Building a basic translator
def translate(phrase):
    translation = ""
    for letter in phrase:
        if letter.lower() in "aeiou":
            if letter.isupper():
                translation = translation + "G"
            else:
                translation = translation + "g"
        else:
            translation = translation + letter
    return translation

#>>print(translate(input("Enter a phrase ")))

#Comments
'''
This is a multiple line comment
'''
#official guide says to use the HashTag for the comments

#Try/Except
#this is used to catch errors in the program
try:
    value = 10/0
    #number = int(input("Enter a number: "))
    #print(number)
except ZeroDivisionError as err:
    print (err)
except ValueError:
    print("Invalid input")

#Reading from external files
employee_file = open("employees.txt", "r") #r stands for read mode
                        #w stqands for write
                        #a is append which is used to add information
#print(employee_file.read()) #to print the entire content of the file
#print(employee_file.readline()) #to read the file line by line
#print(employee_file.readlines()) #to get a list of each line present in the file
for employee in employee_file.readlines():
    print (employee)
employee_file.close()

#Writing and appending to files in python
employee_file = open("employees.txt","a")
employee_file.write("\nKelly - Customer Service")
employee_file.close()

#write in a file - this overwrites the file #you can also create a new file
#>>employee_file = open("employees.txt", "w")
#>>employee_file.write("Hello - HelloDepartment") #this will erase the existing content and overwrite it with this information
#>>employee_file.close()

#creating a new file
employee_file = open("index.html","w")
employee_file.write("<p>This is a paragraph</p>")
employee_file.close()

#Modules and PIP
#reusing existing python file in another file
#we have made a new file called 'useful_tools.py'
import useful_tools

print(useful_tools.get_file_ext("Hello.py"))
print(useful_tools.roll_dice(10))
#a module is any python external file which you can use
# in your project

# pip is essentially a program which is used to install
# other python modules
# it is essentially a package manager

#Classes and Objects in python
#inorder to represent real world entities we use class
# as they cannot be represented using the data types
# which are supported by python
# we can use classes to define our own data type
from Student import Student
student1 = Student("Rishabh", 24, "RishabhStudentId") # we dont use new to create new object of class
print(student1.name)
print(student1.age)
print(student1.Id)

#multiple choice quiz
question_prompts = [
    "What is up\na) A\nb) B\nc) C\n",
    "What is up\na) A\nb) B\nc) C\n",
    "What is up\na) A\nb) B\nc) C\n"
]
from Question import Question
questions = [
    Question(question_prompts[0], "a"),
    Question(question_prompts[0], "b"),
    Question(question_prompts[0], "c"),
]

def run_the_test(questions):
    score = 0
    for question in questions:
        answer = input(question.prompt)
        if answer == question.answer:
            score += 1
    print ("You got " + str(score) + "/" + str(len(questions)) + " correct")

#>>run_the_test(questions)

#object functions
student1 = Student("Student_1", 17, "Student_1_Id")
student2 = Student("Student_2", 24, "Student_2_Id")
print(student1.is_an_adult())

#Inheritance in python
#in order to inherit a functionalit given by a certain class
#need to pass the name of the class which you want to inherit
#from while initializing the new class
#For ex; if you want to inherit Car class in class Tesla
# class Tesla(Car): # this is how the instantiation will be

def function_name(x):
    x = [1,2]
    print(x)

hello_string = [1,2,4,5]
print(hello_string)
function_name(hello_string)
print(hello_string)