# -*- coding: utf-8 -*-
#Полозова лаб.1


import urllib, urlparse, re


start_url = "http://plast.me/plastic/13077-ktulhu.html"
content_img = urllib.urlopen(start_url).read()
urls_of_img = re.findall('img .*?src="(.*?)"', content_img)
abs_urls =[]
try:
    for url in urls_of_img:
        abs_urls.append(urlparse.urljoin(start_url, url))
    for url in abs_urls:
        name = url.rsplit('/',1)[1]
        urllib.urlretrieve(url, name)
except:
    print 'err'
