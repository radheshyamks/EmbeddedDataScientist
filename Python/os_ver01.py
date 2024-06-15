#######################################
# Author Name: Radheshyam             #
# Date: 25-08-2023                    #
# Description:                        #
# this file is to create directories  #
######################################
import os;
import time
from colorama import Fore,Style,init
parent_path = r'E:\NotepadPlusPlus\Python'
init(convert=True)
for i in range(1,10):
    if os.path.exists("Env") != True:
       os.makedirs(f'Env/Host_{i}')
       with open(f'Env/Host_{i}/Host_{i}.txt','w') as fp:
        pass
    elif os.path.exists(f'Env/Host_{i}') == False:
        os.mkdir(f'Env/Host_{i}')
        with open(f'Env/Host_{i}/Host_{i}.txt','w') as fp:
            pass
# delete the generated files and folder
dir_list=[]
file_list=[]
perm = input(f"Do you want to {Fore.RED}{Style.BRIGHT}delete{Style.BRIGHT} the Generated{Style.RESET_ALL} files and directories[Yes/No]? ")
if perm=='Yes' or perm=="yes":
    for dir_path, dir_name, file_name in os.walk('Env'):
        for name in file_name:
            file_list.append(os.path.join(os.path.join(parent_path,str(dir_path)),name))
        for Dir in dir_name:
            dir_list.append(os.path.join(os.path.join(parent_path,dir_path),Dir))
    try:
        for f_list in file_list:
            os.remove(f_list)
        for d_list in dir_list:
            os.removedirs(d_list)
        print(f"{Style.BRIGHT}{Fore.GREEN}files{Style.RESET_ALL} and {Style.BRIGHT}{Fore.CYAN}directories {Style.RESET_ALL}are {Style.BRIGHT}{Fore.RED}deleted successfully")
    except OSError:
        print("Error thrown")