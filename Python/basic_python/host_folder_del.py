import os;
MAX_FLDR=1002
Path = os.getcwd()
print(os.getcwd())
for i in range(MAX_FLDR):
    if os.path.exists(os.path.join(Path,'Host'+str(i))):
        print(os.path.join(Path,'Host'+str(i)))
        try:
            os.rmdir(os.path.join(Path,'Host'+str(i)))
        except FileNotFoundError:
            print('File Not Found')
        # print(i)