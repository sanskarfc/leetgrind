class Vehicle():
    def __init__(self, num_of_tyres):
        self.num_of_tyres = num_of_tyres

class Car(Vehicle):
    def __init__(self, number_of_tyres, car_name, car_type):
        super().__init__(number_of_tyres)
        self.car_name = car_name
        self.car_type = car_type

    def getCarDetails(self):
        print(f"car name: {self.car_name}, car type: {self.car_type}, number of tyres: {self.num_of_tyres}")

car = Car(4, "santro", "hatchback")
car.getCarDetails()
