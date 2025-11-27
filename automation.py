from flask import *
import sqlite3
app=Flask(__name__)

@app.route('/')
def index1():
    return render_template('index1.html')

@app.route('/light/<a>')
def add_status(a):
    conn=sqlite3.connect("home.db")
    cur=conn.execute("SELECT * FROM Devices WHERE id=1")
    row=cur.fetchone()
    if row == None:
        conn.execute("INSERT INTO Devices(status)VALUES(?)",(a,))
        conn.commit()
        return render_template('index1.html',msg="Light is "+a)
    else:
        conn.execute("UPDATE Devices SET status=? WHERE id=?",(a,1))
        conn.commit()
        return render_template('index1.html',msg="Light is "+a)
@app.route('/check_status')
def check_status():
    conn=sqlite3.connect('home.db')
    cur=conn.execute("SELECT * FROM Devices WHERE id=1")
    row=cur.fetchone()
    return (row[1])
if __name__=="__main__":
        app.run(port=600,host="0.0.0.0")