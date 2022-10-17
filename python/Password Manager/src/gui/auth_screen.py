from tkinter import *
from tkinter import ttk
from tkinter import messagebox
from tkinter import font
from .main_screen import MainScreen

class AuthScreen:
  def __init__(self, root, dbc):
    self.root = root
    self.dbc = dbc

    self.root.title("Authenticate")
    self.frame = ttk.Frame(self.root)
    self.frame.grid(row=1, column=0, sticky="nswe")

    self.password = StringVar()

    labelText = "Authenticate to access the password manager"
    ttk.Label(self.frame, text=labelText).grid(column=0,row=0,columnspan=2,padx=10,pady=10,sticky="we")

    ttk.Label(self.frame, text="Master password").grid(column=0,row=1,padx=10,pady=10)
    ttk.Entry(self.frame, width=30, show="*", textvariable=self.password).grid(column=1, row=1,padx=10,pady=10,sticky="e")

    ttk.Button(self.frame, text="Proceed", command=self.go).grid(column=1, row=2, padx=10,pady=20)

  def go(self):
    if self.dbc.is_correct_password(self.password.get()):
      self.frame.destroy()
      main_screen = MainScreen(self.root, self.dbc)
      main_screen.reload()
    else:
      messagebox.showinfo(message="Incorrect Password")
      self.password.set("")

