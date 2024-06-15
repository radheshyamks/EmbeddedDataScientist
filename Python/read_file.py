with open('rough.txt','w') as fd:
    print(type(fd))
    fd.write('Hello, I am radheshyam from Bihar\n')
    fd.write('Hey, this is me and I am from India\n')
    fd.write('Bye, this is me and I am from India')
with open('rough.txt','r') as fd:
    print(type(fd))
    # print(type(fd.read()))
    p = fd.readline()
    while p:
        print(p)
        p=fd.readline()