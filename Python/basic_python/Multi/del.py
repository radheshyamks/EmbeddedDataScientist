import os
MAX=10
Org_path=os.getcwd()
def delete_dir(cur_path):
    for dir_lst in os.listdir(os.path.join(cur_path)):
        path = os.path.join(cur_path,dir_lst)
        if os.path.isfile(dir_lst):
            pass
        else:
            delete_dir(path)
    # try:
        if cur_path==Org_path:
            print(cur_path)
            return
        else:
            os.rmdir(cur_path)
    # except PermissionError:
        # print('Not delted')
        # pass
for i in range(MAX):
    delete_dir(os.getcwd())