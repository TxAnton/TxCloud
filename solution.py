import os
import re
import sys

def main():
    value_stack = list()
    amount_stack = list()
    action_stack = list()
    walk(amount_stack, value_stack, action_stack)
    res = count(amount_stack, value_stack, action_stack)
    print(res)


def count(amount_stack, value_stack, action_stack):
    for i in range(len(action_stack)-1,-1,-1):
        amount = amount_stack[i]
        amount_stack.pop(i)
        action = action_stack[i]
        action_stack.pop(i)
        value_list = list()
        for j in range(amount):
            value_stack_len = len(value_stack)
            if type(value_stack[value_stack_len-1]) == type(""):
                value_list += get_from_txt(value_stack[value_stack_len-1])
            else:
                value_list.append(value_stack[value_stack_len-1])
            value_stack.pop(value_stack_len-1)
            
        if action == "add":
            value_stack.append(add(value_list))
        else:
            value_stack.append(mul(value_list))
    return value_stack[0]   


def add(value_list):
    res = 0
    for i in value_list:
        res += i
    return res


def mul(value_list):
    res = 1
    for i in value_list:
        res *= i
    return res


def get_from_txt(path):
    file = open(path)
    line = file.read()
    file.close()
    res_list = [int(i) for i in line.strip().split(" ")]
    return res_list


def walk(amount_stack, value_stack, action_stack):
    tree = os.walk("/home/box/tmp")
    flag = 0
    for node in tree:
        if flag == 0:
            flag = 1
            continue
        pattern = r"[\w]*$"
        res = re.findall(pattern, node[0])
        action_stack.append(res[0])
        counter = len(node[1]) + len(node[2])
        amount_stack.append(counter)
        for i in node[2]:
            value_stack.append(node[0] + "/" + i)
            
if __name__ == "__main__":
    main()
