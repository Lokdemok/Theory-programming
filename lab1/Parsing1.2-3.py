# -*- coding: utf-8 -*-
#Полозова ПС-22



import re, urllib, urllib2, urlparse, os


def find_url_with_search_text(url, text, num):
    if not (url in used_urls) and text:
        used_urls.add(url)
        content = urllib2.urlopen(url).read() #Просматриваем страницу

        # находим все ссылки
        data_urls = re.findall('href="(.*?)"', content)

        # преобразуем в абсолютные ссылки
        convert_data_urls = [urlparse.urljoin(url, urlI) for urlI in data_urls]

        # текст найдем - скачиваем
        if text in content:
            download(url, num)
        #Ищем ссылки дальше
        for url_list in convert_data_urls:
            file_name = url_list.rsplit('/', 1)[-1]
            if '.htm' in file_name or '.html' in file_name:
                find_url_with_search_text(url_list, text, num)

def download(url, num):
    #страница, с которой работаем
    content = urllib.urlopen(url).read()
    print 'download  ', url
    #все адреса записываем
    img_urls = re.findall('img .*?src="(http:*.*?)"', content)
    js_urls = re.findall('script .*?src="(http:*.*?)"', content)
    css_urls = re.findall('href .*?src="(.*?css)"', content)
    other_css_urls = re.findall('href="(.*?css)"', content)
    file_urls = img_urls + js_urls + css_urls + other_css_urls
    
    if file_urls:
        number_of_url = 0
        for urls in file_urls:
            if not 'http://' in urls:                
                urls = urlparse.urljoin(url, urls) # преобразуем в абсолютные 
            if 'http:' or 'https:' in urls:
                number_of_url += 1
                if '.' in urls[len(url)-5::]:   
                    extention = urls[urls.rfind('.')::]
                else:
                    extention = ''
        
            filename = 'file' + str(number_of_url) + extention
            content = content.replace(urls, filename)
            try:
                urllib.urlretrieve(urls, filename) #скачиваем
            except:
                print 'invalid mode'
    num += 1
    web_page = open(url[len(url) - 10:len(url) - 5] + 'WebPage.html', 'w')
    web_page.write(content)
    web_page.close()



url_for_search = 'http://kychka-pc.ru/'
searching_text = 'пуля'
file_adress = '/home/oblachnost/Рабочий стол/'
log_errors = open('LogErrors.txt', 'w')
used_urls = set()
num = 0
find_url_with_search_text(url_for_search, searching_text, num)
log_errors.close

