var ctx1 = document.getElementById('chart1').getContext('2d');
var chart1 = new Chart(ctx1, {
    type: 'line',
    data: {
        labels: [],
        datasets: [{
            label: 'Data 1',
            data: [],
            borderColor: 'rgba(75, 192, 192, 1)',
            backgroundColor: 'rgba(75, 192, 192, 0.2)',
            borderWidth: 1,
            fill: 'origin',
        }]
    },
    options: {
        scales: {
            x: {
                display: true,
                title: {
                    display: true,
                    text: 'Time'
                }
            },
            y: {
                display: true,
                title: {
                    display: true,
                    text: 'Value'
                }
            }
        }
    }
});

function updateChart(chart, data) {
    chart.data.labels.push(data.time); 
    chart.data.datasets[0].data.push(data.value);
    chart.update();
}

function fetchData(chart, endpoint) {
    fetch(endpoint)
        .then(response => response.json())
        .then(data => {
            updateChart(chart, data);
            setTimeout(() => fetchData(chart, endpoint), 1000);
        });
}

var ctx2 = document.getElementById('chart2').getContext('2d');
var chart2 = new Chart(ctx2, {
    type: 'bar',
    data: {
        labels: ['Bar 1', 'Bar 2', 'Bar 3', 'Bar 4'], // Set the labels for the bars
        datasets: [{
            label: 'Data 2',
            data: [0, 0, 0, 0], // Initial values for the bar heights
            backgroundColor: 'rgba(192, 75, 192, 0.5)',
            borderWidth: 1,
            borderColor: 'rgba(192, 75, 192, 1)',
        }]
    },
    options: {
        scales: {
            x: {
                display: true,
                title: {
                    display: true,
                    text: 'Time'
                }
            },
            y: {
                display: true,
                title: {
                    display: true,
                    text: 'Value'
                },
                suggestedMin: 0, // Set the minimum value for the y-axis
                suggestedMax: 1 // Set the maximum value for the y-axis
            }
        }
    }
});

function updateBar(chart, data) {
    chart.data.datasets[0].data = data; // Update the bar heights with new data
    chart.update();
}

function fetchBar(chart, endpoint) {
    fetch(endpoint)
        .then(response => response.json())
        .then(data => {
            updateBar(chart, data);
            setTimeout(() => fetchBar(chart, endpoint), 1000);
        });
}


var ctx3 = document.getElementById('chart3').getContext('2d');
var chart3 = new Chart(ctx3, {
    type: 'pie',
    data: {
        labels: ['Road 1', 'Road 2', 'Road 3', 'Road 4'], // Set the labels for the sections
        datasets: [{
            label: 'Number of cars',
            data: [0, 0, 0, 0], // Initial values for the sections
            backgroundColor: [
                'rgba(255, 99, 132, 0.5)',
                'rgba(54, 162, 235, 0.5)',
                'rgba(255, 206, 86, 0.5)',
                'rgba(75, 192, 192, 0.5)'
            ],
            borderColor: [
                'rgba(255, 99, 132, 1)',
                'rgba(54, 162, 235, 1)',
                'rgba(255, 206, 86, 1)',
                'rgba(75, 192, 192, 1)'
            ],
            borderWidth: 1
        }]
    },
    options: {
        responsive: true
    }
});

function updatePie(chart, data) {
    chart.data.datasets[0].data = data;
    chart.update();
}

function fetchPie(chart, endpoint) {
    fetch(endpoint)
        .then(response => response.json())
        .then(data => {
            updatePie(chart, data);
            setTimeout(() => fetchPie(chart, endpoint), 1000);
        });
}

fetchData(chart1, '/data1');
fetchBar(chart2, '/data2');
fetchPie(chart3, '/data3');
