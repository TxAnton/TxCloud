import os
import sys

#arg0:
#arg1: exec name

#arg2: tests folder name

#arg3: test prefix name

#arg4: answer prefix name

#arg5: prog result prefix name

#arg6: tests  count

#lab2 Tests test answer result 6
assert(len(sys.argv)==7)

nOfTests = int(sys.argv[6])

for i in range(1, nOfTests+1):
	pathToTest= "./"+sys.argv[2]+"/"+sys.argv[3]+str(i)
	pathToAns = "./"+sys.argv[2]+"/"+sys.argv[4]+str(i)
	pathToRes = "./"+sys.argv[2]+"/"+sys.argv[5]+str(i)
	
	os.system("./"+sys.argv[1] + " < " + pathToTest + " > "+ pathToRes )
	
	f = open(pathToTest)
	test = f.read().strip()
	f.close()
	f = open(pathToAns)
	ans = f.read().strip()
	f.close()
	f = open(pathToRes)
	res = f.read().strip()
	f.close()
	print("\nTest #"+str(i) + " " + "SUCCESS" if ans==res else "FAIL")
	print("Input:")
	print(test)
	print("Expected result:")
	print(ans)
	print("Result:")
	print(res)
	os.remove(pathToRes)