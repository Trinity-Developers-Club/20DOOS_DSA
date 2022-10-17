from tkinter import *
from tkinter import ttk
from tkinter import font

from .init_screen import InitScreen
from .auth_screen import AuthScreen

class AppGUI:
  def __init__(self,dbc):
    self.dbc = dbc
    self.root = Tk()
    self.root.resizable(False, False)
    header_frame = ttk.Frame(self.root)
    header_frame.grid(row=0,column=0)
    ttk.Label(header_frame, text=str.upper("Password Manager Beta"), font=font.Font(size=14)).grid(padx=20,pady=20,sticky="we")

  def go(self):
    if self.dbc.is_initialized():
      AuthScreen(self.root, self.dbc)
    else:
      InitScreen(self.root, self.dbc)
    self.root.mainloop()
