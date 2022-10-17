from tkinter import *
from tkinter import ttk
import random
# ========================================
class Minesweeper:
	def __init__ (self, num_row, num_col, num_mines):
		assert(num_row > 0 and num_col > 0)
		assert(num_mines <= num_row * num_col)

		self.num_row = num_row
		self.num_col = num_col
		self.num_mines = num_mines
		self.grid = [[0 for i in range(num_col)] for j in range(num_row)]
		
		# status: 0 if covered, 1 if uncovered, 2 if flagged
		self.status = [[0 for i in range(num_col)] for j in range(num_row)]
		
		# generate mine positions
		pos = [[i, j] for i in range(num_row) for j in range(num_col)]
		self.mines = random.sample(pos, num_mines)
		for [x, y] in self.mines:
			self.grid[x][y] = 1
		self.u_empty = 0
		self.f_mines = 0

		# Pseudo GUI
		self.gui_grid = [['_' for i in range(num_col)] for j in range(num_row)]
	
	def uncover (self, row, col):
		c1 = (row >= 0 and row < self.num_row)
		c2 = (col >= 0 and col < self.num_col)
		c3 = (self.status[row][col] == 0)
		if not (c1 and c2 and c3): return -2 # Do nothing
						   
		self.status[row][col] = 1

		if self.grid[row][col] == 1: # Loses the game
			self.gui_grid[row][col] = 'x'
			return -1

		self.u_empty = self.u_empty + 1 # Uncovered empty cell
		
		cnt = 0
		for dr, dc in zip([0, 0, 1, -1, 1, 1, -1, -1], [1, -1, 0, 0, -1, 1, -1, 1]):
			r, c = row + dr, col + dc
			if r < 0 or r >= self.num_row: continue
			if c < 0 or c >= self.num_col: continue
			if self.grid[r][c] == 1: cnt = cnt + 1
		self.gui_grid[row][col] = str(cnt)
		return cnt

	def flag (self, row, col):
		c1 = (row >= 0 and row < self.num_row)
		c2 = (col >= 0 and col < self.num_col)
		c3 = (self.status[row][col] == 0)
		if not (c1 and c2 and c3): return False
		self.status[row][col] = 2
		self.gui_grid[row][col] = 'F'
		if self.grid[row][col] == 1: self.f_mines = self.f_mines + 1 # True flag
		return True

	def unflag (self, row, col):
		c1 = (row >= 0 and row < self.num_row)
		c2 = (col >= 0 and col < self.num_col)
		c3 = (self.status[row][col] == 2)
		if not (c1 and c2 and c3): return False
		self.status[row][col] = 0
		self.gui_grid[row][col] = '_'
		if self.grid[row][col] == 1: self.f_mines = self.f_mines - 1 # Removed a true flag
		return True

	def is_flagged (self, row, col):
		return self.status[row][col] == 2

	def has_won (self):
		p = self.u_empty + self.f_mines == self.num_row * self.num_col
		q = self.f_mines == self.num_mines
		return (p and q)

	def show_cheat(self):
		print("cheat")
		for i in range(self.num_row):
			for j in range(self.num_col):
				print("[" + str(self.grid[i][j]) + "]", end="")
			print()

	def show(self):
		for i in range(self.num_row):
			for j in range(self.num_col):
				print("[" + self.gui_grid[i][j] + "]", end="")
			print()
# ========================================
def toggle_mode():
	global toggle_button, flag_mode
	flag_mode = not flag_mode
	if flag_mode:
		toggle_button["text"] = "Flag Mode (click to toggle)"
	else:
		toggle_button["text"] = "Uncover Mode (click to toggle)"

def disable(r, c):
	 cells[r][c]["command"] = no_op 

def disable_all():
	for i in range(num_row):
		for j in range(num_col):
			disable(i, j)

def no_op():
	pass
# ========================================
def process (r, c):
	if flag_mode:
		if ms.is_flagged(r, c):
			if ms.unflag(r, c):
				# print("Unflagged")
				cells[r][c]["image"] = img_covered
		else:
			if ms.flag(r, c):
				# print("Flagged")
				cells[r][c]["image"] = img_flag 
	else:
		cnt = ms.uncover(r, c)
		# print("cnt", cnt)
		disable(r, c)
	
		# Uncover all 0-cells together
		if cnt == 0:
			for dr, dc in zip([0, 0, 1, -1, 1, 1, -1, -1], [1, -1, 0, 0, -1, 1, -1, 1]):
				r1, c1 = r + dr, c + dc
				if r1 < 0 or r1 >= num_row: continue
				if c1 < 0 or c1 >= num_col: continue
				process(r1, c1)	
			
		if cnt == -2: return
		if cnt == -1:
			cells[r][c]["image"] = img_mine 
			status_label["text"] = "YOU LOSE!"
			disable_all()
			return
		cells[r][c]["image"] = img_num[cnt] 
	if ms.has_won():
		status_label["text"] = "YOU WIN!"
		disable_all()
# ========================================
def init():
	global root, cells, ms, flag_mode, toggle_button, status_label

	# New Minesweeper game with specified parameters
	ms = Minesweeper(num_row, num_col, num_mines)
	# ms.show_cheat()
	cells = []
	flag_mode = False
	
	# Add main frame and status bar
	mainframe = ttk.Frame(root, padding="0 0 0 0")
	mainframe.grid(column=0, row=0, sticky="nsew")
	suppframe = ttk.Frame(root, padding="5 5 5 5")
	suppframe.grid(column=0, row=1, sticky="nsew")
	
	# Add buttons
	for i in range(num_row):
		cells.append([])
		for j in range(num_col):
			cells[i].append(ttk.Button(mainframe, image = img_covered))

	for i in range(num_row):
		for j in range(num_col):
			cells[i][j].grid(row = i, column = j)
			cells[i][j]["command"] = lambda r = i, c = j : process(r, c)

	# Status Bar
	toggle_button = ttk.Button(suppframe, text = "Uncover Mode (click to toggle)", command = toggle_mode)
	toggle_button.grid(row = 0, column = 0)
	reset_button = ttk.Button(suppframe, text = "Restart", command = init)
	reset_button.grid(row = 0, column = 1)
	status_label = ttk.Label(suppframe, text = "")
	status_label.grid(row = 0, column = 2)
	
	# Remove padding
	for child in mainframe.winfo_children(): child.grid_configure(padx=0, pady=0)
# ========================================
# Customize size, mines
num_row, num_col, num_mines = 15, 25, 25 

root = Tk()
root.title("Minesweeper")
root.resizable(False, False)

# Resources
img_uncovered = PhotoImage(file = "./resources/uncovered.png")
img_covered = PhotoImage(file = "./resources/covered.png")
img_mine = PhotoImage(file = "./resources/mine.png")
img_flag = PhotoImage(file = "./resources/flag.png")
img_num = [PhotoImage(file = "./resources/num-" + str(i) + ".png") for i in range(9)]

# Start now
init()
root.mainloop()
# ========================================
