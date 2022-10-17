from tkinter import *
from tkinter import ttk
from tkinter import messagebox
from .auth_screen import AuthScreen

class InitScreen:
  def __init__(self, root, dbc):
    self.root = root
    self.dbc = dbc

    self.root.title("First time setup")
    self.frame = ttk.Frame(self.root, padding="10 10 10 10")
    self.frame.grid()

    self.password = StringVar()
    self.conf_pass = StringVar()

    labelText = "To start using the password manager, set a master password"
    ttk.Label(self.frame, text=labelText).grid(column=0,row=0, columnspan=2, padx=10, pady=10)

    ttk.Label(self.frame, text="Enter password").grid(column=0,row=1, padx=10, pady=10)
    ttk.Entry(self.frame, width=30, show="*", textvariable=self.password).grid(column=1, row=1, padx=10, pady=10)

    ttk.Label(self.frame, text="Confirm").grid(column=0,row=2, padx=10, pady=10)
    ttk.Entry(self.frame, width=30, show="*", textvariable=self.conf_pass).grid(column=1, row=2, padx=10, pady=10)

    ttk.Button(self.frame, text="Proceed", command=self.go).grid(column=1, row=3, padx=10, pady=10)

  def go(self):
    if self.password.get() != self.conf_pass.get():
      messagebox.showinfo(message="Passwords do not match, try again.")
      self.password.set("")
      self.conf_pass.set("")
    elif len(self.password.get()) < 4:
      messagebox.showinfo(message="Password is too short (< 4)")
    else:
      self.dbc.initialize(self.password.get())
      self.frame.destroy()
      AuthScreen(self.root, self.dbc)
