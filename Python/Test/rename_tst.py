# E:\NotepadPlusPlus\Python\Test\test_script.tst

import re;
import os;
from colorama import Fore,Style,init
init(convert=True)
org_file_path = r"E:\NotepadPlusPlus\Python\Test\test_script.tst"
# print(org_file_path)
file_path,file_name = os.path.split(org_file_path)
# print(file_path)
# print(file_name)
# pattrn = re.compile(r"(-- Test Case:|TEST.NAME:)")
pattrn = re.compile('(-- Test Case:|TEST.NAME:)\s*\w+\.\d+')
# pattrn = re.compile(r'^(-- Test Case:|TEST.NAME:)\d+')
def repace_str():
    pass 
with open(org_file_path,'r') as fd:
    for line in fd.readlines():
        if pattrn.match(line.strip("\n")):
            # print(pattrn.match(line.strip("\n")).group())
            pattrn.sub(repace_str,line.strip("\n").group())