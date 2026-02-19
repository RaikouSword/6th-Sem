class car:
    pass
c1=car()
setattr(c1,"brand","SUV")
setattr(c1,"color","Red")
brandname=getattr(c1,"brand","not avaiable")
print("brand",brandname)
