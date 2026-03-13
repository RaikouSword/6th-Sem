import math
class Shape:
    def area(self):
        pass

class Circle(Shape):
    def __init__(self,radius):
        self.radius = radius
    def area(self):
        return math.pi*(self.radius**2)

class Rectangle(Shape):
    def __init__(self,length,breadth):
        self.length = length
        self.breadth = breadth
    def area(self):
        return self.length*self.breadth

c1 = Circle(10)
r1 = Rectangle(10,10)

print("Circle area: ",c1.area())
print("Rectangle area: ",r1.area())
