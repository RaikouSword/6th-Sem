class Book:
    pass

class Chapter(Book):
    def __init__(self, ch):
        self.ch = ch
    title = ""
    page_count = 0

b = Book()
c1 = "c1",c2="c2",c3="c3"
b = Chapter([c1,c2,c3])
print(b.ch)