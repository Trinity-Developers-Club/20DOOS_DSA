from tkinter import *
from tkinter import ttk
from tkinter import messagebox
from tkinter import font

class ScrollableFrame(ttk.Frame):
  def __init__(self, container, *args, **kwargs):
    super().__init__(container, *args, **kwargs)
    canvas = Canvas(self)
    scrollbar = ttk.Scrollbar(self, orient="vertical", command=canvas.yview)
    hscrollbar = ttk.Scrollbar(self, orient="horizontal", command=canvas.xview)
    self.scrollable_frame = ttk.Frame(canvas)
    self.scrollable_frame.bind(
      "<Configure>",
      lambda e: canvas.configure(
        scrollregion=canvas.bbox("all")
      )
    )
    canvas.create_window((0, 0), window=self.scrollable_frame, anchor="nw")
    canvas.configure(yscrollcommand=scrollbar.set)
    canvas.configure(xscrollcommand=hscrollbar.set)
    canvas.grid(column=0, row=0, sticky="we")
    scrollbar.grid(column=1, row=0, sticky="ns")
    hscrollbar.grid(column=0, row=1, sticky="we")

class MainScreen:
  def __init__(self, root, dbc):
    self.root = root
    self.dbc = dbc

    self.root.title("Password Manager")
    self.frame = ttk.Frame(self.root)
    self.frame.grid(column=0, row=1, sticky="nsew", padx=10, pady=10)

    ttk.Separator(self.frame, orient="horizontal").grid(column=0, row=0, columnspan=2, sticky="nsew")
    ttk.Label(self.frame, text="Your stored passwords:").grid(column=0,row=1, sticky="w")
    
    self.table = ScrollableFrame(self.frame)
    self.table.grid(column=0, row=2, columnspan=2, sticky="nsew")
    
    ttk.Separator(self.frame, orient="horizontal").grid(column=0, row=3, columnspan=2, sticky="nsew")

    self.input_name = StringVar()
    self.input_userid = StringVar()
    self.input_password = StringVar()

    ttk.Label(self.frame, text="Add an entry:").grid(column=0, row=4, columnspan=2, sticky="we", padx=5, pady=5)

    ttk.Label(self.frame, text="Name:").grid(column=0, row=5, sticky="we", padx=5, pady=5)
    ttk.Entry(self.frame, width=30, textvariable=self.input_name).grid(column=1, row=5, sticky="e", padx=5, pady=5)

    ttk.Label(self.frame, text="Userid:").grid(column=0, row=6, sticky="w", padx=5, pady=5)
    ttk.Entry(self.frame, width=30, textvariable=self.input_userid).grid(column=1, row=6, sticky="e", padx=5, pady=5)

    ttk.Label(self.frame, text="Password:").grid(column=0, row=7, sticky="w", padx=5, pady=5)
    ttk.Entry(self.frame, width=30, textvariable=self.input_password).grid(column=1, row=7, sticky="e", padx=5, pady=5)

    ttk.Button(self.frame, text="Add", command=self.add_entry).grid(column=1, row=8, sticky="e", padx=5, pady=5)

    ttk.Separator(self.frame, orient="horizontal").grid(column=0, row=9, columnspan=2, sticky="nsew")
    ttk.Button(self.frame, text="Change master password", command=self.change_mpass).grid(column=1, row=10, sticky="e", padx=5, pady=5)

  def reload(self):
    for child in self.table.scrollable_frame.winfo_children():
      child.destroy()
    ttk.Label(self.table.scrollable_frame, font=font.Font(weight="bold"), text="Name").grid(column=0, row=0, padx=5, pady=5)
    ttk.Label(self.table.scrollable_frame, font=font.Font(weight="bold"), text="Email/Username").grid(column=1, row=0, padx=5, pady=5)
    ttk.Label(self.table.scrollable_frame, font=font.Font(weight="bold"), text="Password").grid(column=2, row=0, padx=5, pady=5)
    ttk.Label(self.table.scrollable_frame, font=font.Font(weight="bold"), text="Action").grid(column=3, row=0, sticky="e", padx=5, pady=5)

    cnt = 1
    entries = self.dbc.get_entries()
    for e in entries:
      ttk.Label(self.table.scrollable_frame, text=e[1]).grid(column=0, row=cnt, padx=5, pady=5)
      ttk.Label(self.table.scrollable_frame, text=e[2]).grid(column=1, row=cnt, padx=5, pady=5)
      ttk.Label(self.table.scrollable_frame, text=e[3]).grid(column=2, row=cnt, padx=5, pady=5)
      ttk.Button(self.table.scrollable_frame, text="Delete",command=lambda x=e[0]:self.delete_entry(x)).grid(column=3, row=cnt, padx=5, pady=5)
      cnt += 1
        
  def delete_entry(self, entry_id):
    ok = messagebox.askyesno("Confirm deletion", "Delete entry?")
    if not ok: return
    self.dbc.remove_entry(entry_id)
    self.reload()

  def add_entry(self):
    if self.input_name.get() == "" or self.input_userid.get() == "" or self.input_password.get() == "":
      messagebox.showinfo(message="One or more fields are empty, try again")
      return
    ok = messagebox.askyesno("Confirm adding entry", "Add entry (%s, %s, %s)?" % (self.input_name.get(), self.input_userid.get(), self.input_password.get()))
    if not ok: return
    self.dbc.add_entry(self.input_name.get(), self.input_userid.get(), self.input_password.get())
    self.reload()
    self.input_name.set("")
    self.input_userid.set("")
    self.input_password.set("")

  def change_mpass(self):
    PassChangeDialog(self.root, self.dbc)

class PassChangeDialog:
  def __init__(self, root, dbc):
    self.root = root
    self.frame = Toplevel(root)
    self.frame.resizable(False, False)
    self.dbc = dbc

    self.old_pass, self.new_pass, self.con_pass = StringVar(), StringVar(), StringVar()

    ttk.Label(self.frame, text="Change master password").grid(column=0, row=0, columnspan=2, padx=5, pady=5)
    ttk.Label(self.frame, text="Old password").grid(column=0, row=1, padx=5, pady=5)
    ttk.Label(self.frame, text="New password").grid(column=0, row=2, padx=5, pady=5)
    ttk.Label(self.frame, text="Confirm password").grid(column=0, row=3, padx=5, pady=5)

    ttk.Entry(self.frame, width=30, show="*", textvariable=self.old_pass).grid(column=1, row=1, padx=5, pady=5, sticky="e")
    ttk.Entry(self.frame, width=30, show="*", textvariable=self.new_pass).grid(column=1, row=2, padx=5, pady=5, sticky="e")
    ttk.Entry(self.frame, width=30, show="*", textvariable=self.con_pass).grid(column=1, row=3, padx=5, pady=5, sticky="e")
    
    ttk.Button(self.frame, text="Proceed", command=self.go).grid(column=1, row=4, padx=5, pady=5, sticky="e")
    
    self.frame.protocol("WM_DELETE_WINDOW", self.dismiss)
    self.frame.transient(root)
    self.frame.wait_visibility()
    self.frame.grab_set()
    self.frame.wait_window()

  def go(self):
    if self.new_pass.get() != self.con_pass.get():
      messagebox.showinfo(message="Passwords do not match, try again")
      return
    if len(self.new_pass.get()) < 4:
      messagebox.showinfo(message="Password is too short (< 4)")
      return
    if not self.dbc.is_correct_password(self.old_pass.get()): 
      messagebox.showinfo(message="Incorrect old password")
      return
    if self.old_pass.get() == self.new_pass.get():
      messagebox.showinfo(message="New password is same as old password, choose a new one")
      return
    self.dbc.initialize(self.new_pass.get())
    messagebox.showinfo(message="Successfully changed master password")
    self.dismiss()

  def dismiss(self):
    self.frame.grab_release()
    self.frame.destroy()
