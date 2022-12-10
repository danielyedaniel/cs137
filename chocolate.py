def getCount(x_str,x,y):
	#base case
	if x==0:
		return 1 if y==0 else 0

	count=0
	for i in range(len(x_str)):
		h=int(x_str[i])
		if h<=y and h>0:
			if x>0:
				count+=getCount(x_str,x//10,y-h)+1
	return count

def funcCount(inputNum1, inputNum2):
	# Write your code here
	x_str=str(inputNum1)
	return getCount(x_str,int(inputNum1)-1,int(inputNum2))

print(funcCount(10,3))