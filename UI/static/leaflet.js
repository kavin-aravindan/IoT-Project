
var map = L.map('map').setView([latitude, longitude], zoomLevel);

// Load the GeoJSON data from an external file using AJAX
L.Util.ajax('path/to/your/geojson/file.geojson').then(function(data) {
  // Parse the GeoJSON data and add it to the map as a layer
  L.geoJSON(data).addTo(map);
});
