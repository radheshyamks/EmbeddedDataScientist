import os
import sys
from colorama import Fore,Style,init
from pathlib import Path

def remove_directory_tree(start_directory: Path):
    for path in start_directory.iterdir():
        # print(path)
        if path.is_file():
            # print(f"Removing the file '{path}'.")
            path.unlink()
        else:
            remove_directory_tree(path)
    # print(f"Removing the empty directory '{start_directory}'.")
    start_directory.rmdir()


# Define which directory and its content to remove
dir_path = Path(r'E:\NotepadPlusPlus\Python\Env')

# Remove all files and folders that are inside the specified directory
# print(f"Removing the '{dir_path}' directory and its content:")
remove_directory_tree(dir_path)