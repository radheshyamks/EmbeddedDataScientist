import os

def remove_directory_tree(start_directory: str):
    """Recursively and permanently removes the specified directory, all of its
    subdirectories, and every file contained in any of those folders."""
    for name in os.listdir(start_directory):
        path = os.path.join(start_directory, name)
        if os.path.isfile(path):
            print(f"Deleting the '{path}' file.")
            os.remove(path)
        else:
            remove_directory_tree(path)
    print(f"Deleting the empty '{start_directory}' directory.")
    os.rmdir(start_directory)


# Specify which directory (and its content) to remove
dir_path = r"C:\ToDos"

# Remove that directory and all files and folders it contains
print(f"Deleting the '{dir_path}' directory and its content:")
remove_directory_tree(dir_path)