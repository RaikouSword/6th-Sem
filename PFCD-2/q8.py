class Vehicle:
    def __init__(self,make,model):
        self.make = make
        self.model = model
    def display_info(self):
        print("Make: ",self.make)
        print("Model",self.model)

class Car(Vehicle):
    def __init__(self,make,model,num_doors):
        super().__init__(make,model)
        self.num_doors = num_doors
    def display_info(self):
        super().display_info()
        print("Doors: ",self.num_doors)

v1 = Vehicle("ABC","XYZ")
c1 = Car("A","X",4)
v1.display_info()
c1.display_info()
    