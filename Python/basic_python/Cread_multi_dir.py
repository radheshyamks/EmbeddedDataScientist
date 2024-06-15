import os;
MAX_FLDR=1002
Path=os.getcwd()
print(Path)
for i in range(MAX_FLDR):
    if not os.path.exists(os.path.join(Path,'Host'+str(i))):
        os.mkdir(os.path.join(Path,'Host'+str(i)))
        print(os.path.join(Path,'Host'+str(i)))
    else:
        print('File exist')