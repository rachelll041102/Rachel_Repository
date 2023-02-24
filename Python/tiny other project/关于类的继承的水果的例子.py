#============基类===============
class Fruit:
    def __init__(self,color="绿色"):    #构造函数   初始化颜色
        Fruit.color=color
    def harvest(self,color):            #丰收函数   需传入颜色
        print("水果是"+color+"的")                  #此时成熟的颜色，是形参，与实参无关
        print("水果已经收获")
        print("水果原来是:"+Fruit.color+"的")       #原本的颜色（即初始化时候的颜色

#=============派生类--苹果=======
class Apple(Fruit):
    def __init__(self):             #重写构造函数
        print("这是苹果")
        super().__init__()          #调用基类的构造函数进行初始化
    def harvest(self,color):    
        print("苹果是"+color+"的")     #传入形参的颜色
        print("水果已经收获")
        print("水果原来是"+Fruit.color+"的")    #原来的颜色是基类的初始化颜色


#==============派生类--人参果=======================
class Sapodilla(Fruit):
    def __init__(self,color):
        print("这是人参果")
        super().__init__(color)
    def harvest(self,color):
        print("人参果是"+color+"的")
        print("人参果已经收获")
        print("人参原来是"+Fruit.color+'的')

#==============================================
#===============================================
#===============================================
#=================================================
apple=Apple()
apple.harvest("红色")
print("=========================================")
sapodilla=Sapodilla("白色")     #构造函数能赋初值，是因为人参类的构造函数，传入的值包括了color 与苹果不一样
sapodilla.harvest("带紫色条纹的")