people = 30
cars = 40
trucks = 15
if (cars > people and cars < trucks):
    print("We should take cars")
elif (cars < people):
    print("We should not take cars")
else:
    print("We can't decide")

if (trucks > cars):
    print("There are too many trucks")
elif (trucks < cars):
    print("May be we could take the trucks")
elif (trucks < people):
    print("This wont print")
else:
    print("We still can't decide")

if (people > trucks):
    print("Alright, lets just take the trucks")
else:
    print("Fine, Lets stay at home")
