import os
import json

problem_dict = {}
problem_files = os.listdir('./problems')

for file in problem_files:

    filename = file.split('.')[0]

    with open('./problems/'+file, 'r') as json_file:
        problem_dict[filename] = json.loads(json_file.read())
        problem_dict[filename]['number'] = filename

with open('./src/solutions.json', 'w') as json_file:
        json.dump(problem_dict, json_file)