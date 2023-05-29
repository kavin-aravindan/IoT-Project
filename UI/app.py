from flask import Flask, render_template, jsonify
import random

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/data1')
def get_data1():
    #
    time = str(random.randint(0, 100))
    value = random.randint(0, 100)
    data = {'time': time, 'value': value}
    return jsonify(data)

@app.route('/data2')
def get_data2():
    # Generate random data for the bar graph for the traffic light status
    data = [random.randint(0, 1) for x in range(4)]
    return jsonify(data)

@app.route('/data3')
def get_data3():
    # chart for displaying cars at a junction?
    data = [random.randint(0, 100) for x in range(4)]
    return jsonify(data)

if __name__ == '__main__':
    app.run()
