
import os
import random


def main():
    name = "/home/box/tmp"
    os.mkdir(name) 
    os.chdir(name)
    level = int(7)
    go(level)
    

def go(level):
    if random.randint(0,4) > 1:
        name = "add"
    else:
        name = "mul"
    os.mkdir(name)
    os.chdir(name)
    level -=1
    while level>0:
        file_amount = random.randint(1,10)
        create_files(file_amount)
        if level>1:
            if random.randint(1,5) > 2:
                name = "add"
            else:
                name = "mul"
            os.mkdir(name)
            os.chdir(name)
        level -= 1


def create_files(amount):
    for i in range (1, amount+1):
        file = open(str(i)+".txt", mode="w")
        num_list = gen_numbers()
        for i in num_list:
            file.write(str(i)+" ")
        file.close()


def gen_numbers():
    amount = random.randint(1,5)
    num_list = list()
    for i in range(amount):
        number = random.randint(-10,10)    
        num_list.append(number)
    return num_list

if __name__ == "__main__":
    main()


