from tkinter import *
from tkinter import messagebox
import os

file_str = "Datei"
quit_str = "Exit"
edit_str = "Edit"
help_str = "Help"

def com1():
    print("hello")

def _exit():
    
    if messagebox.askquestion("Exit", "Are you sure?", icon='warning') == 'yes':
        os._exit(0)
    else:
        print("Cancled")

        

if __name__ == "__main__":

    root = Tk()
    root.geometry("200x200")

    menubar = Menu(root)
    
    filemenu = Menu(menubar, tearoff=0)
    filemenu.add_command(label="hello", command=com1)
    filemenu.add_separator()
    filemenu.add_command(label=quit_str, command=_exit, underline=1)#, accelerator="Alt+X")

    editmenu = Menu(menubar, tearoff=0)
    
    helpmenu = Menu(menubar, tearoff=0)
    
    menubar.add_cascade(label=file_str, menu=filemenu, underline=0)
    menubar.add_cascade(label=edit_str, menu=editmenu)
    menubar.add_cascade(label=help_str, menu=helpmenu)
    root.config(menu=menubar)

    
    b1 = Button(root, text="Left", command=com1)
    b1.pack(side='left')
 #   b1.grid(row=2, column=1)





    root.mainloop()
