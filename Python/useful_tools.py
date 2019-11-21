import random
feet_in_mile = 5280
meters_in_kilometers = 1000
beatles = ["john Lennon", "Paul McCartney", "George Harrison", "Ringo Star"]

def get_file_ext(name):
    return name[(name.index(".") + 1):]

def roll_dice(num):
    return random.randint(1,num)