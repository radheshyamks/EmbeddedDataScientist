import os

def remove_directory_tree(start_directory: str):
    for name in os.listdir(start_directory):
        path = os.path.join(start_directory, name)
        if os.path.isfile(path):
            os.remove(path)
        else:
            remove_directory_tree(path)
    os.rmdir(start_directory)