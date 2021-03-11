from datetime import datetime
import requests

############ VARS ############
index = 50000
outFile = 'out.txt'
uri = 'http://whatthecommit.com/index.txt'


######### FUNCTIONS #########
def colored(text, color):
    colorCodes = {'black': '30', 'red': '31', 'yellow': '33', 'green': '32', 'blue': '34', 'cyan': '36',
                  'magenta': '35', 'white': '37', 'gray': '90', 'reset': '0'}
    return '\033[' + colorCodes[str(color).lower()] + 'm' + str(text) + "\033[0m"


def DebugPrint(Catagory, Text, Color, end = "", start = ""):
    print(start + colored('['+datetime.now().strftime("%H:%M:%S")+'] ', 'yellow') +
          colored('['+Catagory+'] ', 'magenta')+colored(Text, Color), end=end)


def getMessages(index, uri):
    messages = []
    for i in range(index):
        x = requests.get(uri)
        working = x.text
        if working not in messages:
            messages.append(working)
        DebugPrint('Request', f"{i}/{index} ~~ {round(i / index * 100, 3)}%", 'cyan', end="\r")
    return messages


def saveMessages(file, messages):
    DebugPrint('Save', f"Saveing {len(messages)} Messages!", 'cyan', start="\n", end="\n")
    file = open(file, 'a')

    for i in messages:
        text = i.replace('\n', '')
        try:
            file.write(f"\"{text}\",\n")
        except:
            pass


def main():
    DebugPrint('Main', 'Starting...\n', 'green')
    messages = getMessages(index, uri)
    saveMessages(outFile, messages)
    DebugPrint('Main', 'Finished...', 'red')


if __name__ == '__main__':
    main()
