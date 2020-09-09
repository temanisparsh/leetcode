import os
import json
import time

from selenium import webdriver
from selenium.webdriver.common.keys import Keys

problem_files = os.listdir('./problems')
problem_files = set([i.split('.')[0] for i in problem_files])

solution_paths = ['./solutions/easy', './solutions/medium', './solutions/hard']
solution_files = []
solution_dict = {}

for i in solution_paths:

    path_files = os.listdir(i)

    for j in path_files:
        solution_dict[j.split('.')[0]] = i + '/' + j

    path_files = [j.split('.')[0] for j in path_files]
    solution_files.extend(path_files)

solution_files = set(solution_files)

diff_files = list(solution_files.difference(problem_files))
print(diff_files)

with open('links.json', 'r') as json_file:
    links = json.loads(json_file.read())

driver = webdriver.Chrome()
driver.get('https://leetcode.com/problemset/algorithms/')

for problem_number in diff_files:

    problem = links[problem_number]
    link = problem['link']

    driver.get(link)
    
    while True:
        try:
            statement_ele = driver.find_element_by_xpath('//*[@id="app"]/div/div[2]/div/div/div[1]/div/div[1]/div[1]/div/div[2]/div/div[2]')
            statement = statement_ele.get_attribute("innerHTML")            
            break
        except:
            time.sleep(1)
            continue

    problem['statement'] = statement
    problem['language'] = solution_dict[problem_number].split('.')[-1]

    with open(solution_dict[problem_number], 'r') as file:
        problem['solution'] = file.read()

    with open('./problems/'+problem_number+'.json', 'w') as json_file:
        json.dump(problem, json_file)