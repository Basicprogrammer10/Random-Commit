import requests

messages = []
index = 1000

for i in range(index):
    x = requests.get('http://whatthecommit.com/index.txt')
    working = x.text
    if working not in messages:
        messages.append(working)
        print(f" [*] {i}/{index} ~~ {round(i/index*100, 2)}%", end="\r")

print(f" [*] Saveing {len(messages)} Messages!")
file = open('out.txt', 'a')

for i in messages:
    text = i.replace('\n', '')
    try:
        file.write(f"\"{text}\",\n")
    except:
        pass

print("Done!")