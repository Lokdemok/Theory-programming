# -*- coding: utf-8 -*-
#Полозова ПС-22



import re, urllib, urllib2, urlparse, os


def findUrlWithText(url, text, num):
    if not (url in usedUrls) and text:
        usedUrls.add(url)
        content = urllib2.urlopen(url).read() #Просматриваем страницу

        # находим все ссылки
        DataUrls = re.findall('href="(.*?)"', content)

        # преобразуем в абсолютные ссылки
        convertDataUrls = [urlparse.urljoin(url, urlI) for urlI in DataUrls]

        # текст найдем - скачиваем
        if text in content:
            download(url, num)
        #Ищем ссылки дальше
        for urlList in convertDataUrls:
            nameFile = urlList.rsplit('/', 1)[-1]
            if '.htm' in nameFile or '.html' in nameFile:
                findUrlWithText(urlList, text, num)

def download(url, num):
    #страница, с которой работаем
    content = urllib.urlopen(url).read()
    print 'download  ', url
    #все адреса записываем
    img_urls = re.findall('img .*?src="(http:*.*?)"', content)
    js_urls = re.findall('script .*?src="(http:*.*?)"', content)
    css_urls = re.findall('href .*?src="(.*?css)"', content)
    other_css_urls = re.findall('href="(.*?css)"', content)
    fileUrls = img_urls + js_urls + css_urls + other_css_urls
    
    if fileUrls:
        numberUrl = 0
        for urls in fileUrls:
            if not 'http://' in urls:                
                urls = urlparse.urljoin(url, urls) # преобразуем в абсолютные 
            if 'http:' or 'https:' in urls:
                numberUrl += 1
                if '.' in urls[len(url)-5::]:   
                    extention = urls[urls.rfind('.')::]
                else:
                    extention = ''
        
            filename = 'file' + str(numberUrl) + extention
            content = content.replace(urls, filename)
            try:
                urllib.urlretrieve(urls, filename) #скачиваем
            except:
                print 'invalid mode'
    num += 1
    webPage1 = open(url[len(url) - 10:len(url) - 5] + 'WebPage.html', 'w')
    webPage1.write(content)
    webPage1.close()



url = 'http://kychka-pc.ru/'
text = 'пуля'
FileAdress = '/home/oblachnost/Рабочий стол/'
f1 = open('LogErrors', 'w')
usedUrls = set()
num = 0
findUrlWithText(url, text, num)
f1.close

