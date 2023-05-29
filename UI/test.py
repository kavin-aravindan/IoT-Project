import requests


#code to get data from thingspeak
request = requests.get("https://api.thingspeak.com/channels/2160241/fields/1.json?api_key=A96Z3U63JEAJJ4UY&results=100")
print(type(request.json))
#print(request.text)
print(request.json()['feeds'])

#code to get data from OM2M
url = "http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Node-1/Data?rcn=4"

payload={}
headers = {
  'X-M2M-Origin': 'admin:admin',
  'Accept': 'application/json'
}

response = requests.request("GET", url, headers=headers, data=payload)