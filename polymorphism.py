class Vehicle():
    def __init__(self, name, number_of_tyres, numberPlate):
        self.name = name
        self.number_of_tyres = number_of_tyres
        self._numberPlate = numberPlate

class Car(Vehicle):
    def __init__(self, name, number_of_tyres, company, numberPlate):
        super().__init__(name, number_of_tyres, numberPlate)
        self.company = company

    def getDetails(self):
        print(f"number plate: {self._numberPlate}")

car = Car("santro", "4", "maruti", "1234")
car.getDetails();
