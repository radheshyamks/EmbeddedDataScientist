import os;
import re;
import shutil
# import colorama;
from colorama import Fore,Style,init;
init(convert=True)
path = r"E:\NikkiSingh\Dec_2022_All_Question_Paper"
ptrn = re.compile(r"\d+\w+")
if not os.path.exists(os.path.join(path,"Ctet-Dec-2022")):
    os.mkdir(os.path.join(path,"Ctet-Dec-2022"))
else:
    # below code will delete all the files from directory Ctet-Dec-2022 and at last it will delete the directory Ctet-Dec-2022
    for rm_path in os.scandir(os.path.join(path,"Ctet-Dec-2022")):
        os.remove(os.path.join(path,"Ctet-Dec-2022",rm_path.name))
    os.removedirs(os.path.join(path,"Ctet-Dec-2022"))
    os.mkdir(os.path.join(path,"Ctet-Dec-2022"))
for pth in os.scandir(path):
    if not pth.is_file() and not pth.name.endswith(".zip"):
        try:
            if ptrn.match(pth.name).group():
                for pathname in os.scandir(os.path.join(path,pth.name)):
                    os.chdir(os.path.join(path,pth.name))
                    if pathname.is_file():
                        # it will rename and remove the file from source directory
                        # os.rename(pathname.name,os.path.join(os.path.join(path,"Ctet-Dec-2022"),pth.name+"_"+pathname.name+".pdf"))
                        # this will copy to destination without removing the file from source
                        shutil.copy(pathname.name,os.path.join(os.path.join(path,"Ctet-Dec-2022"),pth.name+"_"+pathname.name))
        except:
            pass