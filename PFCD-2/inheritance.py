class Employee:
    bonus = 1000
    def display(self):
        print("This is employee class")
class Manager(Employee):
    bonuss = 2000
    def show(self):
        print("This is manager class")

e = Employee()
m = Manager()
e.display()
m.show()
print(m.bonus)