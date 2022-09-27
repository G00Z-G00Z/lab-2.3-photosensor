import sys

def exit_error():
    sys.exit(1)

def file_exists(filename : str):
    try:
        with open(filename, "r") as f:
            pass
        return True
    
    except FileNotFoundError: 
        return False

if __name__ == "__main__":    
    pass

