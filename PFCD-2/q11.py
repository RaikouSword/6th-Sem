class Dog:
    def speak(self):
        return "Woof! Woof!"

class Robot:
    def speak(self):
        return "Processing audio output..."

def describe(entity):
    print(f"The entity says: {entity.speak()}")

d1 = Dog()
b1 = Robot()

describe(d1)
describe(b1)