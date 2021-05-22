import requests
from bs4 import BeautifulSoup
import pandas as pd
from time import sleep
import numpy

#----------------------------Scap whole page
what_input = input("\n\t\tEnter job title, keywords or company :")
what_input.replace(" ", "+")        # replace space with + to match indeed's input format
where_input = input("\n\t\tEnter location : ")

URL="https://ca.indeed.com/jobs?q="+what_input+"+&l="+where_input+"&start="

title = [] 
company =[]
location = []
difficulty = []
date = []
remote = []
salary = []
rating = []

proxy = {           # use this website to check proxy "http://free-proxy.cz/en/proxylist/country/CA/https/ping/level1"
    "http":"http://142.44.136.219:32769",
    "https":"http://142.44.136.219:32769"
}   # use proxy to bypass block from indeed

for pg in range(0,3):
    URL_page = URL + str(pg*10)
    page = requests.get(URL_page,headers={'User-Agent': 'Mozilla/5.0'},proxies=proxy)

    soup = BeautifulSoup(page.text, 'html.parser')
    #soup = BeautifulSoup(page.content, 'html.parser')

    data = soup.find_all("div",{"data-tn-component":"organicJob"})
    #data = soup.find_all("div",{"class":"jobsearch-SerpJobCard"})
    #data = soup.select("div.jobsearch-SerpJobCard")
    
    for d in list(data):
        try:
            # title.append(d.find("h2",{"class":"title"}).get_text().replace('\n\n','').replace('\nnew',''))
            title.append(d.find("a",{"data-tn-element":"jobTitle"}).get_text().replace('\n',''))
        except:
            title.append(None)

        try:
            company.append(d.find("span",{"class":"company"}).get_text().replace('\n',''))
            # company.append(d.find("span",{"class":"company"}).get_text())
        except:
            company.append(None)

        try:
            location.append(d.find("span",{"class":"location"}).get_text())
        except:
            location.append(None)

        try:
            difficulty.append(d.find("span",{"class":"iaLabel iaIconActive"}).get_text())  
        except:
            difficulty.append(None)

        try:
            date.append(d.find("span",{"class":"date"}).get_text())  
        except:
            date.append(None)

        try:
            salary.append(d.find("span",{"class":"salaryText"}).get_text().replace('\n',''))  
            # salary.append(d.find("span",{"class":"salaryText"}).get_text())
        except:
            salary.append(None)

        try:
            remote.append(d.find("span",{"class":"remote"}).get_text())
        except:
            remote.append(None)
            
        try:
            rating.append(d.find("span",{"class":"ratingsDisplay"}).get_text().replace('\n',''))
            # rating.append(d.find("span",{"class":"ratingsDisplay"}).get_text())
        except:
            rating.append(None)

    delays = [3, 0.5, 1]
    delay = numpy.random.choice(delays)
    sleep(delay)
    

save_data = pd.DataFrame({
    "Title": title,
    "Company": company,
    "Location": location,
    "Salary": salary,
    "Date": date,
    "Rating": rating,
    "Difficulty": difficulty,
    "Remote": remote
})

save_data.fillna("---", inplace = True)         # replace empty cell to ---
# (from pandas import ExcelWriter)
# create excel writer object
#writer = ExcelWriter('./Data/Indeed_Data.xlsx')    # pylint: disable=abstract-class-instantiated
# write dataframe to excel
#save_data.to_excel(writer,"henry",index = False, header=True)
# save the excel
#writer.save()

#save data to csv file
save_data.to_csv('./Data/indeed_data_original.csv', index = False, header=True)  
save_data.to_csv('./Data/indeed_data_modified.csv', index = False, header=True, sep='|')         #replace '|' as delimter (instead of ',')



#----------------------------------------------------------#
'''     # Testing 
has_salary=[]
for s in save_data["Salary"]:
    try:
        if len(s) == 0:
            has_salary.append(False)
        else:
            has_salary.append(True)
    except:
        has_salary.append(False)
n = 0    
save_salary = []
for s in has_salary:
    if s:
        # print(save_data.iloc[n])        #loc, iloc, ix
        save_salary.append(save_data.iloc[n])        # table format
    n+=1

for s in save_salary:
    print(s)
    print("\n")
'''