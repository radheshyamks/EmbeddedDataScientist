# s = "My name is Ravi" # Ravi is name my
s  = input("Enter Text here: ")
l = s.split(" ")
s2=""
for i in range(len(l)-1, -1, -1):
    s2=s2 + l[i] + " " #
print(s2.strip(' '))

# Another way to reverse the string

s1 = s;
s3=''
s4 = ''
for i in s1[::-1]:
    if ' ' == i:
        s4=s4+s3[::-1]+i
        s3=''
    else:
        s3+=i
s4+=s3[::-1]
print(s4)