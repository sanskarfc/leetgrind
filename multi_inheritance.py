class A:
    def __init__(self):
        self._protected_var = "Protected Variable from A"
        self.__private_var = "Private Variable from A"  # Private due to double underscore prefix

    def public_method(self):
        return "Public Method from A"

    def _protected_method(self):
        return "Protected Method from A"

    # Private method
    def __private_method(self):
        return "Private Method from A"


class B(A):
    def access_protected(self):
        return self._protected_var

    def access_private(self):
        try:
            return self.__private_var  # This will raise an attribute error
        except AttributeError as e:
            return str(e)


class C(A):
    def access_protected(self):
        return self._protected_var

    def access_private(self):
        try:
            return self.__private_var  # This will also raise an attribute error
        except AttributeError as e:
            return str(e)


class D(B, C):
    def demo_method(self):
        return "Method in D"

# Instantiate and use classes
d_instance = D()
print(d_instance.public_method())  # Accessible from A
print(d_instance.access_protected())  # Accessible from B or C, protected in A
print(d_instance.access_private())  # Attempt to access private variable in A

# Checking the Method Resolution Order (MRO)
print(D.mro())  # Prints the method resolution order
