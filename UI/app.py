from flask import Flask, render_template, jsonify
import requests
import random
import sqlite3

app = Flask(__name__)

@app.route('/')
@app.route('/home')
def home():
    return render_template('home.html')

@app.route('/stats')
def stats():
    return render_template('stats.html')

@app.route('/junca')
def junca():
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-1/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["lt"]
    data = data.split("T")
    retStr = ''
    retStr += data[1][0:2]
    retStr += ":"
    retStr += data[1][2:4]
    retStr += ":"
    retStr += data[1][4:6]
    retStr += "  "
    retStr += data[0][6:8]
    retStr += "-"
    retStr += data[0][4:6]
    retStr += "-"
    retStr += data[0][0:4]
    print(data)
    return render_template('junca.html', timestamp = retStr)

@app.route('/juncb')
def juncb():
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-2/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["lt"]
    data = data.split("T")
    retStr = ''
    retStr += data[1][0:2]
    retStr += ":"
    retStr += data[1][2:4]
    retStr += ":"
    retStr += data[1][4:6]
    retStr += "  "
    retStr += data[0][6:8]
    retStr += "-"
    retStr += data[0][4:6]
    retStr += "-"
    retStr += data[0][0:4]
    print(data)
    return render_template('juncb.html', timestamp = retStr)

@app.route('/juncc')
def juncc():
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-3/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["lt"]
    data = data.split("T")
    retStr = ''
    retStr += data[1][0:2]
    retStr += ":"
    retStr += data[1][2:4]
    retStr += ":"
    retStr += data[1][4:6]
    retStr += "  "
    retStr += data[0][6:8]
    retStr += "-"
    retStr += data[0][4:6]
    retStr += "-"
    retStr += data[0][0:4]
    print(data)
    return render_template('juncc.html', timestamp = retStr)

@app.route('/juncd')
def juncd():
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-4/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["lt"]
    data = data.split("T")
    retStr = ''
    retStr += data[1][0:2]
    retStr += ":"
    retStr += data[1][2:4]
    retStr += ":"
    retStr += data[1][4:6]
    retStr += "  "
    retStr += data[0][6:8]
    retStr += "-"
    retStr += data[0][4:6]
    retStr += "-"
    retStr += data[0][0:4]
    print(data)
    return render_template('juncd.html', timestamp = retStr)

@app.route('/junce')
def junce():
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-5/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    response = requests.request("GET", url, headers=headers, data=payload)
    dataResponse = eval(response.text)
    data = dataResponse["m2m:cnt"]["m2m:cin"][-1]["lt"]
    data = data.split("T")
    retStr = ''
    retStr += data[1][0:2]
    retStr += ":"
    retStr += data[1][2:4]
    retStr += ":"
    retStr += data[1][4:6]
    retStr += "  "
    retStr += data[0][6:8]
    retStr += "-"
    retStr += data[0][4:6]
    retStr += "-"
    retStr += data[0][0:4]
    print(data)
    return render_template('junce.html', timestamp = retStr)

@app.route('/test')
def maps():
    return render_template('test.html')

@app.route('/dataA')
def get_dataA():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-1/Data?rcn=4"
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
    data = data[1:-1].split(", ")
    
    # print(data)
    
    return jsonify(data)

@app.route('/dataB')
def get_dataB():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-2/Data?rcn=4"
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
    data = data[1:-1].split(", ")
    print(data)
    return jsonify(data)

@app.route('/dataC')
def get_dataC():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-3/Data?rcn=4"
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
    data = data[1:-1].split(", ")
    return jsonify(data)

@app.route('/dataD')
def get_dataD():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-4/Data?rcn=4"
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
    data = data[1:-1].split(", ")
    return jsonify(data)

@app.route('/dataE')
def get_dataE():
    # Generate random data for the bar graph for the traffic light status
    
    url = "https://df20-2409-40f0-4e-5fc7-8c4a-2ee-946f-20c4.ngrok-free.app/~/in-cse/in-name/Database/Junction-5ur/Data?rcn=4"
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
    data = data[1:-1].split(", ")
    return jsonify(data)

if __name__ == '__main__':
    app.run()
