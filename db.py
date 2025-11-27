import sqlite3
conn=sqlite3.connect("home.db")
conn.execute("CREATE TABLE Devices(id INTEGER PRIMARY KEY AUTOINCREMENT,status TEXT)")