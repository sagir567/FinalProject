import requests
import json

# Made by SAGI,EDEN and AARON
# Replace your api key please
api_key = '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'

# API endpoint URL
api_url = 'https://api.openai.com/v1/engines/davinci/completions'

print("Welcome to our chat , we are Sagi ,Eden and Aaron\n")

print("Ask any question please :")
prompt = input()

# Set up the headers with your API key
headers = {
    'Authorization': f'Bearer {api_key}',
    'Content-Type': 'application/json',
}

data = {
    'prompt': prompt,
    'max_tokens': 50,  # Set the maximum length of the response
}

# Make the API request
response = requests.post(api_url, headers=headers, json=data)

# Check if the request was successful
if response.status_code == 200:
    result = json.loads(response.text)
    generated_text = result['choices'][0]['text']
    print(generated_text)
else:
    print(f"Error: {response.status_code} - {response.text}")
