class Student:
    def __init__(self, name, age, Id):
        self.name = name
        self.age = age
        self.Id = Id

    def is_an_adult(self):
        if self.age >= 18:
            return True
        return False