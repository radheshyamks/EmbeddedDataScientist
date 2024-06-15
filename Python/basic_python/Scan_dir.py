import os;
path = os.getcwd()
print(path)
# print(os.scandir())
dir_list = []
# Here without args, bydefault it will consider as current dir
# for i in os.scandir():
    # print(i)
for dir_1 in os.scandir(path):
    if dir_1.is_dir():
        dir_list.append(dir_1.name)
print(*dir_list)
print(dir_list)