import time
import json

from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome()
driver.get('https://leetcode.com/problemset/algorithms/')

input("Change filter to show all problems: ")

links = {}

count = 1

while True:
    try:
        
        link_ele = driver.find_element_by_xpath('//*[@id="question-app"]/div/div[2]/div[2]/div[2]/table/tbody[1]/tr['+str(count)+']/td[3]/div/a')
        link = link_ele.get_attribute('href')
        name = link_ele.get_attribute('innerHTML')

        difficulty_ele = driver.find_element_by_xpath('//*[@id="question-app"]/div/div[2]/div[2]/div[2]/table/tbody[1]/tr['+str(count)+']/td[6]/span')
        difficulty = difficulty_ele.get_attribute('innerHTML')
        
        number_ele = driver.find_element_by_xpath('//*[@id="question-app"]/div/div[2]/div[2]/div[2]/table/tbody[1]/tr['+str(count)+']/td[2]')
        number = number_ele.get_attribute('innerHTML')

        links[number] = {
            'link': link,
            'name': name,
            'difficulty': difficulty
        }
        
        count += 1
        if count % 50 == 0:
            print(count)

    except:
        break

with open('links.json', 'w') as json_file:
        json.dump(links, json_file)