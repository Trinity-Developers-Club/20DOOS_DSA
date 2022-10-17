from db_connector import DBConnector
from gui.app_gui import AppGUI

dbc = DBConnector()
app = AppGUI(dbc)
app.go()
