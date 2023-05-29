from flask import Flask, render_template, jsonify
import requests
import random
import sqlite3

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/data')
def get_data():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://a5ba-14-139-82-6.ngrok-free.app/~/in-cse/in-name/Database/Junction-4/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    
    # conn = sqlite3.connect('lostAndFound.db')
    # db = conn.cursor()
    
    # for con in dataResponse["m2m:cnt"]["m2m:cin"]:
    #     db.execute("INSERT INTO junction1 (road1,road2,road3,road4,signal1,signal2,signal3,signal4) VALUES (?, ?, ?, ?, ?, ?, ?, ?);", (con["con"][0], con["con"][1], con["con"][2], con["con"][3], con["con"][4], con["con"][5], con["con"][6], con["con"][7]))
         
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["con"]
    
    return jsonify(data)

if __name__ == '__main__':
    app.run()
