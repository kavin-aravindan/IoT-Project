var map = L.map('map').setView([-70, 0], 1);

// Add the tile layer to the map
// L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
//     attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/">OpenStreetMap</a> contributors',
//     maxZoom: 18
// }).addTo(map);

// Load the GeoJSON data from an external file using AJAX
L.Util.ajax('./iot_project.geojson').then(function(data) {
  // Parse the GeoJSON data and add it to the map as a layer
  L.geoJSON(data).addTo(map);
});
