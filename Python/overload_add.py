class A(object):
    def __init__(self,n1,n2) -> None:
        self.x=n1
        self.y=n2
    def Print_Val(self):
        print('x = ',self.x)
        print('y = ',self.y)
    def __add__(self,other):
        self.x = self.x+other.x
        self.y = self.y+other.y
        return self
    def __del__(self)->None:
        print('memory released')
p1 = A(10,20)
p2 = A(20,30)
p1.Print_Val()
p3 = p1+p2
p3.Print_Val()