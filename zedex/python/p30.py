people = 30
cars = 40
trucks = 15
<<<<<<< HEAD
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
=======
if cars > people:
    print("We should take cars.")
elif cars < people:
    print("We should not take the cars.")
else:
    print("We can't decide.")

if trucks > cars:
    print("That's too many trucks.")
elif trucks < cars:
    print("May be we could take the trucks.")
else:
    print("We still can't decide.")

if people > trucks:
    print("Alright, lets just take the trucks.")
else:
    print("Fine, lets stay home then.")



>>>>>>> ad0851f0489895549fdf2638db6a197528816895
